#include "Rsp_#1.1.h"
#include "rsp.h"

#include "su/su.h"
#include "vu/vu.h"
#include "matrix.h"

void run_task(void)
{
#ifdef WAIT_FOR_CPU_HOST
    register int i;

    if (CFG_WAIT_FOR_CPU_HOST != 0)
        for (i = 0; i < 32; i++)
            MFC0_count[i] = 0;
#endif

    while (!(*RSP.SP_STATUS_REG & 0x00000001))
    { /* Explicitly speaking, it must == 0x0, though the object is NOT(HALT). */
        inst.W = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
#ifdef SP_EXECUTE_LOG
        step_SP_commands(inst.W);
#endif
EX:
     /* if ((inst & 0xFE000000) == 0x4A000000) */
        if (inst.W >> 25 == 0x25) /* is a VU instruction */
        {
            const int vd = inst.R.sa;
            const int vs = inst.R.rd;
            const int vt = inst.R.rt;
            const int e  = inst.R.rs & 0xF;
#ifdef PARALLELIZE_VECTOR_TRANSFERS
            SHUFFLE_VECTOR(vt, e); /* *(__int128 *)VC = shuffle(VT, mask(e)); */
#endif
#ifdef EMULATE_VECTOR_RESULT_BUFFER
            memcpy(Result, VR[vd], 16);
#endif
            SP_COP2_C2[inst.R.func](vd, vs, vt, e);
#ifdef EMULATE_VECTOR_RESULT_BUFFER
            memcpy(VR[vd], Result, 16);
#endif
        }
        else
        {
            if (SR[0] != 0x00000000)
                message("$0", 0); /* tried to overwrite MIPS GPR $zero */
            SR[0] = 0x00000000;
            EX_SCALAR[inst.J.op][(inst.W >> sub_op_table[inst.J.op]) & 077]();
        }
        if (stage == 2) /* branch phase of scheduler */
        {
            *RSP.SP_PC_REG = temp_PC & 0xFFC;
            stage = 0;
            continue;
        }
        *RSP.SP_PC_REG += 0x004;
        *RSP.SP_PC_REG &= 0x00000FFC;
        stage <<= 1; /* stage <-- 1<<1:  next IW in branch delay slot */
        continue;
    }
    if (*RSP.SP_STATUS_REG & 0x00000002) /* normal exit, from executing BREAK */
        return;
    else if (*RSP.MI_INTR_REG & 0x00000001) /* interrupt set by MTC0 to break */
        RSP.CheckInterrupts();
    else if (CFG_WAIT_FOR_CPU_HOST != 0) /* plugin system hack to re-sync */
        {}
    else if (*RSP.SP_SEMAPHORE_REG != 0x00000000) /* semaphore lock fixes */
        {}
    else /* ??? unknown, possibly external intervention from CPU memory map */
    {
        message("SP_SET_HALT", 3);
        return;
    }
    *RSP.SP_STATUS_REG &= ~0x00000001; /* CPU restarts with the correct SIGs. */
    return;
}

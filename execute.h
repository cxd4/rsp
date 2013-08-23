#include "Rsp_#1.1.h"
#include "rsp.h"

#include "su/su.h"
#include "vu/vu.h"

/*
 * Treat the RSP CPU as a permanent loop til MTC0/BREAK set SP_STATUS_HALT.
 *
 * Any N64 game will end the SP task by executing BREAK directly, not asking
 * MTC0 to set the HALT bit without executing a BREAK.  Thus, we could get a
 * very small (tested ~1-1.5 VI/s) speed boost by making the `while` RSP loop
 * an unconditional, permanent loop escapable only once BREAK gets executed,
 * but this detriments from strict accuracy because MTC0/SSTEP could set it.
 *
 * The bulk of speed-up to the loop has already come from having no code
 * after the execute phase.  Immediately after any RSP operation in the body,
 * the loop jumps to the beginning via the standard `continue;` statement, in
 * the absence of any trailing code outside the switches but ending the body.
 */
void run_task(void)
{
    int imm, rs, rt, rd;
    int BC;
    unsigned int addr; /* scalar loads, stores:  LB, LH, LW, LBU, LHU, SH, SW */

#ifdef WAIT_FOR_CPU_HOST
    if (CFG_WAIT_FOR_CPU_HOST != 0)
        for (rt = 0; rt < 32; rt++)
            MFC0_count[rt] = 0;
#endif
    while (!(*RSP.SP_STATUS_REG & 0x00000001))
    { /* Explicitly speaking, it must == 0x0, though the object is NOT(HALT). */
        inst.W = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
        if (*RSP.SP_STATUS_REG & 0x00000020) // SP_STATUS_SSTEP by debugger.
        {
            message("Omitted SP debug interface.", 0); /*
            if (rsp.step_count) // from MAME / Ville Linde
                --rsp.step_count;
            else
            {
                *RSP.SP_STATUS_REG |= 0x00000002;
                message("SP_STATUS_BROKE", 3);
            } */
        }
#ifdef SP_EXECUTE_LOG
        step_SP_commands(inst.W);
#endif
        *RSP.SP_PC_REG += 0x004;
        *RSP.SP_PC_REG &= 0x00000FFC;
/* This is the fastest method of maintaining the correct PC.
 * It is not the most accurate because PC slot checks happen after cycle EX.
 *
 * Be warned that this modifies the implemented solutions to emulating the
 * branch and jump operations.  For instance, to emulate BAL or JAL, we
 * increment the PC only by += 0x004, not by += 0x008 like the doc says.
 * Ultimately, the PC register and link address stores remain 100% accurate.
 */
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
            continue;
        }
        if (SR[0] != 0x00000000)
            message("$0", 0); /* tried to overwrite MIPS GPR $zero */
        SR[0] = 0x00000000;
        EX_SCALAR[inst.J.op][(inst.W >> sub_op_table[inst.J.op]) & 077]();
    }
/*
 * If we have reached this point in the program, it means that the SP task
 * was terminated in a way other than executing BREAK.  From an accuracy
 * point of view, this is highly unusual, but there are a few possibilities.
 */
    if (*RSP.MI_INTR_REG & 0x00000001) /* 1.  interrupt set by MTC0 to break */
        RSP.CheckInterrupts();
    else if (CFG_WAIT_FOR_CPU_HOST != 0) /* 2.  plugin system hack to re-sync */
        {}
    else if (*RSP.SP_SEMAPHORE_REG != 0x00000000) /* 3.  semaphore lock fixes */
        {}
    else /* ??? unknown, possibly external intervention from CPU memory map */
    {
        message("SP_SET_HALT", 3);
        return;
    }
    *RSP.SP_STATUS_REG &= ~0x00000001; /* CPU restarts with the correct SIGs. */
    return;
}

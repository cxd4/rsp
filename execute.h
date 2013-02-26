/******************************************************************************\
* Project:  Hybrid Interpreter Combining Static and Dynamic Decode             *
* Authors:  Iconoclast                                                         *
* Release:  2013.02.25                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* The MSP for the N64 RCP has two parts:  a scalar unit and a vector unit.
 *
 * The SU is basically a 32-bit subset of the design template used for the
 * original MIPS family revision 4000.  This interpreter will maintain the
 * traditional approach for SU instructions.  The function calls to the
 * functional-based interpreter operations I have defined elsewhere are
 * intended to be inline-serviced by the compiler to accelerate the decode
 * phase resultant of interpreting code instead of re-compiling it.  (If
 * this file is not used, interpretation is way slower because of function
 * calls pushing instruction operands as function call stack arguments.)
 *
 * The VU for its time was revolutionary and still comprises many special
 * vector operations not apt to replication on SSE4, AVX, or other recent
 * enhancements to the Intel instruction set.  As such, to match the grace
 * of cycling through SU operations, I have decided to take it upon myself
 * to attempt a "static interpreter" which voids the decode cyclical steps.
 * The RCP essentially splits processor behavior for SU and VU operations,
 * so my attempt at this "static interpreter" is temporarily slopped at the
 * bottom of this file.  --cxd4
 */

__declspec(dllexport) unsigned long _cdecl DoRspCycles(unsigned long cycles)
{
    if (*RSP.SP_STATUS_REG & 0x00000003)
    {
        message("SP HALT/BROKE on start!", 3);
        return 0;
    }
    switch (*(unsigned int *)(RSP.DMEM + 0xFC0))
    { /* Simulation barrier to redirect processing externally. */
#ifdef EXTERN_COMMAND_LIST_GBI
        case 0x00000001:
            if (RSP.ProcessDList == 0) {} else
                RSP.ProcessDList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            return 0;
#endif
#ifdef EXTERN_COMMAND_LIST_ABI
        case 0x00000002: /* OSTask.type == M_AUDTASK */
            if (RSP.ProcessAList == 0) {} else
                RSP.ProcessAList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            return 0;
#endif
    }
    *RSP.SP_PC_REG &= 0x00000FFF;
    do
    {
        register unsigned int inst;

        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
        if (delay_clock >= 0)
        { /* most likely that this condition does NOT take the branch */
            if (delay_clock == 0)
            {
                *RSP.SP_PC_REG  = temp_PC;
                *RSP.SP_PC_REG &= 0x00000FFC;
                --delay_clock; /* maybe more optimizable: `delay_clock = -1` */
                continue;
            }
            --delay_clock;
        }
        *RSP.SP_PC_REG += 0x00000004;
        *RSP.SP_PC_REG &= 0x00000FFC;
        if (inst >> 25 == 0x25) /* is a VU instruction */
            execute_VU(inst);
        else
        {
            const int rs = (inst & 0x03E00000) >> 21;
            const int rt = (inst >> 16) & 0x0000001F; /* Try to mov upper HW. */
            const short imm = (short)inst; /* (un)signed is sub-op-defined. */

            inst >>= 26;
            SP_PRIMARY[inst](rs, rt, imm);
        }
        --cycles;
        if (*RSP.SP_STATUS_REG & 0x00000020) /* SP_STATUS_SSTEP by debugger. */
            message("Single-stepping support unconfirmed.", 2);
    } while ((*RSP.SP_STATUS_REG & 0x00000001) == 0x00000000);
    if (!(*RSP.SP_STATUS_REG & 0x00000002)) /* BROKE was not set. */
        message("Halted RSP CPU loop by means of MTC0.", 2);
    return (cycles);
}

inline void execute_VU(unsigned int inst)
{
    register int i = 0; /* iteration count index for (liably unrolled) loops */

    switch (inst)
    {
        case 0x4A000000: // VMULF $v0, $v0, $v0
            for (i = 0; i < 8; i++)
                VACC[i].DW = 2*VR[0].s[i]*VR[0].s[i] + 0x8000;
            for (i = 0; i < 8; i++)
                VR[0].s[i] = (VR[0].s[i] == 0x8000) ? 0x7FFF : VACC[i].s[MD];
            return;
        default:
        {
            char debugger[] = "XXXXXXXX\nTreating as reserved.";
            const char digits[16] = {
                '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
            };
            debugger[00] = digits[(inst & 0xF0000000) >> 28];
            debugger[01] = digits[(inst & 0x0F000000) >> 24];
            debugger[02] = digits[(inst & 0x00F00000) >> 20];
            debugger[03] = digits[(inst & 0x000F0000) >> 16];
            debugger[04] = digits[(inst & 0x0000F000) >> 12];
            debugger[05] = digits[(inst & 0x00000F00) >>  8];
            debugger[06] = digits[(inst & 0x000000F0) >>  4];
            debugger[07] = digits[(inst & 0x0000000F) >>  0];
            MessageBoxA(NULL, debugger, NULL, 0x00000030);
            for (i = 0; i < 8; i++)
                VR[(inst >> 6) % 32].s[i] = 0x0000;
            return;
        }
    }
}

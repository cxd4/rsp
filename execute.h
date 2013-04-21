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
void run_microcode(void)
{
    int imm, rs, rt, rd;
    int BC;
    unsigned int addr; /* scalar loads, stores:  LB, LH, LW, LBU, LHU, SH, SW */
    register unsigned int inst;

#ifdef WAIT_FOR_CPU_HOST
    for (rt = 0; rt < 31; rt++)
        MFC0_count[rt] = 0;
#endif
    while (!(*RSP.SP_STATUS_REG & 0x00000001))
    { /* Explicitly speaking, it must == 0x0, though the object is NOT(HALT). */
        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
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
        step_SP_commands(inst);
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
        if (inst >> 25 == 0x25) /* is a VU instruction */
        {
            const int vd = (inst & 0x000007C0) >>  6;
            const int vs = (inst & 0x0000FFFF) >> 11;
            const int vt = (inst & 0x001F0000) >> 16;
            const int e  = (inst & 0x01E00000) >> 21;

            SP_COP2_C2[inst % 64](vd, vs, vt, e);
            continue;
        }
        SR[0] ^= SR[0];
/* I don't want to essay out an entire list of accurate ways we could emulate
 * the MIPS `zero` register's permanence, but let's just remember these keys:
 *
 * 1.  Ensure that the virtual register is constantly fixed to one value.
 * 2.  Save code block size in switch block splits with more code space.
 * 3.  Avoid creating new branch labels and blocks for exiting if rd == 0.
 * #1 means more stable, #2 means faster, and #3 means more accurate + fast.
 */
        imm = inst & 0x0000FFFF;
        rd = (unsigned short)(imm) >> 11; /* mov ecx, ax; shr ecx, 11 */
        rs = (unsigned)(inst) >> 21; /* Don't assume that op isn't 0b000000. */
        rt = (inst >> 16) & 31; /* Do a LUI on `inst`, then ANDI by 31. */
        switch (inst >> 26)
        {
            case 000: /* SPECIAL */
                switch (imm & 077) /* rs = inst >> 21, w/o having to `&= 31`. */
                {
                    int sa;

                    case 000: /* SLL */
                        sa = (imm & 0x07C0) >> 6;
                        SR[rd] = SR[rt] << sa;
                        continue;
                    case 002: /* SRL */
                        sa = (imm & 0x07C0) >> 6;
                        SR[rd] = (unsigned)(SR[rt]) >> sa;
                        continue;
                    case 003: /* SRA */
                        sa = (imm & 0x07C0) >> 6;
                        SR[rd] = (signed)(SR[rt]) >> sa;
                        continue;
                    case 004: /* SLLV */
                        SR[rd] = SR[rt] << (SR[rs] & 31);
                        continue;
                    case 006: /* SRLV */
                        SR[rd] = (unsigned)(SR[rt]) >> (SR[rs] & 31);
                        continue;
                    case 007: /* SRAV */
                        SR[rd] = (signed)(SR[rt]) >> (SR[rs] & 31);
                        continue;
                    case 010: /* JR */
                        temp_PC = SR[rs];
                        goto BRANCH;
                    case 011: /* JALR */
                        SR[rd] = (*RSP.SP_PC_REG + 0x004) & 0x00000FFC;
                        temp_PC = SR[rs];
                        goto BRANCH;
                    case 015: /* BREAK */
                        *RSP.SP_STATUS_REG |= 0x00000003;
                        if (*RSP.SP_STATUS_REG & 0x00000040)
                        { /* SP_STATUS_INTR_BREAK */
                            *RSP.MI_INTR_REG |= 0x00000001;
                            RSP.CheckInterrupts();
                        }
                        return; /* return (cycles); */
                    case 040: /* ADD */
                        SR[rd] = SR[rs] + SR[rt];
                        continue;
                    case 041: /* ADDU */
                        SR[rd] = SR[rs] + SR[rt];
                        continue;
                    case 042: /* SUB */
                        SR[rd] = SR[rs] - SR[rt];
                        continue;
                    case 043: /* SUBU */
                        SR[rd] = SR[rs] - SR[rt];
                        continue;
                    case 044: /* AND */
                        SR[rd] = SR[rs] & SR[rt];
                        continue;
                    case 045: /* OR */
                        SR[rd] = SR[rs] | SR[rt];
                        continue;
                    case 046: /* XOR */
                        SR[rd] = SR[rs] ^ SR[rt];
                        continue;
                    case 047: /* NOR */
                        SR[rd] = ~(SR[rs] | SR[rt]);
                        continue;
                    case 052: /* SLT */
                        SR[rd] = (signed)(SR[rs]) < (signed)(SR[rt]);
                        continue;
                    case 053: /* SLTU */
                        SR[rd] = (unsigned)(SR[rs]) < (unsigned)(SR[rt]);
                        continue;
                    default:
                        message("SPECIAL\nRESERVED", 3);
                        continue;
                }
            case 001: /* REGIMM */
                rs &= 31;
                switch (rt)
                {
                    default:
                        message("REGIMM\nRESERVED", 3);
                        continue;
                    case 000: /* BLTZ */
                        BC = ((signed)SR[rs] < 0);
                        if (!BC) continue;
                        temp_PC = *RSP.SP_PC_REG + (imm << 2);
                        goto BRANCH;
                    case 001: /* BGEZ */
                        BC = ((signed)SR[rs] >= 0);
                        if (!BC) continue;
                        temp_PC = *RSP.SP_PC_REG + (imm << 2);
                        goto BRANCH;
                    case 020: /* BLTZAL */
                        SR[31] = (*RSP.SP_PC_REG + 0x004) & 0x00000FFC;
                        BC = ((signed)SR[rs] < 0);
                        if (!BC) continue;
                        temp_PC = *RSP.SP_PC_REG + (imm << 2);
                        goto BRANCH;
                    case 021: /* BGEZAL */
                        SR[31] = (*RSP.SP_PC_REG + 0x004) & 0x00000FFC;
                        BC = ((signed)SR[rs] >= 0);
                        if (!BC) continue;
                        temp_PC = *RSP.SP_PC_REG + (imm << 2);
                        goto BRANCH;
                }
            case 002: /* J */
                temp_PC = imm << 2;
                goto BRANCH;
            case 003: /* JAL */
                SR[31] = (*RSP.SP_PC_REG + 0x004) & 0x00000FFC;
                temp_PC = imm << 2;
                goto BRANCH;
            case 004: /* BEQ */
                BC = (SR[rs &= 31] == SR[rt]);
                if (!BC) continue;
                temp_PC = *RSP.SP_PC_REG + (imm << 2);
                goto BRANCH;
            case 005: /* BNE */
                BC = (SR[rs &= 31] != SR[rt]);
                if (!BC) continue;
                temp_PC = *RSP.SP_PC_REG + (imm << 2);
                goto BRANCH;
            case 006: /* BLEZ */
                BC = ((signed)SR[rs &= 31] <= 0);
                if (!BC) continue;
                temp_PC = *RSP.SP_PC_REG + (imm << 2);
                goto BRANCH;
            case 007: /* BGTZ */
                BC = ((signed)SR[rs &= 31] > 0);
                if (!BC) continue;
                temp_PC = *RSP.SP_PC_REG + (imm << 2);
                goto BRANCH;
            case 010: /* ADDI */
                SR[rt] = SR[rs &= 31] + (signed short)imm;
                continue;
            case 011: /* ADDIU */
                SR[rt] = SR[rs &= 31] + (signed short)imm;
                continue;
            case 012: /* SLTI */
                SR[rt] = ((signed)SR[rs &= 31] < (signed short)imm);
                continue;
            case 013: /* SLTIU */
                SR[rt] = ((unsigned)SR[rs &= 31] < (unsigned long)(short)imm);
                continue;
            case 014: /* ANDI */
                SR[rt] = SR[rs &= 31] & (unsigned short)imm;
                continue;
            case 015: /* ORI */
                SR[rt] = SR[rs &= 31] | (unsigned short)imm;
                continue;
            case 016: /* XORI */
                SR[rt] = SR[rs &= 31] ^ (unsigned short)imm;
                continue;
            case 017: /* LUI */
                SR[rt] = imm << 16;
                continue;
            case 020: /* COP0 */
#if (0 == 0)
                SP_COP0[rs &= 31](rt, rd);
                continue; /* Too complex to maintain in this memory space. */
#else
                switch (rs &= 31)
                {
                    case 000: /* MFC0 */
                        SR[rt] = **CR[rd];
                        continue;
                    case 004: /* MTC0 */
                        MTC0(rt, rd);
                        continue;
                    default:
                        message("COP0\nRESERVED", 3);
                        continue;
                }
#endif
            case 022: /* COP2 */
                SP_COP2[rs &= 31](rt, rd, (imm >> 7) & 0xF);
                continue;
            case 040: /* LB */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                SR[rt] = *(signed char *)(RSP.DMEM + BES(addr));
                continue;
            case 041: /* LH */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                switch (addr & 03)
                {
                    case 00: /* word-aligned */
                        SR[rt] = *(signed short *)(RSP.DMEM + (addr + 0x002));
                        continue;
                    case 01:
                        SR[rt] = *(signed short *)(RSP.DMEM + (addr | 0x000));
                        continue;
                    case 02:
                        SR[rt] = *(signed short *)(RSP.DMEM + (addr - 0x002));
                        continue;
                    case 03:
                        SR[rt]  = RSP.DMEM[addr - 0x003] << 8;
                        SR[rt] |= RSP.DMEM[(addr += 0x004) & 0x00000FFF];
                        SR[rt]  = (signed short)(SR[rt]);
                        continue;
                }
            case 043: /* LW */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                switch (addr & 03)
                {
                    case 00: /* word-aligned */
                        SR[rt] = *(int *)(RSP.DMEM + addr);
                        continue;
                    case 01:
                        SR[rt]   = RSP.DMEM[addr + 0x001];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr | 0x000];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr - 0x001];
                        SR[rt] <<= 8;
                        addr += 0x006;
                        SR[rt]  |= RSP.DMEM[addr &= 0x00000FFF];
                        continue;
                    case 02:
                        SR[rt]   = RSP.DMEM[addr - 0x001];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr - 0x002];
                        SR[rt] <<= 8;
                        addr += 0x005;
                        addr &= 0x00000FFF;
                        SR[rt]  |= RSP.DMEM[addr | 0x000];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr - 0x001];
                        continue;
                    case 03:
                        SR[rt]   = RSP.DMEM[addr - 0x003];
                        SR[rt] <<= 8;
                        addr += 0x004;
                        addr &= 0x00000FFF;
                        SR[rt]  |= RSP.DMEM[addr | 0x000];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr - 0x001];
                        SR[rt] <<= 8;
                        SR[rt]  |= RSP.DMEM[addr - 0x002];
                        continue;
                }
            case 044: /* LBU */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                SR[rt] = *(unsigned char *)(RSP.DMEM + BES(addr));
                continue;
            case 045: /* LHU */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                switch (addr & 03)
                {
                    case 00: /* word-aligned */
                        SR[rt] = *(unsigned short *)(RSP.DMEM + (addr + 0x002));
                        continue;
                    case 01:
                        SR[rt] = *(unsigned short *)(RSP.DMEM + (addr | 0x000));
                        continue;
                    case 02:
                        SR[rt] = *(unsigned short *)(RSP.DMEM + (addr - 0x002));
                        continue;
                    case 03:
                        SR[rt]  = RSP.DMEM[addr - 0x003] << 8;
                        SR[rt] |= RSP.DMEM[(addr += 0x004) & 0x00000FFF];
                        continue;
                }
            case 050: /* SB */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                *(RSP.DMEM + BES(addr)) = SR[rt] & 0xFF;
                continue;
            case 051: /* SH */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                switch (addr & 03)
                {
                    case 00: /* word-aligned */
                        *(short *)(RSP.DMEM + (addr + 0x002)) = SR[rt] & 0xFFFF;
                        continue;
                    case 01:
                        *(short *)(RSP.DMEM + (addr | 0x000)) = SR[rt] & 0xFFFF;
                        continue;
                    case 02:
                        *(short *)(RSP.DMEM + (addr - 0x002)) = SR[rt] & 0xFFFF;
                        continue;
                    case 03:
                        RSP.DMEM[addr - 0x003] = (SR[rt] >> 8) & 0xFF;
                        RSP.DMEM[(addr += 0x004) & 0x00000FFF] = SR[rt] & 0xFF;
                        continue;
                }
            case 053: /* SW */
                addr = (SR[rs &= 31] + imm) & 0x00000FFF;
                switch (addr & 03)
                {
                    case 00: /* word-aligned */
                        *(int *)(RSP.DMEM + addr) = SR[rt];
                        continue;
                    case 01:
                        RSP.DMEM[addr + 0x001] = (SR[rt] >> 24) & 0xFF;
                        RSP.DMEM[addr | 0x000] = (SR[rt] >> 16) & 0xFF;
                        RSP.DMEM[addr - 0x001] = (SR[rt] >>  8) & 0xFF;
                        addr += 0x006;
                        RSP.DMEM[addr &= 0x00000FFF] = SR[rt] & 0xFF;
                        continue;
                    case 02:
                        RSP.DMEM[addr - 0x001] = (SR[rt] >> 24) & 0xFF;
                        RSP.DMEM[addr - 0x002] = (SR[rt] >> 16) & 0xFF;
                        addr += 0x005;
                        addr &= 0x00000FFF;
                        RSP.DMEM[addr | 0x000] = (SR[rt] >>  8) & 0xFF;
                        RSP.DMEM[addr - 0x001] = (SR[rt] >>  0) & 0xFF;
                        continue;
                    case 03:
                        RSP.DMEM[addr - 0x003] = (SR[rt] >> 24) & 0xFF;
                        addr += 0x004;
                        addr &= 0x00000FFF;
                        RSP.DMEM[addr | 0x000] = (SR[rt] >> 16) & 0xFF;
                        RSP.DMEM[addr - 0x001] = (SR[rt] >>  8) & 0xFF;
                        RSP.DMEM[addr - 0x002] = (SR[rt] >>  0) & 0xFF;
                        continue;
                }
            case 062: /* LWC2 */
                imm &= 0x007F;
                imm |= -(imm & 0x0040);
                SP_LWC2[rd](rt, (inst >>= 7) & 0xF, imm, rs &= 31);
                continue; /* Too complex to maintain in this memory space. */
            case 072: /* SWC2 */
                imm &= 0x007F;
                imm |= -(imm & 0x0040);
                SP_SWC2[rd](rt, (inst >>= 7) & 0xF, imm, rs &= 31);
                continue; /* Too complex to maintain in this memory space. */
            default:
                message("RESERVED", 3);
                continue; /* How are reserved commands conducted on the RCP? */
        }
    }
    if (*RSP.SP_SEMAPHORE_REG == 0x00000001) /* SP semaphore lock (zilmar) */
        *RSP.SP_STATUS_REG &= ~0x00000001; /* Guess I need to let emu retask. */
#ifdef WAIT_FOR_CPU_HOST
    else if (MFC0_count != 0)
        *RSP.SP_STATUS_REG &= ~0x00000001; /* CPU restarts with correct SIGs. */
#endif
    else
    {
        message("Halted RSP CPU loop by means of MTC0.", 2); /* not sure */
        *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
        RSP.CheckInterrupts();
    }
    while (SR[0] != SR[0])
    {
BRANCH:
        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
#ifdef SP_EXECUTE_LOG
        step_SP_commands(inst);
#endif
        *RSP.SP_PC_REG = temp_PC & 0x00000FFC;
        /* temp_PC = 0x00000000 ^ 0xFFFFFFFF; */
        goto EX;
    }
}

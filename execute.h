/*
    Nintendo/SGI Reality Signal Processor (RSP) emulator

    Written by Ville Linde
*/

/* All the scalar unit (SU) emulation for the primary R4000 operations is
 * managed in this file.  I have entirely rewritten and checked/debugged
 * almost everything else but the primary opcodes listed here, so credit for
 * those most go to Ville Linde M.E.S.S. development and ziggy for some small
 * rewrites and testing/checking of his own.  Eventually when I re-derive
 * these opcodes and recreate them into a function jump table this file will
 * probably be destroyed. -- Iconoclast
 */

#include "Rsp_#1.1.h"
#include "rsp.h"
//#include <math.h>
/* Note about `#include <math.h>`.
 * The only need for this file in the RSP emulator has always been a function
 * for doing a square root operation.  However, depending what compiler you
 * use, there may be an option to control the Intel hardware FP precision.
 * If this is set correctly, an Intel FSQRT instruction will be generated
 * without having to call an external math library function for square root,
 * thus eliminating the need for `math.h` or any such thing under the CRT.
 */

#define LOG_INSTRUCTION_EXECUTION   0
#define SAVE_DISASM                 0
#define SAVE_DMEM                   0

///мой код
char RspDasmOutput[100];
char big[2000];
extern int HmDebug;
extern FILE* newfile;
extern UINT64 DebugCount;

const int element_index[16][8] = {
    { 00, 01, 02, 03, 04, 05, 06, 07 }, /* none */
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 00, 00, 02, 02, 04, 04, 06, 06 }, /* 0Q */
    { 01, 01, 03, 03, 05, 05, 07, 07 }, /* 1Q */
    { 00, 00, 00, 00, 04, 04, 04, 04 }, /* 0H */
    { 01, 01, 01, 01, 05, 05, 05, 05 }, /* 1H */
    { 02, 02, 02, 02, 06, 06, 06, 06 }, /* 2H */
    { 03, 03, 03, 03, 07, 07, 07, 07 }, /* 3H */
    { 00, 00, 00, 00, 00, 00, 00, 00 }, /* 0 */
    { 01, 01, 01, 01, 01, 01, 01, 01 }, /* 1 */
    { 02, 02, 02, 02, 02, 02, 02, 02 }, /* 2 */
    { 03, 03, 03, 03, 03, 03, 03, 03 }, /* 3 */
    { 04, 04, 04, 04, 04, 04, 04, 04 }, /* 4 */
    { 05, 05, 05, 05, 05, 05, 05, 05 }, /* 5 */
    { 06, 06, 06, 06, 06, 06, 06, 06 }, /* 6 */
    { 07, 07, 07, 07, 07, 07, 07, 07 }  /* 7 */
};

/* This is zilmar's method of transposing the source element read order,
 * based on the loop iteration count and destination element, to avoid
 * premature vector element overwrites.  The more modern method however
 * is to just not transpose the read orders and write to a prebuffer,
 * temporary vector register, then do one single hit to move the result
 * over to the destination vector register.  So this probably has no use.
 */
const int element_source_transpose[16][8] = {
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 01, 03, 05, 07, 00, 02, 04, 06 },
    { 00, 02, 04, 06, 01, 03, 05, 07 },
    { 01, 02, 03, 05, 06, 07, 00, 04 },
    { 00, 02, 03, 04, 06, 07, 01, 05 },
    { 00, 01, 03, 04, 05, 07, 02, 06 },
    { 00, 01, 02, 04, 05, 06, 03, 07 },
    { 01, 02, 03, 04, 05, 06, 07, 00 },
    { 00, 02, 03, 04, 05, 06, 07, 01 },
    { 00, 01, 03, 04, 05, 06, 07, 02 },
    { 00, 01, 02, 04, 05, 06, 07, 03 },
    { 00, 01, 02, 03, 05, 06, 07, 04 },
    { 00, 01, 02, 03, 04, 06, 07, 05 },
    { 00, 01, 02, 03, 04, 05, 07, 06 },
    { 00, 01, 02, 03, 04, 05, 06, 07 }
};

#include "special/special.h"
#include "regimm/regimm.h"
#include "cop0/cop0.h"
#include "cop2/cop2.h"
#include "lwc2/lwc2.h"
#include "swc2/swc2.h"

#include "vu/vu.h" /* All the includes above are SU; this is the VU. */

extern offs_t rsp_dasm_one(char *buffer, offs_t pc, UINT32 op);
#if LOG_INSTRUCTION_EXECUTION
static FILE *exec_output;
#endif

// INLINE void sp_set_status(UINT32 status)
// {
//     if (status & 0x1)
//     {
//         cpu_trigger(6789);

//         cpunum_set_input_line(1, INPUT_LINE_HALT, ASSERT_LINE);
//         rsp_sp_status |= SP_STATUS_HALT;
//     }
//     if (status & 0x2)
//     {
//         rsp_sp_status |= SP_STATUS_BROKE;

//         if (rsp_sp_status & SP_STATUS_INTR_BREAK)
//         {
//             signal_rcp_interrupt(SP_INTERRUPT);
//         }
//     }
// }

#ifdef RSPTIMING
uint64_t rsptimings[512];
int rspcounts[512];
#endif

RSP_REGS rsp;
static int rsp_icount;

int rsp_execute(unsigned long cycles)
{
    const unsigned long cycles_start = cycles; /* preserve original */

    if (*RSP.SP_STATUS_REG & 0x00000001)
    {
        message("SP HALT/BROKE on start!", 3);
        return 0;
    }
    *RSP.SP_PC_REG &= 0x00000FFF;
    do
    {
        register unsigned int inst;

        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
#ifdef SP_EXECUTE_LOG
        if (output_log)
        {
            unsigned char endian_swap[4];

            endian_swap[00] = (unsigned char)(inst >> 24);
            endian_swap[01] = (unsigned char)(inst >> 16);
            endian_swap[02] = (unsigned char)(inst >>  8);
            endian_swap[03] = (unsigned char)inst;
            fwrite(endian_swap, 4, 1, output_log);
        }
#endif
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
        if (inst >> 25 == 0x25) /* is a VU instruction? */
        {
            const unsigned vd = (inst >>  6) & 0x0000001F;
            const unsigned vs = (unsigned short)(inst) >> 11;
            const unsigned vt = (inst >> 16) & 0x001F;
            const unsigned e  = (inst >> 21) & 0x0000000F;

            inst &= 0x0000003F;
            SP_COP2_VECTOP[inst](vd, vs, vt, e);
            continue;
        }
        switch (inst >> 26)
        {
            case 0x00: /* SPECIAL */
            {
                unsigned int rs = inst;
                unsigned int rt = inst >> 16; /* Try to mov upper HW? */
                unsigned short rd = (unsigned short)inst; /* mov LO HW */
                const unsigned sa = (inst >> 6) & 31;
#ifdef SLL_NOP_AS_SEMICYCLE
                if (inst == 0x00000000) continue;
#endif
                rs >>= 21; /* no need to mask, cuz op == zero */
                rt  &= 31; /* LO five bits of upper HW */
                rd >>= 11; /* HI five bits of lower HW */
                inst &= 0x0000003F; /* "function" specifier */
                SP_SPECIAL[inst](rs, rt, rd, sa);
                break;
            }
            case 0x01: /* REGIMM */
            {
                int rt = (inst >> 16); /* load upper halfword */
                const unsigned rs = (inst >> 21) & 0x0000001F;
                signed long int offset = (short)inst; /* load lower halfword */
                rt &= 0x0000001F;
                offset <<= 2;
                SP_REGIMM[rt](rs, offset);
                break;
            }
            case 0x02: /* J */
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC = inst;
                delay_clock = 1;
                break;
            case 0x03: /* JAL */
                SR[31]  = *RSP.SP_PC_REG;
                SR[31] += 0x00000004; /* should be 8! :mad: */
                SR[31] &= 0x00000FFC; /* Link FIRST, */
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC = inst; /* THEN jump (processor manual order). */
                delay_clock = 1;
                break;
            case 0x04: /* BEQ */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (SR[rs] != SR[rt]) break;
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC  = *RSP.SP_PC_REG;
                temp_PC += inst;
                delay_clock = 1;
                break;
            }
            case 0x05: /* BNE */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (SR[rs] == SR[rt]) break;
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC  = *RSP.SP_PC_REG;
                temp_PC += inst;
                delay_clock = 1;
                break;
            }
            case 0x06: /* BLEZ */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                if ((signed)SR[rs] > 0) break;
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC  = *RSP.SP_PC_REG;
                temp_PC += inst;
                delay_clock = 1;
                break;
            }
            case 0x07: /* BGTZ */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                if ((signed)SR[rs] <= 0) break;
                inst  &= 0x000003FF;
                inst <<= 2;
                temp_PC  = *RSP.SP_PC_REG;
                temp_PC += inst;
                delay_clock = 1;
                break;
            }
            case 0x08: /* ADDI */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register signed short int immediate = (short)inst;
                if (rt == 0) break;
                SR[rt] = SR[rs] + immediate;
                break;
            }
            case 0x09: /* ADDIU */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register signed short int immediate = (short)inst;
                if (rt == 0) break;
                SR[rt] = SR[rs] + immediate;
                break;
            }
            case 0x0A: /* SLTI */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register signed short int immediate = (short)inst;
                if (rt == 0) break;
                SR[rt] = (signed)SR[rs] < (signed)immediate;
                break;
            }
            case 0x0B: /* SLTIU */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register signed short int immediate = (short)inst;
                if (rt == 0) break;
                SR[rt] = (unsigned)SR[rs] < (unsigned)immediate;
                break;
            }
            case 0x0C: /* ANDI */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (rt == 0) break;
                inst &= 0x0000FFFF;
                SR[rt] = SR[rs] & inst;
                break;
            }
            case 0x0D: /* ORI */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (rt == 0) break;
                inst &= 0x0000FFFF;
                SR[rt] = SR[rs] | inst;
                break;
            }
            case 0x0E: /* XORI */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (rt == 0) break;
                inst &= 0x0000FFFF;
                SR[rt] = SR[rs] ^ inst;
                break;
            }
            case 0x0F: /* LUI */{
                const unsigned rt = (inst >> 16) & 0x0000001F;
                if (rt == 0) break;
                inst &= 0x0000FFFF;
                SR[rt] = inst << 16;
                break;
            }
            case 0x10: /* COP0 */
            {
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                const unsigned rd = (unsigned short)(inst) >> 11;

                if (rd & 16)
                {
/* What to do here is controversial because we have conflicting sources.
 * In the assembler manual references, $cn is permitted for n <= 31.
 * However, in the programming reference, 'n' is defined to be <= 15.
 */
                    message("COP0", 2);
                    break; /* Correct behavior I think is to just exit? */
                }
                SP_COP0[rs](rt, rd);
                break;
            }
            case 0x12: /* COP2 */
            {
                const unsigned e  = (inst >>  7) & 0xF;
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                const unsigned rd = (unsigned short)(inst) >> 11;
                SP_COP2[rs](rt, rd, e);
                break;
            }
            case 0x20: /* LB */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                if (rt == 0) break;
                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                SR[rt] = ((signed char *)RSP.DMEM)[addr ^ 03];
                break;
            }
            case 0x21: /* LH */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                if (rt == 0) break;
                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                if ((addr & 0x001) != 0x000)
                {
                    register signed short int halfword;
                    message("LH\nCrossed halfword index barrier.", 0);
                    halfword   = RSP.DMEM[addr ^ 03];
                    halfword <<= 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    halfword  |= RSP.DMEM[addr ^ 03];
                    SR[rt] = halfword;
                    break;
                }
                addr ^= 0x002; /* halfword endian swap */
                SR[rt] = *(signed short *)(RSP.DMEM + addr);
                break;
            }
            case 0x23: /* LW */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                if (rt == 0) break;
                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                if (addr & 0x003)
                { /* Super Mario 64 boot sequence */
                    register int word;
                    message("LW\nCrossed word index barrier.", 0);
                    word   = RSP.DMEM[addr ^ 03];
                    word <<= 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    word  |= RSP.DMEM[addr ^ 03];
                    word <<= 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    word  |= RSP.DMEM[addr ^ 03];
                    word <<= 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    word  |= RSP.DMEM[addr ^ 03];
                    SR[rt] = word;
                    break;
                }
                SR[rt] = *(int *)(RSP.DMEM + addr);
                break;
            }
            case 0x24: /* LBU */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                if (rt == 0) break;
                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                SR[rt] = RSP.DMEM[addr ^ 03];
                break;
            }
            case 0x25: /* LHU */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                if (rt == 0) break;
                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                if ((addr & 0x001) != 0x000)
                { /* Super Mario 64 boot sequence */
                    register unsigned short halfword;
                    message("LHU\nCrossed halfword index barrier.", 0);
                    halfword   = ((unsigned char *)RSP.DMEM)[addr ^ 03];
                    halfword <<= 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    halfword  |= ((unsigned char *)RSP.DMEM)[addr ^ 03];
                    SR[rt] = halfword;
                    break;
                }
                addr ^= 0x002; /* halfword endian swap */
                SR[rt] = *(unsigned short *)(RSP.DMEM + addr);
                break;
            }
            case 0x28: /* SB */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                *(RSP.DMEM + (addr ^ 03)) = (unsigned char)SR[rt];
                break;
            }
            case 0x29: /* SH */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                addr = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                if ((addr & 0x001) != 0x000)
                {
                    message("SH\nCrossed halfword index barrier.", 0);
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned short)SR[rt] >> 8;
                    ++addr;
                    addr &= 0x00000FFF;
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned char)SR[rt];
                    break;
                }
                addr ^= 0x002; /* halfword endian swap */
                *(short *)(RSP.DMEM + addr) = (unsigned short)SR[rt];
                break;
            }
            case 0x2B: /* SW */{
                const unsigned rs = (inst >> 21) & 0x0000001F;
                const unsigned rt = (inst >> 16) & 0x0000001F;
                register unsigned int addr;

                addr  = SR[rs];
                addr += (signed short)inst;
                addr &= 0x00000FFF;
                if (addr & 0x003)
                { /* Super Mario 64 boot sequence */
                    register unsigned int word = SR[rt];
                    message("SW\nCrossed word index barrier.", 0);
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned char)(word >> 24);
                    ++addr;
                    addr &= 0x00000FFF;
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned char)(word >> 16);
                    ++addr;
                    addr &= 0x00000FFF;
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned char)(word >>  8);
                    ++addr;
                    addr &= 0x00000FFF;
                    *(RSP.DMEM + (addr ^ 03)) = (unsigned char)(word >>  0);
                    break;
                }
                *(int *)(RSP.DMEM + addr) = SR[rt];
                break;
            }
            case 0x32: /* LWC2 */{
                unsigned short base    = (inst >> 21) & 0x0000001F;
                unsigned short vt = (inst >> 16); /* load upper halfword */
                unsigned short vd = (short)inst; /* load lower halfword */
                unsigned short element = (inst >>  6) & 0x0000001F;
                signed int offset = inst & 0x0000003F;
                vt  &= 0x001F; /* 110010 ----- ttttt ----- ----- ------ */
                vd >>= 11;     /* 110010 ----- ----- ddddd ----- ------ */
                if ((element & 01) == 00)
                {
                    element >>= 1;
                    SP_LWC2[vd](vt, element, offset, base);
                    break;
                }
                offset |= ~077; /* sign-extended, if LSB of (element) */
                element >>= 1;
                SP_LWC2[vd](vt, element, offset, base);
                break;
            }
            case 0x3A: /* SWC2 */{
                unsigned short base    = (inst >> 21) & 0x0000001F;
                unsigned short vt = (inst >> 16); /* load upper halfword */
                unsigned short vd = (short)inst; /* load lower halfword */
                unsigned short element = (inst >>  6) & 0x0000001F;
                signed int offset = inst & 0x0000003F;
                vt  &= 0x001F; /* 111010 ----- ttttt ----- ----- ------ */
                vd >>= 11;     /* 111010 ----- ----- ddddd ----- ------ */
                if ((element & 01) == 00)
                {
                    element >>= 1;
                    SP_SWC2[vd](vt, element, offset, base);
                    break;
                }
                offset |= ~077;
                element >>= 1;
                SP_SWC2[vd](vt, element, offset, base);
                break;
            }
            default: {
                message("Reserved Instruction", 3);
                break;
            } /* Not a RSP exception, but an emu error cause IDK what to do. */
        }
        --cycles;
        if (*RSP.SP_STATUS_REG & 0x00000020) /* SP_STATUS_SSTEP by debugger. */
        { /* реализация из 0.122u7 */
            message("Single-stepping support unconfirmed.", 2);
            if (rsp.step_count)
                --rsp.step_count;
            else
            {
                *RSP.SP_STATUS_REG |= 0x00000002;
                message("SP_STATUS_BROKE", 3);
            }
        }
    } while ((*RSP.SP_STATUS_REG & 0x00000001) == 0x00000000);
    if (!(*RSP.SP_STATUS_REG & 0x00000002)) /* BROKE was not set. */
        message("Halted RSP CPU loop by means of MTC0.", 2);
    if (cycles == 0)
        message("w00t!11!  cycles_start - executed was 0 !!", 0);
    return (cycles_start - cycles); /* meant to be executed, minus remainder */
}

/*****************************************************************************/
static void rsp_get_context(void *dst)
{
    /* copy the context */
    if (dst)
        *(RSP_REGS *)dst = rsp;
}
static void rsp_set_context(void *src)
{
    /* copy the context */
    if (src)
        rsp = *(RSP_REGS *)src;
}

/******************************************************************************\
* Project:  MSP Emulation Table for Scalar Unit Operations                     *
* Authors:  Iconoclast                                                         *
* Release:  2013.08.18                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/
#ifndef _SU_H
#define _SU_H

/*
 * RSP virtual registers (of scalar unit)
 * The most important are the 32 general-purpose scalar registers.
 * We have the convenience of using a 32-bit machine (Win32) to emulate
 * another 32-bit machine (MIPS/N64), so the most natural way to accurately
 * emulate the scalar GPRs is to use the standard `int` type.  Situations
 * specifically requiring sign-extension or lack thereof are forcibly
 * applied as defined in the MIPS quick reference card and user manuals.
 * Remember that these are not the same "GPRs" as in the MIPS ISA and totally
 * abandon their designated purposes on the master CPU host (the VR4300),
 * hence most of the MIPS names "k0, k1, t0, t1, v0, v1 ..." no longer apply.
 */
static int SR[32];

/*
 * system control register indexing pointer table
 * This is particularly useful for directly executing MFC0.
 * MTC0 is too complicated to make regular use of this.
 * I cannot recreate as an array; they are engraved in zilmar plugin module.
 */
#if 0
static const unsigned long **CR[32] = {
    &RSP.SP_MEM_ADDR_REG,
    &RSP.SP_DRAM_ADDR_REG,
    &RSP.SP_RD_LEN_REG,
    &RSP.SP_WR_LEN_REG,
    &RSP.SP_STATUS_REG,
    &RSP.SP_DMA_FULL_REG,
    &RSP.SP_DMA_BUSY_REG,
    &RSP.SP_SEMAPHORE_REG, /* also "SP_RESERVED" */
    &RSP.DPC_START_REG,
    &RSP.DPC_END_REG,
    &RSP.DPC_CURRENT_REG,
    &RSP.DPC_STATUS_REG,
    &RSP.DPC_CLOCK_REG,
    &RSP.DPC_BUFBUSY_REG,
    &RSP.DPC_PIPEBUSY_REG,
    &RSP.DPC_TMEM_REG,
    NULL, /* Usually there are 32 scalar CPU control registers. */
    NULL, /* In fact, RSP assembler manual defines 32 indices, but lists 16. */
    NULL, /* Conflicting sources and undefined doc reference leave this gray. */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};
#endif

static void res_S(void)
{
    message("RESERVED", 3);
    return;
}

#include "cop0.h"
#include "cop2.h"
#include "lwc2.h"
#include "swc2.h"

union {
    struct {
        unsigned int func:  6;
        unsigned int sa:  5;
        unsigned int rd:  5;
        unsigned int rt:  5;
        unsigned int rs:  5;
        unsigned int op:  6;
    } R;
    struct {
        union {
            unsigned imm:  16;
            signed offset:  16;
        };
        unsigned int rt:  5;
        unsigned int rs:  5;
        unsigned int op:  6;
    } I;
    struct {
        unsigned int target:  26;
        unsigned int op:  6;
    } J;
    unsigned W:  32;
} inst;

/*** Scalar, Special Operations ***/
static void BREAK(void) /* 000000 ----- ----- ----- ----- 001101 */
{
    *RSP.SP_STATUS_REG |= 0x00000003; /* SP_STATUS_BROKE | SP_STATUS_HALT */
    if (*RSP.SP_STATUS_REG & 0x00000040)
    { /* SP_STATUS_INTR_BREAK */
        *RSP.MI_INTR_REG |= 0x00000001;
        RSP.CheckInterrupts();
        return;
    }
    return;
}

/*** Scalar, Jump and Branch Operations ***/
#if (0)
#define LINK_OFF    0x008
#else
#define LINK_OFF    0x004
#endif
INLINE void B(signed int off18) /* MIPS assembly idiom "Unconditional Branch" */
{
    if (SR[0] == SR[0])
    { /* B is a pseudo-op-code for `BEQ $0, $0, offset`:  "if (0 == 0)" */
        temp_PC = *RSP.SP_PC_REG + off18;
        inst.W = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
        *RSP.SP_PC_REG = temp_PC & 0x00000FFC;
    }
    return;
}
static void J(void) /* 000010 iiiiiiiiiiiiiiiiiiiiiiiiii */
{
    temp_PC = 4*inst.W;
    inst.W = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
    *RSP.SP_PC_REG = temp_PC & 0x00000FFC;
    return;
}
static void JAL(void) /* 000011 iiiiiiiiiiiiiiiiiiiiiiiiii */
{
    SR[31] = (*RSP.SP_PC_REG + LINK_OFF) & 0x00000FFC;
    J();
    return;
}
static void JR(void) /* 000000 sssss ----- ----- ----- 001000 */
{
    temp_PC = SR[inst.R.rs];
    inst.W = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
    *RSP.SP_PC_REG = temp_PC & 0x00000FFC;
    return;
}
static void JALR(void) /* 000000 sssss ----- ddddd ----- 001001 */
{
    SR[inst.R.rd] = (*RSP.SP_PC_REG + LINK_OFF) & 0x00000FFC;
    JR();
    return;
}
static void BEQ(void) /* 000100 sssss ttttt iiiiiiiiiiiiiiii */
{
    const int BC = (SR[inst.I.rs] == SR[inst.I.rt]);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BNE(void) /* 000101 sssss ttttt iiiiiiiiiiiiiiii */
{
    const int BC = (SR[inst.I.rs] != SR[inst.I.rt]);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BLEZ(void) /* 000110 sssss 00000 iiiiiiiiiiiiiiii */
{
    const int BC = ((signed)(SR[inst.I.rs]) <= 0);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BGTZ(void) /* 000111 sssss 00000 iiiiiiiiiiiiiiii */
{
    const int BC = ((signed)(SR[inst.I.rs])  > 0);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BLTZ(void) /* 000001 sssss 00000 iiiiiiiiiiiiiiii */
{
    const int BC = ((signed)(SR[inst.I.rs])  < 0);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BGEZ(void) /* 000001 sssss 00001 iiiiiiiiiiiiiiii */
{
    const int BC = ((signed)(SR[inst.I.rs]) >= 0);

    if (BC)
        B(4*inst.I.offset);
    return;
}
static void BLTZAL(void) /* 000001 sssss 10000 iiiiiiiiiiiiiiii */
{
    SR[31] = (*RSP.SP_PC_REG + LINK_OFF) & 0x00000FFC;
    BLTZ();
    return;
}
static void BGEZAL(void) /* 000001 sssss 10001 iiiiiiiiiiiiiiii */
{
    SR[31] = (*RSP.SP_PC_REG + LINK_OFF) & 0x00000FFC;
    BGEZ();
    return;
}

/*** Scalar, Shift Operations ***/
#if (0)
#define MASK_SA(sa) (sa & 31) /* Force masking in software. */
#else
#define MASK_SA(sa) (sa) /* Let hardware architecture do the mask for us. */
#endif
static void SLL(void) /* 000000 ----- ttttt ddddd aaaaa 000000 */
{
    SR[inst.R.rd] = SR[inst.R.rt] << MASK_SA(inst.W >> 6);
    return;
}
static void SRL(void) /* 000000 ----- ttttt ddddd aaaaa 000010 */
{
    SR[inst.R.rd] = (unsigned)(SR[inst.R.rt]) >> MASK_SA(inst.W >> 6);
    return;
}
static void SRA(void) /* 000000 ----- ttttt ddddd aaaaa 000011 */
{
    SR[inst.R.rd] = (signed)(SR[inst.R.rt]) >> MASK_SA(inst.W >> 6);
    return;
}
static void SLLV(void) /* 000000 sssss ttttt ddddd ----- 000100 */
{
    SR[inst.R.rd] = SR[inst.R.rt] << MASK_SA(SR[inst.W >> 21]);
    return;
}
static void SRLV(void) /* 000000 sssss ttttt ddddd ----- 000110 */
{
    SR[inst.R.rd] = (unsigned)(SR[inst.R.rt]) >> MASK_SA(SR[inst.W >> 21]);
    return;
}
static void SRAV(void) /* 000000 sssss ttttt ddddd ----- 000111 */
{
    SR[inst.R.rd] = (signed)(SR[inst.R.rt]) >> MASK_SA(SR[inst.W >> 21]);
    return;
}

/*** Scalar, Arithmetic and Logical Operations ***/
static void ADD(void) /* 000000 sssss ttttt ddddd ----- 100000 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] + SR[inst.R.rt];
    return;
} /* There is no overflow trap on the RSP.  Use ADDU. */
static void ADDI(void) /* 001000 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = SR[inst.I.rs] + inst.I.offset;
    return;
} /* There is no overflow trap on the RSP.  Use ADDIU. */
static void ADDIU(void) /* 001001 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = SR[inst.I.rs] + inst.I.offset;
    return;
}
static void ADDU(void) /* 000000 sssss ttttt ddddd ----- 100001 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] + SR[inst.R.rt];
    return;
}
static void SUB(void) /* 000000 sssss ttttt ddddd ----- 100010 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] - SR[inst.R.rt];
    return;
} /* There is no overflow trap on the RSP.  Use SUBU. */
static void SUBU(void) /* 000000 sssss ttttt ddddd ----- 100011 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] - SR[inst.R.rt];
    return;
}
static void SLT(void) /* 000000 sssss ttttt ddddd ----- 101010 */
{
    SR[inst.R.rd] = ((signed)(SR[inst.W >> 21]) < (signed)(SR[inst.R.rt]));
    return;
}
static void SLTI(void) /* 001010 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = ((signed)(SR[inst.I.rs]) < inst.I.offset);
    return;
}
static void SLTIU(void) /* 001011 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = ((unsigned)(SR[inst.I.rs]) < inst.I.imm);
    return;
}
static void SLTU(void) /* 000000 sssss ttttt ddddd ----- 101011 */
{
    SR[inst.R.rd] = ((unsigned)(SR[inst.W >> 21]) < (unsigned)(SR[inst.R.rt]));
    return;
}
static void AND(void) /* 000000 sssss ttttt ddddd ----- 100100 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] & SR[inst.R.rt];
    return;
}
static void OR(void) /* 000000 sssss ttttt ddddd ----- 100101 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] | SR[inst.R.rt];
    return;
}
static void XOR(void) /* 000000 sssss ttttt ddddd ----- 100110 */
{
    SR[inst.R.rd] = SR[inst.W >> 21] ^ SR[inst.R.rt];
    return;
}
static void NOR(void) /* 000000 sssss ttttt ddddd ----- 100111 */
{
    SR[inst.R.rd] = ~(SR[inst.W >> 21] | SR[inst.R.rt]);
    return;
}
static void ANDI(void) /* 001100 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = SR[inst.I.rs] & inst.I.imm;
    return;
}
static void ORI(void) /* 001101 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = SR[inst.I.rs] | inst.I.imm;
    return;
}
static void XORI(void) /* 001110 sssss ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = SR[inst.I.rs] & inst.I.imm;
    return;
}
static void LUI(void) /* 001111 ----- ttttt iiiiiiiiiiiiiiii */
{
    SR[inst.I.rt] = inst.I.imm << 16;
    return;
}

/*
 * All other behaviors defined below this point in the file are specific to
 * the SGI N64 extension to the MIPS R4000 and are not entirely implemented.
 */

/*** Scalar, Coprocessor Operations (system control) ***/
extern void SP_DMA_READ(void);
extern void SP_DMA_WRITE(void);
static void MFC0(void)
{
    const int rt = inst.R.rt;

    switch (inst.R.rd & 0xF)
    {
        case 0x0:
            SR[rt] = *RSP.SP_MEM_ADDR_REG;
            return;
        case 0x1:
            SR[rt] = *RSP.SP_DRAM_ADDR_REG;
            return;
        case 0x2: /* have not verified / been able to test yet ? */
            message("MFC0\nDMA_READ_LENGTH", 2);
            SR[rt] = *RSP.SP_RD_LEN_REG;
            return;
        case 0x3:
            message("MFC0\nDMA_WRITE_LENGTH", 3);
            return; /* dunno what to do, so error */
        case 0x4:
            SR[rt] = *RSP.SP_STATUS_REG;
#ifdef WAIT_FOR_CPU_HOST
            if (CFG_WAIT_FOR_CPU_HOST == 0)
                return;
            ++MFC0_count[rt];
            if (MFC0_count[rt] > 07)
                *RSP.SP_STATUS_REG |= 0x00000001; /* Let OS restart the task. */
#endif
            return;
        case 0x5: /* SR[rt] = !!(SP_STATUS_REG & SP_STATUS_DMAFULL) */
            SR[rt] = *RSP.SP_DMA_FULL_REG;
            return;
        case 0x6: /* SR[rt] = !!(SP_STATUS_REG & SP_STATUS_DMABUSY) */
            SR[rt] = *RSP.SP_DMA_BUSY_REG;
            return;
        case 0x7:
            SR[rt] = *RSP.SP_SEMAPHORE_REG;
#ifdef SEMAPHORE_LOCK_CORRECTIONS
            if (CFG_MEND_SEMAPHORE_LOCK == 0)
                return;
            *RSP.SP_SEMAPHORE_REG = 0x00000001;
            *RSP.SP_STATUS_REG |= 0x00000001; /* temporary bit to break CPU */
#endif
            return;
        case 0x8:
            SR[rt] = *RSP.DPC_START_REG;
            return;
        case 0x9:
            SR[rt] = *RSP.DPC_END_REG;
            return;
        case 0xA:
            SR[rt] = *RSP.DPC_CURRENT_REG;
            return;
        case 0xB:
            if (*RSP.DPC_STATUS_REG & 0x00000600) /* end/start valid ? */
                message("MFC0\nCMD_STATUS", 0); /* This is just CA-related. */
            SR[rt] = *RSP.DPC_STATUS_REG;
            return;
        case 0xC:
            SR[rt] = *RSP.DPC_CLOCK_REG;
            return;
        case 0xD:
            SR[rt] = *RSP.DPC_BUFBUSY_REG;
            return;
        case 0xE:
            SR[rt] = *RSP.DPC_PIPEBUSY_REG;
            return;
        case 0xF:
            SR[rt] = *RSP.DPC_TMEM_REG;
            return;
    }
}
static void MTC0(void)
{
    const int rt = inst.R.rt;

    switch (rd &= 0xF) /* exception override:  MAME r10933 (2010.12.31) */
    {
        case 0x0:
            *RSP.SP_MEM_ADDR_REG = SR[rt] & 0xFFFFFFF8;
            return; /* Reserved upper bits are filtered out on DMA R/W. */
        case 0x1: /* 24-bit RDRAM pointer */
            *RSP.SP_DRAM_ADDR_REG = SR[rt] & 0xFFFFFFF8;
            return; /* Again, we don't *yet* care about the reserved bits. */
        case 0x2:
            *RSP.SP_RD_LEN_REG = SR[rt] | 07;
            SP_DMA_READ();
            return;
        case 0x3:
            *RSP.SP_WR_LEN_REG = SR[rt] | 07;
            SP_DMA_WRITE();
            return;
        case 0x4:
            if (*RSP.SP_STATUS_REG & 0xFE000040)
                message("MTC0\nSP_STATUS", 2);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000001) <<  0);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000002) <<  0);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000004) <<  1);
            *RSP.MI_INTR_REG &= ~((SR[rt] & 0x00000008) >> 3); /* SP_CLR_INTR */
            *RSP.MI_INTR_REG |=  ((SR[rt] & 0x00000010) >> 4); /* SP_SET_INTR */
            *RSP.SP_STATUS_REG |= (SR[rt] & 0x00000010) >> 4; /* int set halt */
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000020) <<  5);
         /* *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000040) <<  5); */
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000080) <<  6);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000100) <<  6);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000200) <<  7);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000400) <<  7);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000800) <<  8);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00001000) <<  8);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00002000) <<  9);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00004000) <<  9);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00008000) << 10);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00010000) << 10);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00020000) << 11);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00040000) << 11);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00080000) << 12);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00100000) << 12);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00200000) << 13);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00400000) << 13);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00800000) << 14);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x01000000) << 14);
            return;
        case 0x5: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nDMA_FULL", 1);
            return;
        case 0x6: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nDMA_BUSY", 1);
            return;
        case 0x7:
            *RSP.SP_SEMAPHORE_REG = 0x00000000; /* Forced (zilmar + dox). */
            return;
        case 0x8:
            if (*RSP.DPC_BUFBUSY_REG) /* lock hazards not implemented */
                message("MTC0\nCMD_START", 0);
            *RSP.DPC_START_REG   = SR[rt] & ~07; /* Funnelcube demo--marshall */
            *RSP.DPC_CURRENT_REG = *RSP.DPC_START_REG;
            *RSP.DPC_END_REG     = *RSP.DPC_START_REG;
            return;
        case 0x9:
            if (*RSP.DPC_BUFBUSY_REG)
                message("MTC0\nCMD_END", 0); /* This is just CA-related. */
            *RSP.DPC_END_REG = SR[rt] & 0xFFFFFFF8;
            if (RSP.ProcessRdpList == NULL) /* zilmar GFX #1.2 */
                return;
            RSP.ProcessRdpList();
            return;
        case 0xA: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_CURRENT", 1);
            return;
        case 0xB:
            if (SR[rt] & 0xFFFFFD80) /* unsupported or reserved bits */
                message("MTC0\nCMD_STATUS", 2);
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000001) << 0);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000002) << 0);
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000004) << 1);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000008) << 1);
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000010) << 2);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000020) << 2);
/* Some NUS-CIC-6105 SP tasks try to clear some zeroed DPC registers. */
            *RSP.DPC_TMEM_REG     &= !(SR[rt] & 0x00000040) * -1;
         /* *RSP.DPC_PIPEBUSY_REG &= !(SR[rt] & 0x00000080) * -1; */
         /* *RSP.DPC_BUFBUSY_REG  &= !(SR[rt] & 0x00000100) * -1; */
            *RSP.DPC_CLOCK_REG    &= !(SR[rt] & 0x00000200) * -1;
            return;
        case 0xC:
            message("MTC0\nCMD_CLOCK", 1);
            *RSP.DPC_CLOCK_REG = SR[rt];
            return; /* Doc appendix says this is RW; elsewhere it says R. */
        case 0xD: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_BUSY", 2);
            return;
        case 0xE: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_PIPE_BUSY", 2);
            return;
        case 0xF: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_TMEM_BUSY", 2);
            return;
    }
}
void SP_DMA_READ(void)
{
    register unsigned int length;
    register unsigned int count;
    register unsigned int skip;

    length = (*RSP.SP_RD_LEN_REG & 0x00000FFF) >>  0;
    count  = (*RSP.SP_RD_LEN_REG & 0x000FF000) >> 12;
    skip   = (*RSP.SP_RD_LEN_REG & 0xFFF00000) >> 20;
    /* length |= 07; // already corrected by mtc0 */
    ++length;
    ++count;
    skip += length;
    do
    { /* `count` always starts > 0, so we begin with `do` instead of `while`. */
        unsigned int offC, offD; /* SP cache and dynamic DMA pointers */
        register unsigned int i = 0;

        --count;
        do
        {
            offC = (count*length + *RSP.SP_MEM_ADDR_REG + i) & 0x00001FF8;
            offD = (count*skip + *RSP.SP_DRAM_ADDR_REG + i) & 0x00FFFFF8;
            memcpy(RSP.DMEM + offC, RSP.RDRAM + offD, 8);
            i += 0x008;
        } while (i < length);
    } while (count);
    *RSP.SP_DMA_BUSY_REG = 0x00000000;
    *RSP.SP_STATUS_REG &= ~0x00000004; /* SP_STATUS_DMABUSY */
}
void SP_DMA_WRITE(void)
{
    register unsigned int length;
    register unsigned int count;
    register unsigned int skip;

    length = (*RSP.SP_WR_LEN_REG & 0x00000FFF) >>  0;
    count  = (*RSP.SP_WR_LEN_REG & 0x000FF000) >> 12;
    skip   = (*RSP.SP_WR_LEN_REG & 0xFFF00000) >> 20;
    /* length |= 07; // already corrected by mtc0 */
    ++length;
    ++count;
    skip += length;
    do
    { /* `count` always starts > 0, so we begin with `do` instead of `while`. */
        unsigned int offC, offD; /* SP cache and dynamic DMA pointers */
        register unsigned int i = 0;

        --count;
        do
        {
            offC = (count*length + *RSP.SP_MEM_ADDR_REG + i) & 0x00001FF8;
            offD = (count*skip + *RSP.SP_DRAM_ADDR_REG + i) & 0x00FFFFF8;
            memcpy(RSP.RDRAM + offD, RSP.DMEM + offC, 8);
            i += 0x000008;
        } while (i < length);
    } while (count);
    *RSP.SP_DMA_BUSY_REG = 0x00000000;
    *RSP.SP_STATUS_REG &= ~0x00000004; /* SP_STATUS_DMABUSY */
}

/*** Scalar, Coprocessor Operations (vector unit) ***/
extern static short VR[32][8];
#define VR_B(v, e) (*(unsigned char *)(((unsigned char *)(VR+v)) + MES(e))
#define VR_S(v, e) (*(short *)((unsigned char *)(*(VR + v)) + ((e + 01) & ~01)))
// to-do:  check this stupid thing for (unsigned char *)(VR+v) like above?
static void MFC2(void)
{
    const int rt = inst.R.rt;
    const int vd = inst.R.rd;
    const int e = inst.R.sa >> 1;

    if (e == 0xF)
        goto WRAP; /* Various games do this, actually. */
    SR[rt] = VR_S(vd, e);
    SR[rt] = (signed short)(SR[rt]);
    return;
WRAP:
/////// to-do:  test SR_B for non-shifted byte masks
    SR[rt] = (VR_B(vd, 0xF) << 8) | VR_B(vd, 0x0);
    SR[rt] = (signed short)(SR[rt]);
    return;
}
static void MTC2(void)
{
    const int rt = inst.R.rt;
    const int vd = inst.R.rd;
    const int e = inst.R.sa >> 1;

    VR_S(vd, e) = (short)(SR[rt]);
    return; /* If element == 0xF, it does not matter; loads do not wrap over. */
}
static void CFC2(void)
{
    if (inst.R.rd & 2)
    {
        message("CFC2\nVCE", 1);
        SR[inst.R.rt] = VCE; /* This transfer is not sign-extended. */
        return;
    }
    SR[inst.R.rt] = *(signed short *)vCR[inst.R.rd & 1];
    return;
}
static void CTC2(void)
{
    if (inst.R.rd & 2)
    {
        message("CTC2\nVCE", 1);
        VCE = (unsigned char)SR[inst.R.rt];
        return;
    }
    *vCR[inst.R.rd & 1] = (short)SR[inst.R.rt];
    return;
}

/*** Scalar, Coprocessor Operations (vector unit, scalar cache transfers) ***/
/*
 * This shit is going to be a pain in the ass to re-do.
 * l8z!
 */

static void (*EX_SCALAR[64][64])(void) = {
    { /* SPECIAL */
        SLL    ,res_S  ,SRL    ,SRA    ,SLLV   ,res_S  ,SRLV   ,SRAV   ,
        JR     ,JALR   ,res_S  ,res_S  ,res_S  ,BREAK  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        ADD    ,ADDU   ,SUB    ,SUBU   ,AND    ,OR     ,XOR    ,NOR    ,
        res_S  ,res_S  ,SLT    ,SLTU   ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* REGIMM */
        BLTZ   ,BGEZ   ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        BLTZAL ,BGEZAL ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
/* hazard reaction barrier -- rt only covers 32 sub-op-codes, not 64. */
        BLTZ   ,BGEZ   ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        BLTZAL ,BGEZAL ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* Jump */
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J      ,
        J      ,J      ,J      ,J      ,J      ,J      ,J      ,J
    },
    { /* Jump and Link */
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,
        JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL    ,JAL
    },
    { /* Branch on Equal */
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,
        BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ    ,BEQ
    },
    { /* Branch on Not Equal */
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,
        BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE    ,BNE
    },
    { /* Branch on Less Than or Equal to Zero */
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,
        BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ   ,BLEZ
    },
    { /* Branch on Greater Than Zero */
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,
        BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ   ,BGTZ
    },
    { /* Add Immediate Word */
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,
        ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI   ,ADDI
    },
    { /* Add Immediate Unsigned Word */
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,
        ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU  ,ADDIU
    }, /* Note:  Because the RSP is free of exception-handling, ADDI = ADDIU. */
    { /* Set on Less Than Immediate */
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,
        SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI   ,SLTI
    },
    { /* Set on Less Than Immediate Unsigned */
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,
        SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU  ,SLTIU
    },
    { /* And Immediate */
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,
        ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI   ,ANDI
    },
    { /* Or Immediate */
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,
        ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI    ,ORI
    },
    { /* Exclusive Or Immediate */
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,
        XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI   ,XORI
    },
    { /* Load Upper Immediate */
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,
        LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI    ,LUI
    },
    { /* COP0 */
        MFC0   ,res_S  ,res_S  ,res_S  ,MTC0   ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
/* hazard reaction barrier -- rs only covers 32 sub-op-codes, not 64. */
        MFC0   ,res_S  ,res_S  ,res_S  ,MTC0   ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* COP2 */
        MFC2   ,res_S  ,CFC2   ,res_S  ,MTC2   ,res_S  ,CTC2   ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,
        C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,
/* hazard reaction barrier -- rs only covers 32 sub-op-codes, not 64. */
        MFC2   ,res_S  ,CFC2   ,res_S  ,MTC2   ,res_S  ,CTC2   ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,
        C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2     ,C2
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* Load Byte */
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,
        LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB     ,LB
    },
    { /* Load Halfword */
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,
        LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH     ,LH
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* Load Word */
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,
        LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW     ,LW
    },
    { /* Load Byte Unsigned */
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,
        LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU    ,LBU
    },
    { /* Load Halfword Unsigned */
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,
        LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU    ,LHU
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* Store Byte */
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,
        SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB     ,SB
    },
    { /* Store Halfword */
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,
        SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH     ,SH
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* Store Word */
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,
        SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW     ,SW
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* LWC2 */
        LBV    ,LSV    ,LLV    ,LDV    ,LQV    ,LRV    ,LPV    ,LUV    ,
        LHV    ,LFV    ,res_S  ,LTV    ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
/* hazard reaction barrier -- rd only covers 32 sub-op-codes, not 64. */
        LBV    ,LSV    ,LLV    ,LDV    ,LQV    ,LRV    ,LPV    ,LUV    ,
        LHV    ,LFV    ,res_S  ,LTV    ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* SWC2 */
        SBV    ,SSV    ,SLV    ,SDV    ,SQV    ,SRV    ,SPV    ,SUV    ,
        SHV    ,SFV    ,SWV    ,STV    ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
/* hazard reaction barrier -- rd only covers 32 sub-op-codes, not 64. */
        SBV    ,SSV    ,SLV    ,SDV    ,SQV    ,SRV    ,SPV    ,SUV    ,
        SHV    ,SFV    ,SWV    ,STV    ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    },
    { /* illegal */
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,
        res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S  ,res_S
    }
};

#endif

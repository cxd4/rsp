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

static const void res_S(void)
{
    message("RESERVED", 3);
    return;
}

#include "cop0.h"
#include "cop2.h"
#include "lwc2.h"
#include "swc2.h"

static const void (*EX_SCALAR[64][64])(void) = {
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

/******************************************************************************\
* Project:  MSP Emulation Table for Scalar Unit Operations                     *
* Authors:  Iconoclast                                                         *
* Release:  2013.01.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/
#ifndef _SU_H
#define _SU_H

void res(int rs, int rt, short imm)
{
    rt = rs = 0;
    imm = 0x0000;
    message("PRIMARY\nRESERVED", 3);
    return;
}

#include "addi.h"
#include "addiu.h"
#include "andi.h"
#include "beq.h"
#include "bgtz.h"
#include "blez.h"
#include "bne.h"
#include "cop0.h"
#include "cop2.h"
#include "j.h"
#include "jal.h"
#include "lb.h"
#include "lbu.h"
#include "lh.h"
#include "lhu.h"
#include "lui.h"
#include "lw.h"
#include "lwc2.h"
#include "ori.h"
#include "regimm.h"
#include "sb.h"
#include "sh.h"
#include "slti.h"
#include "sltiu.h"
#include "special.h"
#include "sw.h"
#include "swc2.h"
#include "xori.h"

static void (*SP_PRIMARY[64])(int, int, short) = {
    SPECIAL,REGIMM ,J      ,JAL    ,BEQ    ,BNE    ,BLEZ   ,BGTZ   , /* 000 */
    ADDI   ,ADDIU  ,SLTI   ,SLTIU  ,ANDI   ,ORI    ,XORI   ,LUI    , /* 001 */
    COP0   ,res    ,COP2   ,res    ,res    ,res    ,res    ,res    , /* 010 */
    res    ,res    ,res    ,res    ,res    ,res    ,res    ,res    , /* 011 */
    LB     ,LH     ,res    ,LW     ,LBU    ,LHU    ,res    ,res    , /* 100 */
    SB     ,SH     ,res    ,SW     ,res    ,res    ,res    ,res    , /* 101 */
    res    ,res    ,LWC2   ,res    ,res    ,res    ,res    ,res    , /* 110 */
    res    ,res    ,SWC2   ,res    ,res    ,res    ,res    ,res      /* 111 */
}; /* 000     001     010     011     100     101     110     111 */

/* The op-code matrix implemented here favors the Nintendo 64 RSP.
 * A superset of this matrix for other signal processors includes MULT, etc.
 * This more fundamental instance is a subset of MIPS family revision 4000.
 */

#endif

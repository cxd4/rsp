/******************************************************************************\
* Project:  MSP Emulation Table for System Control Coprocessor Operations      *
* Creator:  Iconoclast                                                         *
* Release:  2013.01.17                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#include "mfc0.h"
#include "mtc0.h"

void res_020(int rt, int rd)
{
    message("COP0", 3);
    SR[rt] = 0x00000000;
    /* CPR[rd] = 0x00000000; // CPR file embedded in zilmar plugin specs */
    rd = 0; /* Besides, some CP0 regs are read-only, so, be lazy. */
    return;
}

static void (*SP_COP0[32])(int, int) = {
    MFC0   ,res_020,res_020,res_020,MTC0   ,res_020,res_020,res_020, /* 00 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020, /* 01 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020, /* 10 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020  /* 11 */
}; /* 000     001     010     011     100     101     110     111 */

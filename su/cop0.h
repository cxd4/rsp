/******************************************************************************\
* Project:  MSP Emulation Table for System Control Coprocessor Operations      *
* Creator:  Iconoclast                                                         *
* Release:  2013.03.09                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

extern void MFC0(int rt, int cr);
extern void MTC0(int rt, int cr);

#include "cop0/mfc0.h"
#include "cop0/mtc0.h"

void res_020(int rt, int rd)
{
    rd = rt = 0;
    message("COP0\nRESERVED", 3);
    return;
}

static void (*SP_COP0[32])(int, int) = {
    MFC0   ,res_020,res_020,res_020,MTC0   ,res_020,res_020,res_020, /* 00 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020, /* 01 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020, /* 10 */
    res_020,res_020,res_020,res_020,res_020,res_020,res_020,res_020  /* 11 */
}; /* 000     001     010     011     100     101     110     111 */

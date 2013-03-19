/******************************************************************************\
* Project:  MSP Emulation Table for Vector Unit Coprocessor Operations (COP2)  *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

extern void CFC2(int rt, int vcr, int unused);
extern void CTC2(int rt, int vcr, int unused);
extern void MFC2(int rt, int vd, int element);
extern void MTC2(int rt, int vd, int element);

#include "cop2/mfc2.h"
#include "cop2/cfc2.h"
#include "cop2/mtc2.h"
#include "cop2/ctc2.h"

void res_022(int rt, int rd, int element)
{
    element = rd = rt = 0;
    message("COP2\nRESERVED", 3);
    return;
}

static void (*SP_COP2[32])(int, int, int) = {
    MFC2   ,res_022,CFC2   ,res_022,MTC2   ,res_022,CTC2   ,res_022, /* 00 */
    res_022,res_022,res_022,res_022,res_022,res_022,res_022,res_022, /* 01 */
    res_022,res_022,res_022,res_022,res_022,res_022,res_022,res_022, /* 10 */
    res_022,res_022,res_022,res_022,res_022,res_022,res_022,res_022  /* 11 */
}; /* 000     001     010     011     100     101     110     111 */

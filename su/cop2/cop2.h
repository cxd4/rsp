/******************************************************************************\
* Project:  RSP Emulation Table for Vector Unit Coprocessor Operations (COP2)  *
* Creator:  R. J. Swedlow                                                      *
* Release:  2013.01.11                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#include "mfc2.h"
#include "cfc2.h"
#include "mtc2.h"
#include "ctc2.h"

extern void MFC2(int rt, int vd, int element);
extern void CFC2(int rt, int vd, int unused);
extern void MTC2(int rt, int vd, int element);
extern void CTC2(int rt, int vd, int unused);

void res_022(int unused_rt, int unused_rd, int unused)
{
    SR[unused_rt] = 0x00000000;
    VCF[unused_rd] = 0x0000;
    VR[unused_rd].b[unused ^ 01] = 0x00;
    ++unused;
    unused &= 0xF;
    VR[unused_rd].b[unused ^ 01] = 0x00;
    message("COP2", 3);
    return;
}

static void (*SP_COP2[32])(int, int, int) = {
    MFC2,
    res_022,
    CFC2,
    res_022,
    MTC2,
    res_022,
    CTC2,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022, /* Denoted in Project Unreality as "VECTOP", but not part of SU. */
    res_022, /* The only VU instructions are these effective sub-opcodes. */
    res_022, /* To be accurate I have split the VU emulation from the SU. */
    res_022, /* Look after the emulation of the RD processor phase to see VU. */
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022,
    res_022
};

#include "vu.h"

/*
 * Note about VMACQ.
 *
 * Current implementation of VMACQ is experimental.
 * It is the surviving op-code of the MPEG-DCT-designated RSP circutries.
 * As such, for it to not be omitted, it is heavily modified from the actual.
 *
 * It was changed into this newer, archaic algorithm on the hardware.
 * Could not find any games using VMACQ, so I gave up waiting for an error
 * complaining to me that I should implement it.  The below algorithm is in
 * conformance to the suggested, explained mode of operation.
 */

static void VMACQ(int vd, int vs, int vt, int e)
{
    vt = vs = 0; /* ignored inputs */
    message("VMACQ", 1); /* untested, any N64 ROMs use this?? */
    for (e = 0; e < 8; e++)
        if (VACC[e].DW & (32 << 16)) /* Bit 21 of acc must be nonzero. */
            continue; /* VACC[e].DW += 0x000000000000; */
        else
            VACC[e].DW += (VACC[e].DW & 0x800000000000) ? +32 << 16 : -32 << 16;
    for (e = 0; e < 8; e++) /* Sign-extend 48-bit to 64-bit supersets. */
        VACC[e].HW[03] = VACC[e].s[HI] >> 15;
    for (e = 0; e < 8; e++) /* Sign-clamp bits 32..17 of ACC to dest. VR. */
        if (CLAMP_BASE(e, 17) < -32768)
            VR[vd][e] = -32768 & ~0x000F; /* element underflow */
        else if (CLAMP_BASE(e, 17) > +32767)
            VR[vd][e] = +32767 & ~0x000F; /* element overflow */
        else
            VR[vd][e] = CLAMP_BASE(e, 17) & 0x0000FFF0;
    return;
}

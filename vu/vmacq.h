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
    register int i;

    vt = vs = 0; /* ignored inputs */
    message("VMACQ", 1); /* untested, any N64 ROMs use this?? */
    for (i = 0; i < 8; i++)
        if (VACC[i].DW & (32 << 16)) /* Bit 21 of acc must be nonzero. */
            VACC[i].DW += 0x000000000000;
        else
            VACC[i].DW += (VACC[i].DW & 0x800000000000) ? +32 << 16 : -32 << 16;
    for (i = 0; i < 8; i++)
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if ((VACC[i].DW & 0xFFFF00000000) != 0xFFFF00000000)
                VR[vd][i] = 0x8000 & ~0x000F;
            else
                VR[vd][i] = (short)(VACC[i].DW >> 17) & ~0x000F;
        else
            if ((VACC[i].DW & 0xFFFF00000000) != 0x000000000000)
                VR[vd][i] = 0x7FFF & ~0x000F;
            else
                VR[vd][i] = (short)(VACC[i].DW >> 17) & ~0x000F;
    return;
}

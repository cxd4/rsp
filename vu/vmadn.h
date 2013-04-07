#include "vu.h"

static void VMADN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        if (CLAMP_BASE(i, 16) < -32768)
            VR[vd][i] = 0x0000; /* element underflow */
        else if (CLAMP_BASE(i, 16) > +32767)
            VR[vd][i] = 0xFFFF; /* element overflow */
        else
            VR[vd][i] = VACC[i].DW & 0x00000000FFFF;
    return;
}

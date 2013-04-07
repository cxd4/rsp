#include "vu.h"

static void VMADH(int vd, int vs, int vt, int e)
{
    register signed long long product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = VR[vs][i]*VR[vt][ei[e][i]];
        VACC[i].DW += product << 16;
    }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (CLAMP_BASE(i, 16) < -32768)
            VR[vd][i] = -32768; /* element underflow */
        else if (CLAMP_BASE(i, 16) > +32767)
            VR[vd][i] = +32767; /* element overflow */
        else
            VR[vd][i] = CLAMP_BASE(i, 16) & 0x0000FFFF;
    return;
}

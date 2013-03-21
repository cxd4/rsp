#include "vu.h"

static void VMULU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (VR[vs][i]*VR[vt][ei[e][i]] << 1) + 0x8000;
    for (i = 0; i < 8; i++) /* Unsigned-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW < 0)
            VR[vd][i] = 0x0000; /* unsigned underflow */
        else if (VACC[i].W[0] == 0x80008000) /* only reachable overflow value */
            VR[vd][i] = 0xFFFF;
        else
            VR[vd][i] = VACC[i].s[MD];
    return;
}

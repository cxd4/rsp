#include "vu.h"

static void VMULU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (VR[vs][i]*VR[vt][ei[e][i]] << 1) + 0x8000;
    for (i = 0; i < 8; i++) /* Unsign-clamp bits 31..16 of ACC to dest. VR. */
    {
        VR[vd][i] = VACC[i].s[MD];
        VR[vd][i] |= VR[vd][i] >> 15; /* VD |= -1 * (ACC > 0x00007FFFFFFF); */
        VR[vd][i] &= ~VACC[i].s[HI]; /* VD = (ACC < 0) ? 0 : ACC[31..16]; */
    }
    return;
}

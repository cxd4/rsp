#include "vu.h"

static void VMUDN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (unsigned short)VR[vs][i] * VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++) /* Signed-clamp bits 15..0 of ACC to dest. VR. */
        VR[vd][i] = VACC[i].s[LO]; /* No arithmetic checks needed. */
    return;
}

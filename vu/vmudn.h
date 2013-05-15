#include "vu.h"

static void VMUDN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (unsigned short)VR[vs][i] * VR_T(i);
    for (i = 0; i < 8; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        VR_D(i) = VACC[i].s[LO]; /* No arithmetic checks needed. */
    return;
}

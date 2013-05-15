#include "vu.h"

static void VMUDM(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = VR[vs][i] * (unsigned short)VR_T(i);
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        VR_D(i) = VACC[i].s[MD]; /* No saturate checks needed. */
    return;
}

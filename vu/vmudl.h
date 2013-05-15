#include "vu.h"

static void VMUDL(int vd, int vs, int vt, int e)
{
    register unsigned int product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = (unsigned short)VR[vs][i] * (unsigned short)VR_T(i);
        VACC[i].DW = product >> 16;
    }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        VR_D(i) = VACC[i].s[LO]; /* No arithmetic checks needed. */
    return;
}

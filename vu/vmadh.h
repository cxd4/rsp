#include "vu.h"

static void VMADH(int vd, int vs, int vt, int e)
{
    register signed long long product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = VR[vs][i] * VR_T(i);
        VACC[i].DW += product << 16;
    }
    SIGNED_CLAMP(vd, 0);
    return;
}

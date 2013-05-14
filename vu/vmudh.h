#include "vu.h"

static void VMUDH(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
    {
        VACC[i].DW = VR[vs][i] * VR_T(i);
        VACC[i].DW <<= 16;
    }
    SIGNED_CLAMP(vd, 0);
    return;
}

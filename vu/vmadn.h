#include "vu.h"

static void VMADN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += (unsigned short)VR[vs][i] * VR_T(i);
    SIGNED_CLAMP(vd, 1);
}

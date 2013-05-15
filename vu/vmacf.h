#include "vu.h"

static void VMACF(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += VR[vs][i]*VR_T(i) << 1;
    SIGNED_CLAMP(VMUL_PTR, 0);
    return;
}

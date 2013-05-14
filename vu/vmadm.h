#include "vu.h"

static void VMADM(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += VR[vs][i] * (unsigned short)VR_T(i);
    SIGNED_CLAMP(vd, 0);
    return;
}

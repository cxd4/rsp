#include "vu.h"

static void VMADL(int vd, int vs, int vt, int e)
{
    register unsigned int product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = (unsigned short)VR[vs][i] * (unsigned short)VR_T(i);
        VACC[i].DW += product >> 16;
    }
    SIGNED_CLAMP(vd, 1);
    return;
}

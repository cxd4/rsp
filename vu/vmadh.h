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
#ifdef EMULATE_VECTOR_RESULT_BUFFER
    SIGNED_CLAMP(Result, 0);
#else
    SIGNED_CLAMP(VR[vd], 0);
#endif
    return;
}

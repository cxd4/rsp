#include "vu.h"

INLINE static void set_bo(short* VD, short* VS, short* VT)
{ /* set CARRY and borrow out from difference */
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VS[i] - VT[i];
    vector_copy(VD, VACC_L);
    for (i = 0; i < N; i++)
        ne[i] = (VS[i] != VT[i]);
    for (i = 0; i < N; i++)
        co[i] = ((unsigned short)VS[i] < (unsigned short)VT[i]);
    return;
}

static void VSUBC(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    set_bo(VR[vd], VR[vs], ST);
    return;
}

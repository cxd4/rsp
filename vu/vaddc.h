#include "vu.h"

INLINE static void set_co(short* VD, short* VS, short* VT)
{ /* set CARRY and carry out from sum */
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VS[i] + VT[i];
    vector_copy(VD, VACC_L);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = ((unsigned short)VS[i] + (unsigned short)VT[i]) >> 16;
    return;
}

static void VADDC(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    set_co(VR[vd], VR[vs], ST);
    return;
}

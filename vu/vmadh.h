#include "vu.h"

INLINE static void do_madh(short* VD, short* VS, short* VT)
{
    long product[N];
    unsigned long addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = (signed short)(VS[i]) * (signed short)(VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + (unsigned short)(product[i]);
    for (i = 0; i < N; i++)
        VACC_M[i] += (short)(VS[i] * VT[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] += (addend[i] >> 16) + (product[i] >> 16);
    SIGNED_CLAMP_AM(VD);
    return;
}

static void VMADH(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_madh(VR[vd], VR[vs], ST);
    return;
}

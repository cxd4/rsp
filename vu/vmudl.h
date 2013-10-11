#include "vu.h"

INLINE static void do_mudl(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = (unsigned short)(VS[i])*(unsigned short)(VT[i]) >> 16;
    for (i = 0; i < N; i++)
        VACC_M[i] = 0x0000;
    for (i = 0; i < N; i++)
        VACC_H[i] = 0x0000;
    vector_copy(VD, VACC_L); /* no possibilities to clamp */
    return;
}

static void VMUDL(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mudl(VR[vd], VR[vs], ST);
    return;
}

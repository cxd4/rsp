#include "vu.h"

INLINE static void do_mrg(short* VD, short* VS, short* VT)
{
    merge(VACC_L, comp, VS, VT);
    vector_copy(VD, VACC_L);
    return;
}

static void VMRG(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mrg(VR[vd], VR[vs], ST);
    return;
}

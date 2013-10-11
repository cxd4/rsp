#include "vu.h"

static void VMOV(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;

    vector_copy(VACC_L, ST);
    VR[vd][de] = VACC_L[inst.R.rs & 07];
    return;
}

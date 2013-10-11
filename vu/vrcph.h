#include "vu.h"
#include "divrom.h"

static void VRCPH(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][inst.R.rs & 07] << 16;
    vector_copy(VACC_L, ST);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

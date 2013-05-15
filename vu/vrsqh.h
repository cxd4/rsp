#include "vu.h"
#include "divrom.h"

static void VRSQH(int vd, int de, int vt, int e)
{
    register int i;

    DivIn = VR[vt][e & 07] << 16;
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VR_T(i);
    VR_D(de &= 07) = DivOut >> 16; /* store high part */
    DPH = 1;
    return;
}

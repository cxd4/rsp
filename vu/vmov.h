#include "vu.h"

static void VMOV(int vd, int de, int vt, int e)
{
    register int i;

    /* MovIn = (int)VR[vt][e & 07]; */
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VR[vt][ei[e][i]];
    VR[vd][de &= 07] = VACC[de].s[LO];
    return;
}

#include "vu.h"

static void VMOV(int vd, int de, int vt, int e)
{
    register int i;
#if (0)
    MovIn = (int)VR[vt][e & 07];
#endif
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VR_T(i);
    de &= 07;
    VR_D(de) = VACC[de].s[LO];
    return;
}

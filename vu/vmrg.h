#include "vu.h"

static void VMRG(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VCC & (0x0001 << i) ? VR[vs][i] : VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

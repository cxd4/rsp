#include "vu.h"

static void VXOR(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VR[vs][i] ^ VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

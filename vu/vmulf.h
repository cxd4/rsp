#include "vu.h"

static void VMULF(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (VR[vs][i]*VR_T(i) << 1) + 0x8000;
    for (i = 0; i < 8; i++) /* Only one reachable value can expose overflow. */
        VR[vd][i] = VACC[i].s[MD] + (signed short)(VACC[i].s[MD] >> 15);
    return;
}

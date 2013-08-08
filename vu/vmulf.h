#include "vu.h"

static void VMULF(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW = (VR[vs][i]*VR_T(i) << 1) + 0x8000;
    for (i = 0; i < 8; i++)
        VR_D(i) = VACC[i].s[MD];
    for (i = 0; i < 8; i++) /* Only one reachable value can expose overflow. */
        VR_D(i) -= !!(VR_D(i) & 0x8000);
    return;
}

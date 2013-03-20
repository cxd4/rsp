#include "vu.h"

static void VMULF(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].DW = (VR[vs][i]*VR[vt][j = i] << 1) + 0x8000;
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
            VACC[i].DW = (VR[vs][i]*VR[vt][j | (i & 0xE)] << 1) + 0x8000;
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
            VACC[i].DW = (VR[vs][i]*VR[vt][j | (i & 0xC)] << 1) + 0x8000;
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].DW = (VR[vs][i]*VR[vt][j] << 1) + 0x8000;
    for (i = 0; i < 8; i++) /* Only one reachable value can expose overflow. */
        VR[vd][i] = VACC[i].s[MD] - (VACC[i].W[0] == 0x80008000);
    return;
}

#include "vu.h"

void VMOV(int vd, int de, int vt, int e)
{
    register int i, j;

    de &= 07;
    if (e == 0x0) /* (e == 1) was already filtered. */
        for (i = 0, j = 0; i < 8; j = ++i)
            VACC[i].s[LO] = VR[vt].s[j];
    else if (e < 4)
        for (i = 0, j = e & 01; i < 8; i++, j |= i & 0xE)
            VACC[i].s[LO] = VR[vt].s[j];
    else if (e < 8)
        for (i = 0, j = e & 03; i < 8; i++, j |= i & 0xC)
            VACC[i].s[LO] = VR[vt].s[j];
    else /* if (8 <= e <= 15) */
        for (i = 0, j = e & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j];
    VR[vd].s[de] = VACC[de].s[LO];
    return;
}

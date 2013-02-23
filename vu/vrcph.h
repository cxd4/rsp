#include "vu.h"
#include "divrom.h"

static const void VRCPH(int vd, int del, int vt, int e)
{
    register int i, j;

    DivIn = VR[vt].s[e & 07] << 16;
    if (!e)
        for (i = 0; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j = i];
    else if (e < 4) /* e != 1 */
        for (i = 0, j = e & 01; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j | (i & 0xE)];
    else if (e < 8)
        for (i = 0, j = e & 03; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j | (i & 0xC)];
    else /* if (8 <= e <= 15) */
        for (i = 0, j = e & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j];
    del &= 07;
    VR[vd].s[del] = DivOut >> 16; /* store high part */
    DPH = 1;
    return;
}

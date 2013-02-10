#include "vu.h"

void VRCPH(int vd, int del, int vt, int element)
{
    register int i, j;
    register int sel = element & 07; // sel  = element_index[element][del];

    rsp.reciprocal_high = VR[vt].s[sel];
    del &= 07;
    if (element == 0x0) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[i];
    else if ((element & 0xE) == 02) /* scalar quarter */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            VACC[i].s[LO] = VR[vt].s[j];
        }
    else if ((element & 0xC) == 04) /* scalar half */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            VACC[i].s[LO] = VR[vt].s[j];
        }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j];
    VR[vd].s[del] = rsp.reciprocal_res >> 16; /* store high part */
    return;
}

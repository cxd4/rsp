#include "vu.h"

void VMUDM(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].DW = VR[vs].s[i] * (unsigned short)VR[vt].s[j = i];
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
            VACC[i].DW = VR[vs].s[i] * (unsigned short)VR[vt].s[j | (i & 0xE)];
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
            VACC[i].DW = VR[vs].s[i] * (unsigned short)VR[vt].s[j | (i & 0xC)];
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].DW = VR[vs].s[i] * (unsigned short)VR[vt].s[j];
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        VR[vd].s[i] = VACC[i].s[MD]; /* No saturate checks needed. */
    return;
}

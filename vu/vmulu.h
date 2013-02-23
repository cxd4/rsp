#include "vu.h"

static const void VMULU(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].DW = (VR[vs].s[i]*VR[vt].s[j = i] << 1) + 0x8000;
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
            VACC[i].DW = (VR[vs].s[i]*VR[vt].s[j | (i & 0xE)] << 1) + 0x8000;
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
            VACC[i].DW = (VR[vs].s[i]*VR[vt].s[j | (i & 0xC)] << 1) + 0x8000;
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].DW = (VR[vs].s[i]*VR[vt].s[j] << 1) + 0x8000;
    for (i = 0; i < 8; i++) /* Unsigned-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW < 0)
            VR[vd].s[i] = 0x0000; /* unsigned underflow */
        else if (VACC[i].DW == 0x000080008000) /* short overflow */
            VR[vd].s[i] = 0xFFFF;
        else
            VR[vd].s[i] = VACC[i].s[MD];
    return;
}

#include "vu.h"

void VMUDH(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            VACC[i].DW = VR[vs].s[i] * VR[vt].s[j = i];
            VACC[i].DW <<= 16;
        }
    else if (element < 4) /* scalar quarter */
        for (i = 0, j = element & 01; i < 8; i++)
        {
            VACC[i].DW = VR[vs].s[i] * VR[vt].s[j | (i & 0xE)];
            VACC[i].DW <<= 16;
        }
    else if (element < 8) /* scalar half */
        for (i = 0, j = element & 03; i < 8; i++)
        {
            VACC[i].DW = VR[vs].s[i] * VR[vt].s[j | (i & 0xC)];
            VACC[i].DW <<= 16;
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            VACC[i].DW = VR[vs].s[i] * VR[vt].s[j];
            VACC[i].DW <<= 16;
        }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW < 0)
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* signed underflow */
                VR[vd].s[i] = 0x8000;
            else
                VR[vd].s[i] = VACC[i].s[MD];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* signed overflow */
                VR[vd].s[i] = 0x7FFF;
            else
                VR[vd].s[i] = VACC[i].s[MD];
    return;
}

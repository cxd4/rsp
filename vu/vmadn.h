#include "vu.h"

static void VMADN(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][j = i];
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
            VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][j | (i & 0xE)];
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
            VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][j | (i & 0xC)];
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][j];
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* signed underflow */
                VR[vd][i] = 0x0000;
            else
                VR[vd][i] = VACC[i].s[LO];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* signed overflow */
                VR[vd][i] = 0xFFFF;
            else
                VR[vd][i] = VACC[i].s[LO];
    return;
}

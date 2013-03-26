#include "vu.h"

static void VMADN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if ((VACC[i].DW & 0xFFFF80000000) != 0xFFFF80000000)
                VR[vd][i] = 0x0000; /* slice underflow */
            else
                VR[vd][i] = VACC[i].s[LO];
        else
            if ((VACC[i].DW & 0xFFFF80000000) != 0x000000000000)
                VR[vd][i] = 0xFFFF; /* slice overflow */
            else
                VR[vd][i] = VACC[i].s[LO];
    return;
}

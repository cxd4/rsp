#include "vu.h"

static void VMADN(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += (unsigned short)VR[vs][i] * VR[vt][ei[e][i]];
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

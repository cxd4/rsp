#include "vu.h"

static void VMUDH(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
    {
        VACC[i].DW = VR[vs][i] * VR[vt][ei[e][i]];
        VACC[i].DW <<= 16;
    }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW < 0)
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* signed underflow */
                VR[vd][i] = 0x8000;
            else
                VR[vd][i] = VACC[i].s[MD];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* signed overflow */
                VR[vd][i] = 0x7FFF;
            else
                VR[vd][i] = VACC[i].s[MD];
    return;
}

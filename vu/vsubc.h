#include "vu.h"

static void VSUBC(int vd, int vs, int vt, int e)
{
    register signed int result;
    register int i;

    VCO = 0x0000;
    for (i = 0; i < 8; i++)
    {
        result = (unsigned short)VR[vs][i] - (unsigned short)VR[vt][ei[e][i]];
        VACC[i].s[LO] = (short)result;
        if (result == 0) continue;
        result = (result < 0);
        VCO |= result << i; /* CARRY, because VS - VT < 0 */
        VCO |= 0x0100 << i; /* NOTEQUAL, because VS != VT */
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

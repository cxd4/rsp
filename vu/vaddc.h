#include "vu.h"

static void VADDC(int vd, int vs, int vt, int e)
{
    register unsigned int result;
    register int i;

    VCO = 0x0000;
    for (i = 0; i < 8; i++)
    {
        result = (unsigned short)VR[vs][i] + (unsigned short)VR[vt][ei[e][i]];
        VACC[i].s[LO] = (short)result;
        result >>= 16; /* result = (VS + VT > 0x0000FFFF) ? 1 : 0; */
        VCO |= result << i;
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

#include "vu.h"

static void VGE(int vd, int vs, int vt, int e)
{
    int ge; /* greater than or, unless (CARRY && NOTEQUAL), equal */
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        const short VS = VR[vs][i];
        const short VT = VR[vt][ei[e][i]];

        ge  = (VS == VT);
        ge &= (VCO & 0x0101) != 0x0101;
        ge |= (VS > VT);
        VCC |= ge << i;
        VACC[i].s[LO] = ge ? VS : VT;
        VCO >>= 1;
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

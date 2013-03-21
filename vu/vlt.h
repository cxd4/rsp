#include "vu.h"

static void VLT(int vd, int vs, int vt, int e)
{
    int lt; /* less than, or if (CARRY && NOTEQUAL), equal */
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        const short VS = VR[vs][i];
        const short VT = VR[vt][ei[e][i]];

        lt  = (VS == VT);
        lt &= (VCO & 0x0101) == 0x0101;
        lt |= (VS < VT);
        VCC |= lt << i;
        VACC[i].s[LO] = lt ? VS : VT;
        VCO >>= 1;
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

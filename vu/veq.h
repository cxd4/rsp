#include "vu.h"

static void VEQ(int vd, int vs, int vt, int e)
{
    int eq; /* equal, unless (NOTEQUAL) */
    register int i;

    VCC = 0x0000;
    VCO >>= 8; /* We don't use the CARRY bits of VCO.  VCO will be cleared. */
    for (i = 0; i < 8; i++)
    {
        const short VS = VR[vs][i];
        const short VT = VR[vt][ei[e][i]];

        eq = (VS == VT) & !(VCO & 1);
        VCC |= eq << i;
        VACC[i].s[LO] = VT;
        VCO >>= 1;
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    /* VCO = 0x0000; /* We already cleared VCO by `VCO >>= 1` 16 times. */
    return;
}

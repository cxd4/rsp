#include "vu.h"

static void VNE(int vd, int vs, int vt, int element)
{
    int ne; /* not equal or, unless !(NOTEQUAL), equal */
    register int i, j;

    VCC = 0x0000;
    VCO >>= 8; /* We don't use the CARRY bits of VCO.  VCO will be cleared. */
    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            ne = (VR[vs][i] != VR[vt][j = i]) | (VCO & 1);
            VCC |= ne << i;
            VACC[i].s[LO] = ne ? VR[vs][i] : VR[vt][j = i];
            VCO >>= 1;
        }
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
        {
            ne = (VR[vs][i] != VR[vt][j | (i & 0xE)]) | (VCO & 1);
            VCC |= ne << i;
            VACC[i].s[LO] = ne ? VR[vs][i] : VR[vt][j | (i & 0xE)];
            VCO >>= 1;
        }
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
        {
            ne = (VR[vs][i] != VR[vt][j | (i & 0xC)]) | (VCO & 1);
            VCC |= ne << i;
            VACC[i].s[LO] = ne ? VR[vs][i] : VR[vt][j | (i & 0xC)];
            VCO >>= 1;
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            ne = (VR[vs][i] != VR[vt][j]) | (VCO & 1);
            VCC |= ne << i;
            VACC[i].s[LO] = ne ? VR[vs][i] : VR[vt][j];
            VCO >>= 1;
        }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    /* VCO = 0x0000; /* We already cleared VCO by `VCO >>= 1` 16 times. */
    return;
}

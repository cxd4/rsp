#include "vu.h"

static void VGE(int vd, int vs, int vt, int element)
{
    int ge; /* greater than or, unless (CARRY && NOTEQUAL), equal */
    register int i, j;

    VCC = 0x0000;
    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            ge  = (VR[vs][i] == VR[vt][j = i]);
            ge &= (VCO & 0x0101) != 0x0101;
            ge |= (VR[vs][i] > VR[vt][j = i]);
            VCC |= ge << i;
            VACC[i].s[LO] = ge ? VR[vs][i] : VR[vt][j = i];
            VCO >>= 1;
        }
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
        {
            ge  = (VR[vs][i] == VR[vt][j | (i & 0xE)]);
            ge &= (VCO & 0x0101) != 0x0101;
            ge |= (VR[vs][i] > VR[vt][j | (i & 0xE)]);
            VCC |= ge << i;
            VACC[i].s[LO] = ge ? VR[vs][i] : VR[vt][j | (i & 0xE)];
            VCO >>= 1;
        }
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
        {
            ge  = (VR[vs][i] == VR[vt][j | (i & 0xC)]);
            ge &= (VCO & 0x0101) != 0x0101;
            ge |= (VR[vs][i] > VR[vt][j | (i & 0xC)]);
            VCC |= ge << i;
            VACC[i].s[LO] = ge ? VR[vs][i] : VR[vt][j | (i & 0xC)];
            VCO >>= 1;
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            ge  = (VR[vs][i] == VR[vt][j]);
            ge &= (VCO & 0x0101) != 0x0101;
            ge |= (VR[vs][i] > VR[vt][j]);
            VCC |= ge << i;
            VACC[i].s[LO] = ge ? VR[vs][i] : VR[vt][j];
            VCO >>= 1;
        }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

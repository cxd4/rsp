#include "vu.h"

void VGE(int vd, int vs, int vt, int element)
{
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];

        if (VR[vs].s[i] > VR[vt].s[sel])
            VCC |= 0x0001 << i;
        else if (VR[vs].s[i] == VR[vt].s[sel])
            if ((VCO & (0x0101 << i)) != 0x0101 << i)
                VCC |= 0x0001 << i; /*
            else
                VCC &= ~(0x0001 << i);
        else
            VCC &= ~(0x0001 << i); */
        if (VCC & (0x0001 << i))
            VACC[i].s[LO] = VR[vs].s[i];
        else
            VACC[i].s[LO] = VR[vt].s[sel];
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

#include "vu.h"

void VGE(int vd, int vs, int vt, int element)
{
    register int i;

    VCF[01] = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];

        if (VR[vs].s[i] > VR[vt].s[sel])
            VCF[01] |= 0x0001 << i;
        else if (VR[vs].s[i] == VR[vt].s[sel])
            if ((VCF[00] & (0x0101 << i)) != 0x0101 << i)
                VCF[01] |= 0x0001 << i; /*
            else
                VCF[01] &= ~(0x0001 << i);
        else
            VCF[01] &= ~(0x0001 << i); */
        if (VCF[01] & (0x0001 << i))
            VACC[i].s[LO] = VR[vs].s[i];
        else
            VACC[i].s[LO] = VR[vt].s[sel];
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCF[00] = 0x0000;
    return;
}

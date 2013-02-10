#include "vu.h"

void VEQ(int vd, int vs, int vt, int element)
{
    register int i;

    VCF[01] = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        if ((VR[vs].s[i] == VR[vt].s[sel]) && !(VCF[00] & (0x0100 << i)))
        { /* to-do:  flags indexing is wrong, VCF[00] & 0xFF00 should be EQ */
            VACC[i].s[LO] = VR[vs].s[i];
            VCF[01] |= 0x0001 << i;
        }
        else
        {
            VACC[i].s[LO] = VR[vt].s[sel];
            /* VCF[01] &= ~(0x0001 << i); */
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCF[00] = 0x0000;
    return;
}

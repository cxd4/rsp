#include "vu.h"

void VEQ(int vd, int vs, int vt, int element)
{
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        if ((VR[vs].s[i] == VR[vt].s[sel]) && !(VCO & (0x0100 << i)))
        { /* to-do:  flags indexing is wrong, VCO & 0xFF00 should be EQ */
            VACC[i].s[LO] = VR[vs].s[i];
            VCC |= 0x0001 << i;
        }
        else
        {
            VACC[i].s[LO] = VR[vt].s[sel];
            /* VCC &= ~(0x0001 << i); */
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

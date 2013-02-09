#include "vu.h"

void VEQ(int vd, int vs, int vt, int element)
{
    register int i;

    VCF[01] = 0x0000;
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
    }
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        if ((VR[vs].s[i] == VR[vt].s[sel]) && !(VCF[00] & (0x0100 << i)))
        { /* to-do:  flags indexing is wrong, VCF[00] & 0xFF00 should be EQ */
            VACC[i].w[00] = VR[vs].s[i];
            VCF[01] |= 0x0001 << i;
        }
        else
        {
            VACC[i].w[00] = VR[vt].s[sel];
            VCF[01] &= ~(0x0001 << i);
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = (short)VACC[i].q;
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    VCF[00] = 0x0000;
    return;
}

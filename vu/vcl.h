#include "vu.h"

static void VCL(int vd, int vs, int vt, int e)
{
    int ge, le;
    register int i;

    for (i = 0; i < 8; i++)
    {
        const unsigned short VS = (unsigned short)VR[vs][i];
        const unsigned short VT = (unsigned short)VR[vt][ei[e][i]];
        const int eq = (((VCO >> (i + 8)) & 1) == 0); /* !(NOTEQUAL) */

        if ((VCO >> i) & 1)
        {
            ge = (VCC >> (i + 8)) & 1;
            if (eq)
            {
                const int sum = VS + VT;
                int ce = (VCE >> i) & 1;
                int lz = ((sum & 0x0000FFFF) == 0x00000000);
                int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                le = (ce & (lz | uz)) | (!ce & (lz & uz));
            }
            else
                le = (VCC >> i) & 1;
            VACC[i].s[LO] = le ? -VT : VS;
        }
        else
        {
            le = (VCC >> i) & 1;
            ge = eq ? (VS - VT >= 0) : (VCC >> (i + 8)) & 1;
            VACC[i].s[LO] = ge ? VT : VS;
        }
        VCC &= ~(0x0101 << i);
        VCC |= (ge << (i + 8)) | (le << (i + 0));
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    VCE = 0x00;
    return;
}

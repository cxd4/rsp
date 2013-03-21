#include "vu.h"

static void VCH(int vd, int vs, int vt, int e)
{
    int eq, ge, le;
    register int i;

    VCO = 0x0000;
    VCC = 0x0000;
    VCE = 0x00;
    for (i = 0; i < 8; i++)
    {
        const short VS = VR[vs][i];
        const short VT = VR[vt][ei[e][i]];

        if ((VS ^ VT) < 0)
        {
            ge = (VT < 0);
            le = (VS + VT <= 0);
            eq = (VS + VT == -1); /* compare extension */
            VCE |= eq << i;
            eq ^= !(VS + VT == 0);
            VACC[i].s[LO] = le ? -VT : VS;
            VCC |= (ge << (i + 8)) | (le << (i + 0));
            VCO |= (eq << (i + 8)) | (0x0001 << i);
        }
        else
        {
            le = (VT < 0);
            ge = (VS - VT >= 0);
            eq = !(VS - VT == 0); /* vs != +vt */
            VACC[i].s[LO] = ge ? VT : VS;
            VCC |= (ge << (i + 8)) | (le << (i + 0));
            VCO |= (eq << (i + 8)) | (0x0000 << i);
            VCE |= 0x00 << i;
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

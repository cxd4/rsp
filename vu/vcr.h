#include "vu.h"

static void VCR(int vd, int vs, int vt, int e)
{
    int ge, le;
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        const short VS = VR[vs][i];
        const short VT = VR[vt][ei[e][i]];

        if ((VS ^ VT) < 0)
        {
            ge = (VT < 0);
            le = (VS + VT < 0);
            VACC[i].s[LO] = le ? ~VT : VS;
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
        else
        {
            le = (VT < 0);
            ge = (VS - VT >= 0);
            VACC[i].s[LO] = le ? VT : VS;
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    VCE = 0x00;
    return;
}

#include "vu.h"

static void VCR(int vd, int vs, int vt, int element)
{
    int ge, le;
    register int i, j;

    VCC = 0x0000;
    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            if ((VR[vs][i] ^ VR[vt][i]) < 0)
            {
                ge = (VR[vt][i] < 0);
                le = (VR[vs][i] + VR[vt][i] < 0); /* vs + vt + 1 <= 0 */
                VACC[i].s[LO] = le ? ~VR[vt][i] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
            else
            {
                le = (VR[vt][i] < 0);
                ge = (VR[vs][i] - VR[vt][i] >= 0);
                VACC[i].s[LO] = le ? VR[vt][i] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
    else if (element < 4)
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            if ((VR[vs][i] ^ VR[vt][j]) < 0)
            {
                ge = (VR[vt][j] < 0);
                le = (VR[vs][i] + VR[vt][j] < 0);
                VACC[i].s[LO] = le ? ~VR[vt][i] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
            else
            {
                le = (VR[vt][j] < 0);
                ge = (VR[vs][i] - VR[vt][j] >= 0);
                VACC[i].s[LO] = le ? VR[vt][j] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
        }
    else if (element < 8)
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            if ((VR[vs][i] ^ VR[vt][j]) < 0)
            {
                ge = (VR[vt][j] < 0);
                le = (VR[vs][i] + VR[vt][j] < 0);
                VACC[i].s[LO] = le ? ~VR[vt][i] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
            else
            {
                le = (VR[vt][j] < 0);
                ge = (VR[vs][i] - VR[vt][j] >= 0);
                VACC[i].s[LO] = le ? VR[vt][j] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
            if ((VR[vs][i] ^ VR[vt][j]) < 0)
            {
                ge = (VR[vt][j] < 0);
                le = (VR[vs][i] + VR[vt][j] < 0);
                VACC[i].s[LO] = le ? ~VR[vt][i] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
            else
            {
                le = (VR[vt][j] < 0);
                ge = (VR[vs][i] - VR[vt][j] >= 0);
                VACC[i].s[LO] = le ? VR[vt][j] : VR[vs][i];
                VCC |= (ge << (i + 8)) | (le << (i + 0));
            }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    VCO = 0x0000;
    VCE = 0x00;
    return;
}

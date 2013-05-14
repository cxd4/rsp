#include "vu.h"

static void VCR(int vd, int vs, int vt, int e)
{
    int ge, le;
    register int i;

    VCC = 0x0000;
    for (i = 0; i < 8; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);
        const int sn = (VS ^ VT) < 0; /* sn = (unsigned short)(VS ^ VT) >> 15 */

        if (sn)
        {
            ge = (VT < 0);
            le = (VS + VT < 0);
            ACC_R(i) = le ? ~VT : VS;
        }
        else
        {
            le = (VT < 0);
            ge = (VS - VT >= 0);
            ACC_R(i) = le ? VT : VS;
        }
        VCC |= (ge <<= (i + 8)) | (le <<= (i + 0));
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    VCO = 0x0000;
    VCE = 0x00;
    return;
}

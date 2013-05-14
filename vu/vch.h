#include "vu.h"

static void VCH(int vd, int vs, int vt, int e)
{
    int ge, le, neq;
    register int i;

    VCO = 0x0000;
    VCC = 0x0000;
    VCE = 0x00;
    for (i = 0; i < 8; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);
        const int sn = (VS ^ VT) < 0; /* sn = (unsigned short)(VS ^ VT) >> 15 */

        if (sn)
        {
            ge = (VT < 0);
            le = (VS + VT <= 0);
            neq = (VS + VT == -1); /* compare extension */
            VCE |= neq << i;
            neq ^= !(VS + VT == 0); /* !(x | y) = x ^ !(y), if (x & y) != 1 */
            ACC_R(i) = le ? -VT : VS;
            VCO |= (neq <<= (i + 0x8)) | (sn << (i + 0x0)); /* sn = 1 */
        }
        else
        {
            le = (VT < 0);
            ge = (VS - VT >= 0);
            neq = !(VS - VT == 0);
            VCE |= 0x00 << i;
            ACC_R(i) = ge ? VT : VS;
            VCO |= (neq <<= (i + 0x8)) | (sn << (i + 0x0)); /* sn = 0 */
        }
        VCC |=  (ge <<= (i + 0x8)) | (le <<= (i + 0x0));
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

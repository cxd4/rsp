#include "vu.h"

static void VGE(int vd, int vs, int vt, int e)
{
    int ge; /* greater than or, unless (CARRY && NOTEQUAL), equal */
    register unsigned char VCO_VCE;
    register int i;

    VCC = 0x0000;
    VCO_VCE = ~(unsigned char)(VCO >> 8); /* NOT ah; MOV ax, ah; # eq = ~neq */
    for (i = 0; i < 8; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);

        ge  = ((~VCO >> i) & 0x0001) | ((VCO_VCE >> i) & 0x01);
        ge &= (VS == VT);
        ge |= (VS > VT);
        VCC |= ge <<= i;
        ACC_R(i) = ge ? VS : VT;
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    VCO = 0x0000;
    return;
}

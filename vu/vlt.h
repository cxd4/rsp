#include "vu.h"

static void VLT(int vd, int vs, int vt, int e)
{
    int lt; /* less than, or if (CARRY && NOTEQUAL), equal */
    register unsigned char VCO_VCE;
    register int i;

    VCC = 0x0000;
    VCO_VCE = ~(unsigned char)(VCO >> 8); /* NOT ah; MOV ax, ah; # eq = ~neq */
    for (i = 0; i < 8; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);

        lt  = ((VCO >> i) & 0x0001) & ((~VCO_VCE >> i) & 0x01);
        lt &= (VS == VT);
        lt |= (VS < VT);
        VCC |= lt <<= i;
        ACC_R(i) = lt ? VS : VT;
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    VCO = 0x0000;
    return;
}

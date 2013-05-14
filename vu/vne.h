#include "vu.h"

static void VNE(int vd, int vs, int vt, int e)
{
    int ne; /* not equal or, unless !(NOTEQUAL), equal */
    register unsigned char VCO_VCE;
    register int i;

    VCC = 0x0000;
    VCO_VCE = ~(unsigned char)(VCO >> 8); /* NOT ah; MOV ax, ah; # eq = ~neq */
    for (i = 0; i < 8; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);

        ne  = (~VCO_VCE >> i) & 0x01;
        ne |= (VS != VT);
        VCC |= ne <<= i;
        ACC_R(i) = VS; /* More accurately, `ACC_R(i) = ne ? VS : VT`. */
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    VCO = 0x0000;
    return;
}

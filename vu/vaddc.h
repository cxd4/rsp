#include "vu.h"

static void VADDC(int vd, int vs, int vt, int e)
{
    unsigned int result[8];
    register int i;

    VCO = 0x0000;
    for (i = 0; i < 8; i++)
        result[i] = (unsigned short)VR[vs][i] + (unsigned short)VR_T(i);
    for (i = 0; i < 8; i++)
        ACC_R(i) = (short)result[i];
    for (i = 0; i < 8; i++)
        VCO |= !!(result[i] & ~0x0000FFFF) << i;
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

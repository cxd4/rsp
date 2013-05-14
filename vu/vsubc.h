#include "vu.h"

static void VSUBC(int vd, int vs, int vt, int e)
{
    signed int result[8];
    register int i;

    VCO = 0x0000;
    for (i = 0; i < 8; i++)
        result[i] = (unsigned short)VR[vs][i] - (unsigned short)VR_T(i);
    for (i = 0; i < 8; i++)
        ACC_R(i) = (short)result[i];
    for (i = 0; i < 8; i++)
    {
        if (result[i] == 0) continue; /* If VS == VT, neither flag is set. */
        VCO |= (result[i] < 0) << i; /* CARRY, because VS - VT < 0 */
        VCO |= (0x01 << 8) << i; /* NOTEQUAL, because VS - VT != 0 */
    }
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

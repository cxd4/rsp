#include "vu.h"

static void VADD(int vd, int vs, int vt, int element)
{
    signed int result[8];
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            result[i] = VR[vs][i] + VR[vt][j = i] + (VCO & 0x0001);
            VCO >>= 1;
        }
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
        {
            result[i] = VR[vs][i] + VR[vt][j | (i & 0xE)] + (VCO & 0x0001);
            VCO >>= 1;
        }
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
        {
            result[i] = VR[vs][i] + VR[vt][j | (i & 0xC)] + (VCO & 0x0001);
            VCO >>= 1;
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            result[i] = VR[vs][i] + VR[vt][j] + (VCO & 0x0001);
            VCO >>= 1;
        }
    for (i = 0; i < 8; i++)
    {
        VACC[i].s[LO] = (short)result[i];
        if (result[i] > +32767)
            VR[vd][i] = 0x7FFF;
        else if (result[i] < -32768)
            VR[vd][i] = 0x8000;
        else
            VR[vd][i] = (short)result[i];
    }
    VCO = 0x0000; /* Clear the remaining, upper NOTEQUAL bits. */
    return;
}

#include "vu.h"

static void VADDC(int vd, int vs, int vt, int element)
{
    register unsigned int result;
    register int i, j;

    VCO = 0x0000;
    if (!element) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            result = (unsigned short)VR[vs][i] + (unsigned short)VR[vt][i];
            VACC[i].s[LO] = (short)result;
            result >>= 16; /* result = (VS + VT > 0x0000FFFF) ? 1 : 0; */
            VCO |= result << i;
        }
    }
    else if (element < 4)
    {
        for (i = 0, j = element & 01; i < 8; i++)
        {
            result = (unsigned short)VR[vs][i]
                   + (unsigned short)VR[vt][j | (i & 0xE)];
            VACC[i].s[LO] = (short)result;
            result >>= 16; /* result = (VS + VT > 0x0000FFFF) ? 1 : 0; */
            VCO |= result << i;
        }
    }
    else if (element < 8)
    {
        for (i = 0, j = element & 03; i < 8; i++)
        {
            result = (unsigned short)VR[vs][i]
                   + (unsigned short)VR[vt][j | (i & 0xC)];
            VACC[i].s[LO] = (short)result;
            result >>= 16; /* result = (VS + VT > 0x0000FFFF) ? 1 : 0; */
            VCO |= result << i;
        }
    }
    else /* if (element & 0b1000) */
    {
        for (i = 0, j = element & 07; i < 8; i++)
        {
            result = (unsigned short)VR[vs][i] + (unsigned short)VR[vt][j];
            VACC[i].s[LO] = (short)result;
            result >>= 16; /* result = (VS + VT > 0x0000FFFF) ? 1 : 0; */
            VCO |= result << i;
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

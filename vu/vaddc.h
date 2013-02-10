#include "vu.h"

void VADDC(int vd, int vs, int vt, int element)
{
    register unsigned int result;
    register int i;

    VCF[00] = 0x0000;
    if (element == 00) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i] + (unsigned short)VR[vt].s[i];
            VACC[i].w[00] = (short)result;
            VCF[00] |= (result > 0x0000FFFF) << i;
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            result = (unsigned short)VR[vs].s[i] + (unsigned short)VR[vt].s[j];
            VACC[i].w[00] = (short)result;
            VCF[00] |= (result > 0x0000FFFF) << i;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            result = (unsigned short)VR[vs].s[i] + (unsigned short)VR[vt].s[j];
            VACC[i].w[00] = (short)result;
            VCF[00] |= (result > 0x0000FFFF) << i;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register int j = element & 07;

        for (i = 0; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i] + (unsigned short)VR[vt].s[j];
            VACC[i].w[00] = (short)result;
            VCF[00] |= (result > 0x0000FFFF) << i;
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].w[00];
    return;
}

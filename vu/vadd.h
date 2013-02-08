#include "vu.h"

void VADD(int vd, int vs, int vt, int element)
{
    signed int result[8];
    register int i;

    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
    }
    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            result[i] = VR[vs].s[i] + VR[vt].s[i];
            if ((VCF[00] & (1 << i)) == 0x0000) continue;
            ++result[i];
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            result[i] = VR[vs].s[i] + VR[vt].s[j];
            if ((VCF[00] & (1 << i)) == 0x0000) continue;
            ++result[i];
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            result[i] = VR[vs].s[i] + VR[vt].s[j];
            if ((VCF[00] & (1 << i)) == 0x0000) continue;
            ++result[i];
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register int j = element & 07;

        for (i = 0; i < 8; i++)
        {
            result[i] = VR[vs].s[i] + VR[vt].s[j];
            if ((VCF[00] & (1 << i)) == 0x0000) continue;
            ++result[i];
        }
    }
    for (i = 0; i < 8; i++)
    {
        VACC[i].w[00] = (short)result[i];
        if (result[i] > +32767)
            VR[vd].s[i] = 0x7FFF;
        else if (result[i] < -32768)
            VR[vd].s[i] = 0x8000;
        else
            VR[vd].s[i] = (short)result[i];
    }
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    VCF[00] = 0x0000;
    return;
}

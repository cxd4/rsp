#include "vu.h"

void VCR(int vd, int vs, int vt, int element)
{
    register int i;

    VCF[00] = 0x0000;
    VCF[01] = 0x0000;
    VCF[02] = 0x0000;
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
    }
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short int paired_source_1 = VR[vt].s[sel];
        signed short int paired_source_2 = VR[vs].s[i];
        if ((paired_source_2 ^ paired_source_1) >= 0)
        {
            if (paired_source_1 < 0)
            {
                VCF[01] |= 0x0001 << i;
            }
            if (paired_source_2 < paired_source_1)
            {
                VACC[i].w[00] = paired_source_2;
            }
            else
            {
                VACC[i].w[00] = paired_source_1;
                VCF[01] |= 0x0100 << i;
            }
        }
        else
        {
            if (paired_source_1 < 0)
            {
                VCF[01] |= 0x0100 << i;
            }
            if (paired_source_1 + paired_source_2 > 0)
            {
                VACC[i].w[00] = paired_source_2;
            }
            else
            {
                VACC[i].w[00] = ~paired_source_1;
                VCF[01] |= 0x0001 << i;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = (short)VACC[i].q;
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    return;
}

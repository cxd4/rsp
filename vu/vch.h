#include "vu.h"

void VCH(int vd, int vs, int vt, int element)
{
    register int i;

    VCF[0] = 0x0000;
    VCF[1] = 0x0000;
    VCF[2] = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short paired_source_2 = VR[vs].s[i];
        signed short paired_source_1 = VR[vt].s[sel];

        if ((paired_source_2 ^ paired_source_1) < 0)
        {
            VCF[00] |= 0x0001 << i;
            if (paired_source_1 < 0)
            {
                VCF[01] |= 0x0100 << i;
            }
            if (paired_source_2 + paired_source_1 > 0)
            {
                VACC[i].w[00] = paired_source_2;
                if (paired_source_2 == ~paired_source_1) continue;
                VCF[00] |= 0x0100 << i;
            }
            else
            {
                if (paired_source_2 + paired_source_1 == -1)
                {
                    VCF[02] |= 0x0001 << i;
                    if (paired_source_2 == ~paired_source_1) continue;
                    VCF[00] |= 0x0100 << i;
                }
                else
                {
                    VCF[01] |= 0x0001 << i;
                    VACC[i].w[00] = -paired_source_1;
                    if (paired_source_2 == -paired_source_1) continue;
                    if (paired_source_2 == ~paired_source_1) continue;
                    VCF[00] |= 0x0100 << i;
                }
            }
        }
        else
        {
            if (paired_source_1 < 0)
            {
                VCF[01] |= 0x0001 << i;
            }
            if (paired_source_2 < paired_source_1)
            {
                VACC[i].w[00] = paired_source_2;
                if (paired_source_2 == ~paired_source_1) continue;
                VCF[00] |= 0x0100 << i;
            }
            else
            {
                VCF[01] |= 0x0100 << i;
                VACC[i].w[00] = paired_source_1;
                if (paired_source_2 == +paired_source_1) continue;
                if (paired_source_2 == ~paired_source_1) continue;
                VCF[00] |= 0x0100 << i;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = (short)VACC[i].q;
    return;
}

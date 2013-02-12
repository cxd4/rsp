#include "vu.h"

void VCH(int vd, int vs, int vt, int element)
{
    register int i;

    VCO = 0x0000;
    VCC = 0x0000;
    VCE = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short paired_source_2 = VR[vs].s[i];
        signed short paired_source_1 = VR[vt].s[sel];

        if ((paired_source_2 ^ paired_source_1) < 0)
        {
            VCO |= 0x0001 << i;
            if (paired_source_1 < 0)
            {
                VCC |= 0x0100 << i;
            }
            if (paired_source_2 + paired_source_1 > 0)
            {
                VACC[i].s[LO] = paired_source_2;
                if (paired_source_2 == ~paired_source_1) continue;
                VCO |= 0x0100 << i;
            }
            else
            {
                if (paired_source_2 + paired_source_1 == -1)
                {
                    VCE |= 0x0001 << i;
                    if (paired_source_2 == ~paired_source_1) continue;
                    VCO |= 0x0100 << i;
                }
                else
                {
                    VCC |= 0x0001 << i;
                    VACC[i].s[LO] = -paired_source_1;
                    if (paired_source_2 == -paired_source_1) continue;
                    if (paired_source_2 == ~paired_source_1) continue;
                    VCO |= 0x0100 << i;
                }
            }
        }
        else
        {
            if (paired_source_1 < 0)
            {
                VCC |= 0x0001 << i;
            }
            if (paired_source_2 < paired_source_1)
            {
                VACC[i].s[LO] = paired_source_2;
                if (paired_source_2 == ~paired_source_1) continue;
                VCO |= 0x0100 << i;
            }
            else
            {
                VCC |= 0x0100 << i;
                VACC[i].s[LO] = paired_source_1;
                if (paired_source_2 == +paired_source_1) continue;
                if (paired_source_2 == ~paired_source_1) continue;
                VCO |= 0x0100 << i;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    return;
}

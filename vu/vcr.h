#include "vu.h"

void VCR(int vd, int vs, int vt, int element)
{
    register int i;

    VCO = 0x0000;
    VCC = 0x0000;
    VCE = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short int paired_source_1 = VR[vt].s[sel];
        signed short int paired_source_2 = VR[vs].s[i];
        if ((paired_source_2 ^ paired_source_1) >= 0)
        {
            if (paired_source_1 < 0)
            {
                VCC |= 0x0001 << i;
            }
            if (paired_source_2 < paired_source_1)
            {
                VACC[i].s[LO] = paired_source_2;
            }
            else
            {
                VACC[i].s[LO] = paired_source_1;
                VCC |= 0x0100 << i;
            }
        }
        else
        {
            if (paired_source_1 < 0)
            {
                VCC |= 0x0100 << i;
            }
            if (paired_source_1 + paired_source_2 > 0)
            {
                VACC[i].s[LO] = paired_source_2;
            }
            else
            {
                VACC[i].s[LO] = ~paired_source_1;
                VCC |= 0x0001 << i;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    return;
}

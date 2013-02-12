#include "vu.h"

void VCL(int vd, int vs, int vt, int element)
{
    register int i;

    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short s1 = VR[vs].s[i];
        signed short s2 = VR[vt].s[sel];

        if (VCO & (0x0001 << i))
        {
            if (VCO & (0x0100 << i))
            {
                VACC[i].s[LO] = (VCC & (0x0001 << i)) ? -s2 : +s1;
            }
            else
            {
                if (VCE & (0x0001 << i))
                {
                    if (((UINT32)(UINT16)s1 + (UINT32)(UINT16)s2) > 0x10000)
                    { /* proper fix for Harvest Moon 64, r4 */
                        VACC[i].s[LO] = s1;
                        VCC &= ~(0x0001 << i);
                    }
                    else
                    {
                        VACC[i].s[LO] = -s2;
                        VCC |= 0x0001 << i;
                    }
                }
                else
                {
                    if ((UINT32)(UINT16)s1 + (UINT32)(UINT16)s2)
                    { /* вместе с фиксом для Harvest Moon 64, */
                        VACC[i].s[LO] = s1;
                        VCC &= ~(0x0001 << i);
                    } /* чтоб соответствовать pj64 1.4 rsp */
                    else
                    {
                        VACC[i].s[LO] = -s2;
                        VCC |= 0x0001 << i;
                    }
                }
            }
        }
        else
        {
            if (VCO & (0x0100 << i))
            {
                if (VCC & (0x0100 << i))
                {
                    VACC[i].s[LO] = s2;
                }
                else
                {
                    VACC[i].s[LO] = s1;
                }
            }
            else
            {
                const unsigned short flag_offset = 0x0100 << i;
                VACC[i].s[LO] = ((INT32)(UINT16)s1 < (INT32)(UINT16)s2)
                               ? s1 : s2;
                VCC = ((INT32)(UINT16)s1 < (INT32)(UINT16)s2)
                        ? VCC & ~flag_offset
                        : VCC | flag_offset;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    VCE = 0x0000;
    return;
}

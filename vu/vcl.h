#include "vu.h"

void VCL(int vd, int vs, int vt, int element)
{
    register int i;

    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short s1 = VR[vs].s[i];
        signed short s2 = VR[vt].s[sel];
        if (VCF[00] & (0x0001 << i))
        {
            if (VCF[00] & (0x0100 << i))
            {
                VACC[i].s[LO] = (VCF[01] & (0x0001 << i))
                               ? -s2 : +s1;
            }
            else
            {
                if (VCF[02] & (0x0001 << i))
                {
                    if (((UINT32)(UINT16)s1 + (UINT32)(UINT16)s2) > 0x10000)
                    { /* proper fix for Harvest Moon 64, r4 */
                        VACC[i].s[LO] = s1;
                        VCF[01] &= ~(0x0001 << i);
                    }
                    else
                    {
                        VACC[i].s[LO] = -s2;
                        VCF[01] |= 0x0001 << i;
                    }
                }
                else
                {
                    if ((UINT32)(UINT16)s1 + (UINT32)(UINT16)s2)
                    { /* вместе с фиксом для Harvest Moon 64, */
                        VACC[i].s[LO] = s1;
                        VCF[01] &= ~(0x0001 << i);
                    } /* чтоб соответствовать pj64 1.4 rsp */
                    else
                    {
                        VACC[i].s[LO] = -s2;
                        VCF[01] |= 0x0001 << i;
                    }
                }
            }
        }
        else
        {
            if (VCF[00] & (0x0100 << i))
            {
                if (VCF[01] & (0x0100 << i))
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
                VCF[01] = ((INT32)(UINT16)s1 < (INT32)(UINT16)s2)
                        ? VCF[01] & ~flag_offset
                        : VCF[01] | flag_offset;
            }
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCF[00] = 0x0000;
    VCF[02] = 0x0000;
    return;
}

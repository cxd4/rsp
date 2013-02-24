#include "vu.h"

static void VSUBC(int vd, int vs, int vt, int element)
{
    register signed int result;
    register int i, j;

    VCO = 0x0000;
    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i] - (unsigned short)VR[vt].s[i];
            VACC[i].s[LO] = (short)result;
            if (result == 0) continue;
            result = (result < 0);
            VCO |= result << i; /* CARRY, because VS - VT < 0 */
            VCO |= 0x0100 << i; /* NOTEQUAL, because VS != VT */
        }
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i]
                   - (unsigned short)VR[vt].s[j | (i & 0xE)];
            VACC[i].s[LO] = (short)result;
            if (result == 0) continue;
            result = (result < 0);
            VCO |= result << i; /* CARRY, because VS - VT < 0 */
            VCO |= 0x0100 << i; /* NOTEQUAL, because VS != VT */
        }
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i]
                   - (unsigned short)VR[vt].s[j | (i & 0xC)];
            VACC[i].s[LO] = (short)result;
            if (result == 0) continue;
            result = (result < 0);
            VCO |= result << i; /* CARRY, because VS - VT < 0 */
            VCO |= 0x0100 << i; /* NOTEQUAL, because VS != VT */
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            result = (unsigned short)VR[vs].s[i] - (unsigned short)VR[vt].s[j];
            VACC[i].s[LO] = (short)result;
            if (result == 0) continue;
            result = (result < 0);
            VCO |= result << i; /* CARRY, because VS - VT < 0 */
            VCO |= 0x0100 << i; /* NOTEQUAL, because VS != VT */
        }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    return;
}

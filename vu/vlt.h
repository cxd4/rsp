#include "vu.h"

static void VLT(int vd, int vs, int vt, int element)
{
    register int i, j;

    VCC = 0x0000;
/* We could be accurate and clear these mid-way (e.g. vs > vt then clear the
 * current bit of VCC), but doing this now is much more simple and direct.
 */
    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            if (VR[vs].s[i] < VR[vt].s[i])
                VCC |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[i])
                if ((VCO & (0x0101 << i)) == 0x0101 << i)
                    VCC |= 0x0001 << i; /*
                else
                    VCC &= ~(0x0001 << i);
            else
                VCC &= ~(0x0001 << i); */
            if (VCC & (0x0001 << i)) /* As defined by above if()-else-if. */
                VACC[i].s[LO] = VR[vs].s[i];
            else
                VACC[i].s[LO] = VR[vt].s[i];
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            if (VR[vs].s[i] < VR[vt].s[j])
                VCC |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[j])
                if ((VCO & (0x0101 << i)) == 0x0101 << i)
                    VCC |= 0x0001 << i; /*
                else
                    VCC &= ~(0x0001 << i);
            else
                VCC &= ~(0x0001 << i); */
            if (VCC & (0x0001 << i))
                VACC[i].s[LO] = VR[vs].s[i];
            else
                VACC[i].s[LO] = VR[vt].s[j];
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            if (VR[vs].s[i] < VR[vt].s[j])
                VCC |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[j])
                if ((VCO & (0x0101 << i)) == 0x0101 << i)
                    VCC |= 0x0001 << i; /*
                else
                    VCC &= ~(0x0001 << i);
            else
                VCC &= ~(0x0001 << i); */
            if (VCC & (0x0001 << i))
                VACC[i].s[LO] = VR[vs].s[i];
            else
                VACC[i].s[LO] = VR[vt].s[j];
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register short int t = VR[vt].s[element & 07];

        for (i = 0; i < 8; i++)
        {
            if (VR[vs].s[i] < t)
                VCC |= 0x0001 << i;
            else if (VR[vs].s[i] == t)
                if ((VCO & (0x0101 << i)) == 0x0101 << i)
                    VCC |= 0x0001 << i; /*
                else
                    VCC &= ~(0x0001 << i);
            else
                VCC &= ~(0x0001 << i); */
            if (VCC & (0x0001 << i))
                VACC[i].s[LO] = VR[vs].s[i];
            else
                VACC[i].s[LO] = t;
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

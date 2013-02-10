#include "vu.h"

void VLT(int vd, int vs, int vt, int element)
{
    register int i, j;

    VCF[01] = 0x0000;
/* We could be accurate and clear these mid-way (e.g. vs > vt then clear the
 * current bit of VCC), but doing this now is much more simple and direct.
 */
    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            if (VR[vs].s[i] < VR[vt].s[i])
                VCF[01] |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[i])
                if ((VCF[00] & (0x0101 << i)) == 0x0101 << i)
                    VCF[01] |= 0x0001 << i; /*
                else
                    VCF[01] &= ~(0x0001 << i);
            else
                VCF[01] &= ~(0x0001 << i); */
            if (VCF[01] & (0x0001 << i)) /* As defined by above if()-else-if. */
                VACC[i].w[00] = VR[vs].s[i];
            else
                VACC[i].w[00] = VR[vt].s[i];
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            if (VR[vs].s[i] < VR[vt].s[j])
                VCF[01] |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[j])
                if ((VCF[00] & (0x0101 << i)) == 0x0101 << i)
                    VCF[01] |= 0x0001 << i; /*
                else
                    VCF[01] &= ~(0x0001 << i);
            else
                VCF[01] &= ~(0x0001 << i); */
            if (VCF[01] & (0x0001 << i))
                VACC[i].w[00] = VR[vs].s[i];
            else
                VACC[i].w[00] = VR[vt].s[j];
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            if (VR[vs].s[i] < VR[vt].s[j])
                VCF[01] |= 0x0001 << i;
            else if (VR[vs].s[i] == VR[vt].s[j])
                if ((VCF[00] & (0x0101 << i)) == 0x0101 << i)
                    VCF[01] |= 0x0001 << i; /*
                else
                    VCF[01] &= ~(0x0001 << i);
            else
                VCF[01] &= ~(0x0001 << i); */
            if (VCF[01] & (0x0001 << i))
                VACC[i].w[00] = VR[vs].s[i];
            else
                VACC[i].w[00] = VR[vt].s[j];
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register short int t = VR[vt].s[element & 07];

        for (i = 0; i < 8; i++)
        {
            if (VR[vs].s[i] < t)
                VCF[01] |= 0x0001 << i;
            else if (VR[vs].s[i] == t)
                if ((VCF[00] & (0x0101 << i)) == 0x0101 << i)
                    VCF[01] |= 0x0001 << i; /*
                else
                    VCF[01] &= ~(0x0001 << i);
            else
                VCF[01] &= ~(0x0001 << i); */
            if (VCF[01] & (0x0001 << i))
                VACC[i].w[00] = VR[vs].s[i];
            else
                VACC[i].w[00] = t;
        }
    }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = (short)VACC[i].q;
    VCF[00] = 0x0000;
    return;
}

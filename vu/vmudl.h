#include "vu.h"

static void VMUDL(int vd, int vs, int vt, int element)
{
    register unsigned int product;
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[i];
            VACC[i].DW = product >> 16;
        }
    }
    else if (element < 4)
    {
        for (i = 0, j = element & 01; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i]
                    * (unsigned short)VR[vt].s[j | (i & 0xE)];
            VACC[i].DW = product >> 16;
        }
    }
    else if (element < 8)
    {
        for (i = 0, j = element & 03; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i]
                    * (unsigned short)VR[vt].s[j | (i & 0xC)];
            VACC[i].DW = product >> 16;
        }
    }
    else /* if (element & 0b1000) */
    {
        for (i = 0, j = element & 07; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].DW = product >> 16;
        }
    }
    for (i = 0; i < 8; i++) /* Signed-clamp bits 15..0 of ACC to dest. VR. */
        VR[vd].s[i] = VACC[i].s[LO]; /* No arithmetic checks needed. */
    return;
}

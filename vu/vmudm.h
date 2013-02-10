#include "vu.h"

void VMUDM(int vd, int vs, int vt, int element)
{
    register int product;
    register int i, j;

    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = (signed short)VR[vs].s[i] * (unsigned short)VR[vt].s[i];
            VACC[i].q = product;
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            product = (signed short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].q = product;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            product = (signed short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].q = product;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register unsigned short m = (unsigned short)VR[vt].s[element % 8];

        for (i = 0; i < 8; i++)
        {
            product = (signed short)VR[vs].s[i] * m;
            VACC[i].q = product;
        }
    }
    for (i = 0; i < 8; i++) /* Signed-clamp bits 31..16 of ACC to dest. VR. */
        VR[vd].s[i] = VACC[i].w[01]; /* No saturate checks needed. */
    return;
}

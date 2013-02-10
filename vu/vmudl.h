#include "vu.h"

void VMUDL(int vd, int vs, int vt, int element)
{
    register unsigned int product;
    register int i, j;

    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[i];
            VACC[i].q = product;
            VACC[i].q >>= 16;
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].q = product;
            VACC[i].q >>= 16;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].q = product;
            VACC[i].q >>= 16;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register unsigned short m = (unsigned short)VR[vt].s[element % 8];

        for (i = 0; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * m;
            VACC[i].q = product;
            VACC[i].q >>= 16;
        }
    }
    for (i = 0; i < 8; i++) /* Signed-clamp bits 15..0 of ACC to dest. VR. */
        VR[vd].s[i] = (short)VACC[i].q; /* No arithmetic checks needed. */
    return;
}

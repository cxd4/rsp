#include "vu.h"

void VMULU(int vd, int vs, int vt, int element)
{
    register int product;
    register int i;

    if (element == 00) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * VR[vt].s[i];
            product <<= 1; /* shift of partial product */
            VACC[i].q = product + 0x8000; /* fraction rounding */
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].q = product + 0x8000;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        register int j;

        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].q = product + 0x8000;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register int j = element & 07;

        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].q = product + 0x8000;
        }
    }
    for (i = 0; i < 8; i++) /* Unsigned-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].q & 0x800000000000) /* acc < 0 */
            VR[vd].s[i] = 0x0000; /* unsigned underflow */
        else if (VACC[i].q & ~0x00007FFFFFFF) /* short overflow */
            VR[vd].s[i] = 0xFFFF;
        else
            VR[vd].s[i] = (short)(VACC[i].q >> 16);
    return;
}

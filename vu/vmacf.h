#include "vu.h"

static const void VMACF(int vd, int vs, int vt, int element)
{
    register int product;
    register int i, j;

    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * VR[vt].s[i];
            product <<= 1; /* shift of partial product */
            VACC[i].DW += product; /* fraction rounding */
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].DW += product;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].DW += product;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register short int m = VR[vt].s[element & 07];

        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * m;
            product <<= 1;
            VACC[i].DW += product;
        }
    }
    for (i = 0; i < 8; i++) /* Signed-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* short underflow */
                VR[vd].s[i] = 0x8000;
            else
                VR[vd].s[i] = VACC[i].s[MD];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* short overflow */
                VR[vd].s[i] = 0x7FFF;
            else
                VR[vd].s[i] = VACC[i].s[MD];
    return;
}

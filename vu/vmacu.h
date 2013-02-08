#include "vu.h"

void VMACU(int vd, int vs, int vt, int element)
{
    register int product;
    register int i, j;

    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
    }
    if (element == 0x0) /* if (element >> 1 == 00) */
    {
        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * VR[vt].s[i];
            product <<= 1; /* shift of partial product */
            VACC[i].q += product; /* fraction rounding */
        }
    }
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].q += product;
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            product = VR[vs].s[i] * VR[vt].s[j];
            product <<= 1;
            VACC[i].q += product;
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register short int m = VR[vt].s[element & 07];

        for (i = 0; i < 8; i++)
        {
            product = VR[vs].s[i] * m;
            product <<= 1;
            VACC[i].q += product;
        }
    }
    for (i = 0; i < 8; i++) /* Unsigned-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].q & 0x800000000000) /* acc < 0 */
            VR[vd].s[i] = 0x0000; /* unsigned underflow */
        else if (VACC[i].q & ~0x00007FFFFFFF) /* short overflow */
            VR[vd].s[i] = 0xFFFF;
        else
            VR[vd].s[i] = (short)(VACC[i].q >> 16);
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    return;
}

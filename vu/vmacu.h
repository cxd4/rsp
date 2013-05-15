#include "vu.h"

static void VMACU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += VR[vs][i]*VR_T(i) << 1;
    for (i = 0; i < 8; i++) /* Zero-clamp bits 31..16 of ACC to dest. VR. */
    {
        register signed short result;
        register short int tmp;

        result  = VACC[i].s[MD]; /* raw slice before clamping */
        tmp = (signed short)(VACC[i].DW >> 31) != 0x0000;
        result |= -tmp; /* slice overflow */
        tmp = VACC[i].s[HI] >> 15; /* Zero- or one-extend. */
        result &= ~tmp; /* slice underflow */
        VR_D(i) = result;
    }
    return;
}

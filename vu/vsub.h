#include "vu.h"

static void VSUB(int vd, int vs, int vt, int e)
{
    signed int result[8];
    register int i;

    for (i = 0; i < 8; i++) /* Try to vectorize the subtracts to be parallel. */
        result[i] = VR[vs][i] - VR_T(i);
    for (i = 0; i < 8; i++)
    {
        result[i] -= VCO & 0x0001;
        VCO >>= 1;
    }
    VCO = 0x0000; /* Clear the remaining, upper NOTEQUAL bits. */
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = (short)result[i];
    for (i = 0; i < 8; i++)
#ifdef FORCE_STATIC_CLAMP
    {
        const signed int under = (signed)(result[i] + 32768) >> 31;
        const signed int over  = (signed)(32767 - result[i]) >> 31;

        sclamp[1][1] = result[i] & 0x0000FFFF;
        VR_D(i) = sclamp[under + 1][over + 1];
    }
#else
        if (result[i] > +32767)
            VR_D(i) = +32767;
        else if (result[i] < -32768)
            VR_D(i) = -32768;
        else
            VR_D(i) = (short)result[i];
#endif
    return;
}

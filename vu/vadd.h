#include "vu.h"

static void VADD(int vd, int vs, int vt, int e)
{
    signed int result[8];
    register int i;

    for (i = 0; i < 8; i++) /* Try to vectorize the adds to be parallel. */
        result[i] = VR[vs][i] + VR_T(i);
    for (i = 0; i < 8; i++)
    {
        result[i] += VCO & 0x0001;
        VCO >>= 1; /* We'll need to clear this entire register anyway. */
    }
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = (short)result[i];
    for (i = 0; i < 8; i++)
        if (result[i] > +32767)
            VR[vd][i] = +32767;
        else if (result[i] < -32768)
            VR[vd][i] = -32768;
        else
            VR[vd][i] = (short)result[i];
    VCO = 0x0000; /* Clear the remaining, upper NOTEQUAL bits. */
    return;
}

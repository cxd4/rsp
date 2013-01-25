#include "vu.h"

void VMACU(int vd, int vs, int vt, int element)
{
    register int i;

    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        INT32 r1 = (signed short)VR[vs].s[i] * (signed short)VR[vt].s[sel];
        UINT32 r2 = (UINT16)ACCUM_L(i) + ((UINT16)(r1) * 2);
        UINT32 r3 = (UINT16)ACCUM_M(i) + (UINT16)((r1 >> 16) * 2) + (UINT16)(r2 >> 16);

        // VACC[i].q += (long long)r1 << 16;
/* VMACU is much more complicated than the others.
 * Both the clamping procedures and additive accumulations seem unique.
 * It will take me a while to figure out how to optimize and simplify.
 */
        VACC[i].w[LO]  = (short)r2;
        VACC[i].w[MD]  = (short)r3;
        VACC[i].w[HI] += (short)(r3 >> 16) + (short)(r1 >> 31);
    }
    for (i = 0; i < 8; i++)
    {
        if (VACC[i].q < 0)
        {
            VR[vd].s[i] = 0x0000;
            continue;
        }
        if (VACC[i].q & ~0x7FFFFFFFFFFF)
        { /* Actually & ~0x7FFFFFFF, but we have shifted accumulators. */
            VR[vd].s[i] = 0xFFFF;
            continue;
        }
        VR[vd].s[i] = VACC[i].w[MD];
    }
    return;
}

#include "vu.h"

void VMULU(int vd, int vs, int vt, int element)
{
    register signed long long int product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        product = VR[vs].s[i] * VR[vt].s[sel];
        product <<= 1;
        product += 0x0000000000008000; /* rounding ? */

        VACC[i].q = product << 16;
        VR[vd].s[i] = UNSIGNED_CLAMP(i); /*
        if (product < 0)
        {
            VR[vd].s[i] = 0x0000;
            continue;
        }
        VR[vd].s[i] = (VACC[i].w[02] < 0) ? 0xFFFF : VACC[i].w[02]; */
    }
    return;
}

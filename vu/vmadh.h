#include "vu.h"

static void VMADH(int vd, int vs, int vt, int e)
{
    register signed long long product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = VR[vs][i]*VR[vt][ei[e][i]];
        VACC[i].DW += product << 16;
    }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* short underflow */
                VR[vd][i] = 0x8000;
            else
                VR[vd][i] = VACC[i].s[MD];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* short overflow */
                VR[vd][i] = 0x7FFF;
            else
                VR[vd][i] = VACC[i].s[MD];
    return;
}

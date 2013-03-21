#include "vu.h"

static void VMACU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        VACC[i].DW += VR[vs][i]*VR[vt][ei[e][i]] << 1;
    for (i = 0; i < 8; i++) /* Unsigned-clamp bits 31..16 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            VR[vd][i] = 0x0000; /* unsigned underflow */
        else if (VACC[i].DW & ~0x00007FFFFFFF) /* short overflow */
            VR[vd][i] = 0xFFFF;
        else
            VR[vd][i] = VACC[i].s[MD];
    return;
}

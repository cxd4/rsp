#include "vu.h"

static void VMADL(int vd, int vs, int vt, int e)
{
    register unsigned int product;
    register int i;

    for (i = 0; i < 8; i++)
    {
        product = (unsigned short)VR[vs][i] * (unsigned short)VR[vt][ei[e][i]];
        VACC[i].DW += product >> 16;
    }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if ((VACC[i].DW & 0xFFFF80000000) != 0xFFFF80000000)
                VR[vd][i] = 0x0000; /* slice underflow */
            else
                VR[vd][i] = VACC[i].s[LO];
        else
            if ((VACC[i].DW & 0xFFFF80000000) != 0x000000000000)
                VR[vd][i] = 0xFFFF; /* slice overflow */
            else
                VR[vd][i] = VACC[i].s[LO];
    return;
}

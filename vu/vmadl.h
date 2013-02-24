#include "vu.h"

static void VMADL(int vd, int vs, int vt, int element)
{
    register unsigned int product;
    register int i, j;

    if (!element) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[i];
            VACC[i].DW += product >> 16;
        }
    else if (element < 4)
        for (i = 0, j = element & 01; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i]
                    * (unsigned short)VR[vt].s[j | (i & 0xE)];
            VACC[i].DW += product >> 16;
        }
    else if (element < 8)
        for (i = 0, j = element & 03; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i]
                    * (unsigned short)VR[vt].s[j | (i & 0xC)];
            VACC[i].DW += product >> 16;
        }
    else /* if (element & 0b1000) */
        for (i = 0, j = element & 07; i < 8; i++)
        {
            product = (unsigned short)VR[vs].s[i] * (unsigned short)VR[vt].s[j];
            VACC[i].DW += product >> 16;
        }
    for (i = 0; i < 8; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        if (VACC[i].DW & 0x800000000000) /* acc < 0 */
            if (~VACC[i].DW & ~0x00007FFFFFFF) /* signed underflow */
                VR[vd].s[i] = 0x0000;
            else
                VR[vd].s[i] = VACC[i].s[LO];
        else
            if (VACC[i].DW & ~0x00007FFFFFFF) /* signed overflow */
                VR[vd].s[i] = 0xFFFF;
            else
                VR[vd].s[i] = VACC[i].s[LO];
    return;
}

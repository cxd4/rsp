#include "vu.h"

/* to-do:  possible confusion of VCE with VCO & 0xFF00, might need research */

static void VEQ(int vd, int vs, int vt, int element)
{
    register int i, j;

    VCC = 0x0000;
/* Not part of the central operation, but we do this now because setting bits
 * is easier than clearing them.  `VCC |= 1 << i;` over `VCC &= ~(1 << i);`
 */
    if (element == 0x0) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            if ((VR[vs].s[i] == VR[vt].s[i]) && (VCO & (0x0100 << i)) == 0x0000)
            {
                VCC |= 0x0001 << i;
                VACC[i].s[LO] = VR[vs].s[i];
            }
            else
            {
             /* VCC &= ~(0x0001 << i); */
                VACC[i].s[LO] = VR[vt].s[i];
            }
    else if ((element & 0xE) == 02) /* scalar quarter */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            if ((VR[vs].s[i] == VR[vt].s[j]) && (VCO & (0x0100 << i)) == 0x0000)
            {
                VCC |= 0x0001 << i;
                VACC[i].s[LO] = VR[vs].s[i];
            }
            else
            {
             /* VCC &= ~(0x0001 << i); */
                VACC[i].s[LO] = VR[vt].s[j];
            }
        }
    else if ((element & 0xC) == 04) /* scalar half */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            if ((VR[vs].s[i] == VR[vt].s[j]) && (VCO & (0x0100 << i)) == 0x0000)
            {
                VCC |= 0x0001 << i;
                VACC[i].s[LO] = VR[vs].s[i];
            }
            else
            {
             /* VCC &= ~(0x0001 << i); */
                VACC[i].s[LO] = VR[vt].s[j];
            }
        }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
        for (i = 0, j = element & 07; i < 8; i++)
            if ((VR[vs].s[i] == VR[vt].s[j]) && (VCO & (0x0100 << i)) == 0x0000)
            {
                VCC |= 0x0001 << i;
                VACC[i].s[LO] = VR[vs].s[i];
            }
            else
            {
             /* VCC &= ~(0x0001 << i); */
                VACC[i].s[LO] = VR[vt].s[j];
            }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    return;
}

#include "vu.h"

static void VMOV(int vd, int de, int vt, int e)
{
    register int i, j;

    /* MovIn = (int)VR[vt][e & 07]; */
    if (!e)
        for (i = 0; i < 8; i++)
            VACC[i].s[LO] = VR[vt][j = i];
    else if (e < 4) /* e != 1 */
        for (i = 0, j = e & 01; i < 8; i++)
            VACC[i].s[LO] = VR[vt][j | (i & 0xE)];
    else if (e < 8)
        for (i = 0, j = e & 03; i < 8; i++)
            VACC[i].s[LO] = VR[vt][j | (i & 0xC)];
    else /* if (8 <= e <= 15) */
        for (i = 0, j = e & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt][j];
    de &= 07;
    VR[vd][de] = VACC[de].s[LO];
    return;
}

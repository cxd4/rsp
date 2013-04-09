#include "vu.h"

static void VABS(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        if (VR[vs][i] < 0)
            VACC[i].s[LO] = -(VR[vt][ei[e][i]] ^ (VR[vt][ei[e][i]] == 0x8000));
         /* VACC[i].s[LO] = ~VR[vt][ei[e][i]] + (VR[vt][ei[e][i]] != 0x8000); */
        else if (VR[vs][i] == 0)
            VACC[i].s[LO] = 0x0000;
        else
            VACC[i].s[LO] = +VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

#include "vu.h"

static const void VABS(int vd, int vs, int vt, int element)
{
    register int i, j;

    if (element == 00) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            if (VR[vs].s[i] < 0)
                VACC[i].s[LO] = -VR[vt].s[i];
            else if (VR[vs].s[i] == 0)
                VACC[i].s[LO] = 0x0000;
            else
                VACC[i].s[LO] = +VR[vt].s[i];
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            if (VR[vs].s[i] < 0)
                VACC[i].s[LO] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].s[LO] = 0x0000;
            else
                VACC[i].s[LO] = +VR[vt].s[j];
        }
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            if (VR[vs].s[i] < 0)
                VACC[i].s[LO] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].s[LO] = 0x0000;
            else
                VACC[i].s[LO] = +VR[vt].s[j];
        }
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        for (i = 0, j = element & 07; i < 8; i++)
            if (VR[vs].s[i] < 0)
                VACC[i].s[LO] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].s[LO] = 0x0000;
            else
                VACC[i].s[LO] = +VR[vt].s[j];
    }
    for (i = 0; i < 8; i++)
    {
        if (VACC[i].s[LO] == 0x8000)
            message("VABS element underflow.", 2);
        VR[vd].s[i] = VACC[i].s[LO];
    }
    return;
}

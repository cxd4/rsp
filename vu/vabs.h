#include "vu.h"

void VABS(int vd, int vs, int vt, int element)
{
    register int i;

    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
    }
    if (element == 00) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            if (VR[vs].s[i] < 0)
                VACC[i].w[00] = -VR[vt].s[i];
            else if (VR[vs].s[i] == 0)
                VACC[i].w[00] = 0x0000;
            else
                VACC[i].w[00] = +VR[vt].s[i];
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        register int j = element & 01;

        for (i = 0; i < 8; i++, j = (i & 0xE) | (element & 01))
            if (VR[vs].s[i] < 0)
                VACC[i].w[00] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].w[00] = 0x0000;
            else
                VACC[i].w[00] = +VR[vt].s[j];
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        register int j = element & 03;

        for (i = 0; i < 8; i++, j = (i & 0xC) | (element & 03))
            if (VR[vs].s[i] < 0)
                VACC[i].w[00] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].w[00] = 0x0000;
            else
                VACC[i].w[00] = +VR[vt].s[j];
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register int j = element & 07;

        for (i = 0; i < 8; i++)
            if (VR[vs].s[i] < 0)
                VACC[i].w[00] = -VR[vt].s[j];
            else if (VR[vs].s[i] == 0)
                VACC[i].w[00] = 0x0000;
            else
                VACC[i].w[00] = +VR[vt].s[j];
    }
    for (i = 0; i < 8; i++)
    {
        if (VACC[i].w[00] == 0x8000)
            message("VABS element underflow.", 2);
        VR[vd].s[i] = VACC[i].w[00];
    }
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    return;
}

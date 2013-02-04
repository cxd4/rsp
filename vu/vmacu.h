#include "vu.h"

void VMACU(int vd, int vs, int vt, int element)
{
    register int i = 0;

    if (element == 00) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].q += (long long)(VR[vs].s[i] * VR[vt].s[i]) << 17;
    else if ((element & 0xE) == 02) /* scalar quarter */
    {
        VACC[00].q += (long long)(VR[vs].s[00] * VR[vt].s[element - 2]) << 17;
        VACC[01].q += (long long)(VR[vs].s[01] * VR[vt].s[element - 2]) << 17;
        VACC[02].q += (long long)(VR[vs].s[02] * VR[vt].s[element | 0]) << 17;
        VACC[03].q += (long long)(VR[vs].s[03] * VR[vt].s[element | 0]) << 17;
        VACC[04].q += (long long)(VR[vs].s[04] * VR[vt].s[element + 2]) << 17;
        VACC[05].q += (long long)(VR[vs].s[05] * VR[vt].s[element + 2]) << 17;
        VACC[06].q += (long long)(VR[vs].s[06] * VR[vt].s[element + 4]) << 17;
        VACC[07].q += (long long)(VR[vs].s[07] * VR[vt].s[element + 4]) << 17;
    }
    else if ((element & 0xC) == 04) /* scalar half */
    {
        VACC[00].q += (long long)(VR[vs].s[00] * VR[vt].s[element - 4]) << 17;
        VACC[01].q += (long long)(VR[vs].s[01] * VR[vt].s[element - 4]) << 17;
        VACC[02].q += (long long)(VR[vs].s[02] * VR[vt].s[element - 4]) << 17;
        VACC[03].q += (long long)(VR[vs].s[03] * VR[vt].s[element - 4]) << 17;
        VACC[04].q += (long long)(VR[vs].s[04] * VR[vt].s[element | 0]) << 17;
        VACC[05].q += (long long)(VR[vs].s[05] * VR[vt].s[element | 0]) << 17;
        VACC[06].q += (long long)(VR[vs].s[06] * VR[vt].s[element | 0]) << 17;
        VACC[07].q += (long long)(VR[vs].s[07] * VR[vt].s[element | 0]) << 17;
    }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
    {
        const register int j = element & 07;

        for (i = 0; i < 8; i++)
            VACC[i].q += (long long)(VR[vs].s[i] * VR[vt].s[j]) << 17;
    }
    for (i = 0; i < 8; i++)
    { /* Clamp bits 31..16 of each accumulator element to the VR file. */
        if (VACC[i].q < 0)
        {
            VR[vd].s[i] = 0x0000;
            continue;
        }
        if (VACC[i].q & ~0x7FFFFFFFFFFF)
        { /* Actually & ~0x7FFFFFFF, but we have shifted accumulators. */
            VR[vd].s[i] = 0xFFFF;
            continue;
        }
        VR[vd].s[i] = VACC[i].w[MD];
    }
    return;
}

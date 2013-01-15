#include "vu.h"

void VABS(int vd, int vs, int vt, int element)
{
    register int i;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        signed short int paired_source_2 = VR[vs].s[i];
        signed short int paired_source_1 = VR[vt].s[sel];
        if (paired_source_2 > 0)
        {
            VACC[i].w[01] = paired_source_1;
            continue;
        }
        if (paired_source_2 == 0)
        {
            VACC[i].w[01] = 0x0000;
            continue;
        }
        paired_source_1 = ~paired_source_1;
        if (paired_source_1 == 0x7FFF) {} else
            ++paired_source_1;
        VACC[i].w[01] = paired_source_1;
    }
    VR[vd].s[00] = VACC[00].w[01];
    VR[vd].s[01] = VACC[01].w[01];
    VR[vd].s[02] = VACC[02].w[01];
    VR[vd].s[03] = VACC[03].w[01];
    VR[vd].s[04] = VACC[04].w[01];
    VR[vd].s[05] = VACC[05].w[01];
    VR[vd].s[06] = VACC[06].w[01];
    VR[vd].s[07] = VACC[07].w[01];
    return;
}

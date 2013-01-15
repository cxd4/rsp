#include "vu.h"

void VMADH(int vd, int vs, int vt, int element)
{ //"the low slice is zero" (ORLY?) --Ville Linde (cxd4:  to-do)
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[00];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[01];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[02];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[03];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[04];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[05];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[06];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[07];
            break;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[00];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[00];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[02];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[02];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[04];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[04];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[06];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[06];
            break;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[01];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[01];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[03];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[03];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[05];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[05];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[07];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[07];
            break;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[00];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[00];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[00];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[00];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[04];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[04];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[04];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[04];
            break;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[01];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[01];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[01];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[01];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[05];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[05];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[05];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[05];
            break;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[02];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[02];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[02];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[02];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[06];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[06];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[06];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[06];
            break;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].l[01] += VR[vs].s[00] * VR[vt].s[03];
            VACC[01].l[01] += VR[vs].s[01] * VR[vt].s[03];
            VACC[02].l[01] += VR[vs].s[02] * VR[vt].s[03];
            VACC[03].l[01] += VR[vs].s[03] * VR[vt].s[03];
            VACC[04].l[01] += VR[vs].s[04] * VR[vt].s[07];
            VACC[05].l[01] += VR[vs].s[05] * VR[vt].s[07];
            VACC[06].l[01] += VR[vs].s[06] * VR[vt].s[07];
            VACC[07].l[01] += VR[vs].s[07] * VR[vt].s[07];
            break;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */{
            register signed short multiplier = VR[vt].s[element & 07];
            VACC[00].l[01] += VR[vs].s[00] * multiplier;
            VACC[01].l[01] += VR[vs].s[01] * multiplier;
            VACC[02].l[01] += VR[vs].s[02] * multiplier;
            VACC[03].l[01] += VR[vs].s[03] * multiplier;
            VACC[04].l[01] += VR[vs].s[04] * multiplier;
            VACC[05].l[01] += VR[vs].s[05] * multiplier;
            VACC[06].l[01] += VR[vs].s[06] * multiplier;
            VACC[07].l[01] += VR[vs].s[07] * multiplier;
            break;
        }
    }
    VR[vd].s[00] = SIGNED_CLAMP(VACC[00].l[01]);
    VR[vd].s[01] = SIGNED_CLAMP(VACC[01].l[01]);
    VR[vd].s[02] = SIGNED_CLAMP(VACC[02].l[01]);
    VR[vd].s[03] = SIGNED_CLAMP(VACC[03].l[01]);
    VR[vd].s[04] = SIGNED_CLAMP(VACC[04].l[01]);
    VR[vd].s[05] = SIGNED_CLAMP(VACC[05].l[01]);
    VR[vd].s[06] = SIGNED_CLAMP(VACC[06].l[01]);
    VR[vd].s[07] = SIGNED_CLAMP(VACC[07].l[01]);
    return;
}

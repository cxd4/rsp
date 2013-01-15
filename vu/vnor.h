#include "vu.h"

void VNOR(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VR[vd].d[00] = ~(VR[vs].d[00] | VR[vt].d[00]);
            VR[vd].d[01] = ~(VR[vs].d[01] | VR[vt].d[01]);
            VACC[00].w[01] = VR[vd].s[00];
            VACC[01].w[01] = VR[vd].s[01];
            VACC[02].w[01] = VR[vd].s[02];
            VACC[03].w[01] = VR[vd].s[03];
            VACC[04].w[01] = VR[vd].s[04];
            VACC[05].w[01] = VR[vd].s[05];
            VACC[06].w[01] = VR[vd].s[06];
            VACC[07].w[01] = VR[vd].s[07];
            return;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[00]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[00]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[02]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[02]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[04]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[04]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[06]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[06]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[01]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[01]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[03]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[03]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[05]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[05]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[07]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[07]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[00]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[00]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[00]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[00]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[04]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[04]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[04]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[04]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[01]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[01]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[01]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[01]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[05]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[05]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[05]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[05]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[02]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[02]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[02]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[02]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[06]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[06]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[06]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[06]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[03]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[03]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[03]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[03]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[07]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[07]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[07]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[07]);
            VR[vd].s[00] = VACC[00].w[01];
            VR[vd].s[01] = VACC[01].w[01];
            VR[vd].s[02] = VACC[02].w[01];
            VR[vd].s[03] = VACC[03].w[01];
            VR[vd].s[04] = VACC[04].w[01];
            VR[vd].s[05] = VACC[05].w[01];
            VR[vd].s[06] = VACC[06].w[01];
            VR[vd].s[07] = VACC[07].w[01];
            return;
        case 0x8: /* { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* { 07, 07, 07, 07, 07, 07, 07, 07 } */
            element &= 07;
            VACC[00].w[01] = ~(VR[vs].s[00] | VR[vt].s[element]);
            VACC[01].w[01] = ~(VR[vs].s[01] | VR[vt].s[element]);
            VACC[02].w[01] = ~(VR[vs].s[02] | VR[vt].s[element]);
            VACC[03].w[01] = ~(VR[vs].s[03] | VR[vt].s[element]);
            VACC[04].w[01] = ~(VR[vs].s[04] | VR[vt].s[element]);
            VACC[05].w[01] = ~(VR[vs].s[05] | VR[vt].s[element]);
            VACC[06].w[01] = ~(VR[vs].s[06] | VR[vt].s[element]);
            VACC[07].w[01] = ~(VR[vs].s[07] | VR[vt].s[element]);
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
}

#include "vu.h"

void VMUDL(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[00]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[01]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[02]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[03]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[04]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[05]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[06]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[07]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[00]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[00]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[02]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[02]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[04]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[04]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[06]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[06]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[01]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[01]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[03]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[03]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[05]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[05]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[07]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[07]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[00]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[00]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[00]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[00]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[04]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[04]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[04]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[04]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[01]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[01]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[01]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[01]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[05]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[05]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[05]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[05]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[02]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[02]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[02]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[02]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[06]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[06]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[06]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[06]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * (unsigned short)VR[vt].s[03]);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * (unsigned short)VR[vt].s[03]);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * (unsigned short)VR[vt].s[03]);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * (unsigned short)VR[vt].s[03]);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * (unsigned short)VR[vt].s[07]);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * (unsigned short)VR[vt].s[07]);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * (unsigned short)VR[vt].s[07]);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * (unsigned short)VR[vt].s[07]);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */{
            register unsigned short multiplier = VR[vt].s[element & 07];
            VACC[00].q = (unsigned long)((unsigned short)VR[vs].s[00] * multiplier);
            VACC[01].q = (unsigned long)((unsigned short)VR[vs].s[01] * multiplier);
            VACC[02].q = (unsigned long)((unsigned short)VR[vs].s[02] * multiplier);
            VACC[03].q = (unsigned long)((unsigned short)VR[vs].s[03] * multiplier);
            VACC[04].q = (unsigned long)((unsigned short)VR[vs].s[04] * multiplier);
            VACC[05].q = (unsigned long)((unsigned short)VR[vs].s[05] * multiplier);
            VACC[06].q = (unsigned long)((unsigned short)VR[vs].s[06] * multiplier);
            VACC[07].q = (unsigned long)((unsigned short)VR[vs].s[07] * multiplier);
            VR[vd].s[00] = VACC[00].w[LO];
            VR[vd].s[01] = VACC[01].w[LO];
            VR[vd].s[02] = VACC[02].w[LO];
            VR[vd].s[03] = VACC[03].w[LO];
            VR[vd].s[04] = VACC[04].w[LO];
            VR[vd].s[05] = VACC[05].w[LO];
            VR[vd].s[06] = VACC[06].w[LO];
            VR[vd].s[07] = VACC[07].w[LO];
            return;
        }
    }
}

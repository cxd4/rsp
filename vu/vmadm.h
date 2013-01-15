#include "vu.h"

void VMADM(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[06]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[04]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[05]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[06]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].q += (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            goto CLAMP_TO_VR_FILE;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */{
            register unsigned short source = VR[vt].s[element & 07];
            VACC[00].q += (long long)(VR[vs].s[00] * source) << 16;
            VACC[01].q += (long long)(VR[vs].s[01] * source) << 16;
            VACC[02].q += (long long)(VR[vs].s[02] * source) << 16;
            VACC[03].q += (long long)(VR[vs].s[03] * source) << 16;
            VACC[04].q += (long long)(VR[vs].s[04] * source) << 16;
            VACC[05].q += (long long)(VR[vs].s[05] * source) << 16;
            VACC[06].q += (long long)(VR[vs].s[06] * source) << 16;
            VACC[07].q += (long long)(VR[vs].s[07] * source) << 16;
            goto CLAMP_TO_VR_FILE;
        }
    }
CLAMP_TO_VR_FILE:
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

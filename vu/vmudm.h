#include "vu.h"

void VMUDM(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x2:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[06]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x3:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x4:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[00]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[04]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[04]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x5:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[01]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[05]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[05]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x6:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[02]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[06]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[06]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x7:
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[03]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[07]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[07]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
            element &= 07;
            VACC[00].q = (long long)(VR[vs].s[00] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[01].q = (long long)(VR[vs].s[01] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[02].q = (long long)(VR[vs].s[02] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[03].q = (long long)(VR[vs].s[03] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[04].q = (long long)(VR[vs].s[04] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[05].q = (long long)(VR[vs].s[05] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[06].q = (long long)(VR[vs].s[06] * (unsigned short)VR[vt].s[element]) << 16;
            VACC[07].q = (long long)(VR[vs].s[07] * (unsigned short)VR[vt].s[element]) << 16;
            VR[vd].s[00] = VACC[00].w[02];
            VR[vd].s[01] = VACC[01].w[02];
            VR[vd].s[02] = VACC[02].w[02];
            VR[vd].s[03] = VACC[03].w[02];
            VR[vd].s[04] = VACC[04].w[02];
            VR[vd].s[05] = VACC[05].w[02];
            VR[vd].s[06] = VACC[06].w[02];
            VR[vd].s[07] = VACC[07].w[02];
            return;
    }
}

#include "vu.h"

void VMOV(int vd, int del, int vt, int element)
{
    register int sel;
    del &= 07;

    sel = element_index[element][del ^ 07];
    VR[vd].s[del] = VR[vt].s[sel];
/*
    switch (element)
    {
        case 0x0:
        case 0x1:
            VACC[00].w[LO] = VR[vt].s[00];
            VACC[01].w[LO] = VR[vt].s[01];
            VACC[02].w[LO] = VR[vt].s[02];
            VACC[03].w[LO] = VR[vt].s[03];
            VACC[04].w[LO] = VR[vt].s[04];
            VACC[05].w[LO] = VR[vt].s[05];
            VACC[06].w[LO] = VR[vt].s[06];
            VACC[07].w[LO] = VR[vt].s[07];
            return;
        case 0x2:
            VACC[00].w[LO] = VR[vt].s[00];
            VACC[01].w[LO] = VR[vt].s[00];
            VACC[02].w[LO] = VR[vt].s[02];
            VACC[03].w[LO] = VR[vt].s[02];
            VACC[04].w[LO] = VR[vt].s[04];
            VACC[05].w[LO] = VR[vt].s[04];
            VACC[06].w[LO] = VR[vt].s[06];
            VACC[07].w[LO] = VR[vt].s[06];
            return;
        case 0x3:
            VACC[00].w[LO] = VR[vt].s[01];
            VACC[01].w[LO] = VR[vt].s[01];
            VACC[02].w[LO] = VR[vt].s[03];
            VACC[03].w[LO] = VR[vt].s[03];
            VACC[04].w[LO] = VR[vt].s[05];
            VACC[05].w[LO] = VR[vt].s[05];
            VACC[06].w[LO] = VR[vt].s[07];
            VACC[07].w[LO] = VR[vt].s[07];
            return;
        case 0x4:
            VACC[00].w[LO] = VR[vt].s[00];
            VACC[01].w[LO] = VR[vt].s[00];
            VACC[02].w[LO] = VR[vt].s[00];
            VACC[03].w[LO] = VR[vt].s[00];
            VACC[04].w[LO] = VR[vt].s[04];
            VACC[05].w[LO] = VR[vt].s[04];
            VACC[06].w[LO] = VR[vt].s[04];
            VACC[07].w[LO] = VR[vt].s[04];
            return;
        case 0x5:
            VACC[00].w[LO] = VR[vt].s[01];
            VACC[01].w[LO] = VR[vt].s[01];
            VACC[02].w[LO] = VR[vt].s[01];
            VACC[03].w[LO] = VR[vt].s[01];
            VACC[04].w[LO] = VR[vt].s[05];
            VACC[05].w[LO] = VR[vt].s[05];
            VACC[06].w[LO] = VR[vt].s[05];
            VACC[07].w[LO] = VR[vt].s[05];
            return;
        case 0x6:
            VACC[00].w[LO] = VR[vt].s[02];
            VACC[01].w[LO] = VR[vt].s[02];
            VACC[02].w[LO] = VR[vt].s[02];
            VACC[03].w[LO] = VR[vt].s[02];
            VACC[04].w[LO] = VR[vt].s[06];
            VACC[05].w[LO] = VR[vt].s[06];
            VACC[06].w[LO] = VR[vt].s[06];
            VACC[07].w[LO] = VR[vt].s[06];
            return;
        case 0x7:
            VACC[00].w[LO] = VR[vt].s[03];
            VACC[01].w[LO] = VR[vt].s[03];
            VACC[02].w[LO] = VR[vt].s[03];
            VACC[03].w[LO] = VR[vt].s[03];
            VACC[04].w[LO] = VR[vt].s[07];
            VACC[05].w[LO] = VR[vt].s[07];
            VACC[06].w[LO] = VR[vt].s[07];
            VACC[07].w[LO] = VR[vt].s[07];
            return;
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        {
            register short source = VR[vt].s[sel];
            VACC[00].w[LO] = source;
            VACC[01].w[LO] = source;
            VACC[02].w[LO] = source;
            VACC[03].w[LO] = source;
            VACC[04].w[LO] = source;
            VACC[05].w[LO] = source;
            VACC[06].w[LO] = source;
            VACC[07].w[LO] = source;
            return;
        }
    }
*/
}

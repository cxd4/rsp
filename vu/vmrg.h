#include "vu.h"

void VMRG(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[00];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[01];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[02];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[03];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[04];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[05];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[06];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[07];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[00];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[00];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[02];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[02];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[04];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[04];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[06];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[06];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[01];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[01];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[03];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[03];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[05];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[05];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[07];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[07];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[00];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[00];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[00];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[00];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[04];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[04];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[04];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[04];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[01];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[01];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[01];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[01];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[05];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[05];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[05];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[05];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x6: /* 2Q:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[02];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[02];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[02];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[02];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[06];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[06];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[06];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[06];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x7: /* 3Q:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : VR[vt].s[03];
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : VR[vt].s[03];
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : VR[vt].s[03];
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : VR[vt].s[03];
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : VR[vt].s[07];
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : VR[vt].s[07];
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : VR[vt].s[07];
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : VR[vt].s[07];
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */{
            register short source = VR[vt].s[element & 07];
            VACC[00].w[LO] = (VCF[01] & 0x0001) ? VR[vs].s[00] : source;
            VACC[01].w[LO] = (VCF[01] & 0x0002) ? VR[vs].s[01] : source;
            VACC[02].w[LO] = (VCF[01] & 0x0004) ? VR[vs].s[02] : source;
            VACC[03].w[LO] = (VCF[01] & 0x0008) ? VR[vs].s[03] : source;
            VACC[04].w[LO] = (VCF[01] & 0x0010) ? VR[vs].s[04] : source;
            VACC[05].w[LO] = (VCF[01] & 0x0020) ? VR[vs].s[05] : source;
            VACC[06].w[LO] = (VCF[01] & 0x0040) ? VR[vs].s[06] : source;
            VACC[07].w[LO] = (VCF[01] & 0x0080) ? VR[vs].s[07] : source;
            goto STORE_ACCUMULATOR_RESULTS;
        }
    }
STORE_ACCUMULATOR_RESULTS:
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

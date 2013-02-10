#include "vu.h"

void VRSQL(int vd, int del, int vt, int element)
{
    register int i;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif
    register int sel = element & 07; /* sel = element_index[element][del]; */
    register int sqr = rsp.square_root_high;

    sqr <<= 16;
    sqr  |= (unsigned short)VR[vt].s[sel];
    if (sqr == 0)
    { // square root on 0 -> overflow
        sqr = 0x7FFFFFFF;
    }
    else if (sqr == 0xFFFF8000)
    { // overflow ?
        sqr = 0xFFFF0000;
    }
    else
    {
        int negative = 0;
        if (sqr < 0)
        {
            negative = 1;
            sqr = ~sqr;
            if ((sqr & 0xFFFF8000) == 0x00000000)
            {
                ++sqr;
            }
        }
#ifdef FP_CORRECTIONS
        old_model = _controlfp(_RC_CHOP, _MCW_RC);
#endif
        sqr = (int)(0x7FFFFFFF / sqrt(sqr)); /* `sqrtf` instead of `sqrt`? */
#ifdef FP_CORRECTIONS
        old_model = _controlfp(old_model, _MCW_RC);
#endif

        if (negative)
        {
            sqr = ~sqr;
        }
    }
    switch (element)
    {
        case 0x0:
        case 0x1:
            VACC[00].w[00] = VR[vt].s[00];
            VACC[01].w[00] = VR[vt].s[01];
            VACC[02].w[00] = VR[vt].s[02];
            VACC[03].w[00] = VR[vt].s[03];
            VACC[04].w[00] = VR[vt].s[04];
            VACC[05].w[00] = VR[vt].s[05];
            VACC[06].w[00] = VR[vt].s[06];
            VACC[07].w[00] = VR[vt].s[07];
            break;
        case 0x2:
            VACC[00].w[00] = VR[vt].s[00];
            VACC[01].w[00] = VR[vt].s[00];
            VACC[02].w[00] = VR[vt].s[02];
            VACC[03].w[00] = VR[vt].s[02];
            VACC[04].w[00] = VR[vt].s[04];
            VACC[05].w[00] = VR[vt].s[04];
            VACC[06].w[00] = VR[vt].s[06];
            VACC[07].w[00] = VR[vt].s[06];
            break;
        case 0x3:
            VACC[00].w[00] = VR[vt].s[01];
            VACC[01].w[00] = VR[vt].s[01];
            VACC[02].w[00] = VR[vt].s[03];
            VACC[03].w[00] = VR[vt].s[03];
            VACC[04].w[00] = VR[vt].s[05];
            VACC[05].w[00] = VR[vt].s[05];
            VACC[06].w[00] = VR[vt].s[07];
            VACC[07].w[00] = VR[vt].s[07];
            break;
        case 0x4:
            VACC[00].w[00] = VR[vt].s[00];
            VACC[01].w[00] = VR[vt].s[00];
            VACC[02].w[00] = VR[vt].s[00];
            VACC[03].w[00] = VR[vt].s[00];
            VACC[04].w[00] = VR[vt].s[04];
            VACC[05].w[00] = VR[vt].s[04];
            VACC[06].w[00] = VR[vt].s[04];
            VACC[07].w[00] = VR[vt].s[04];
            break;
        case 0x5:
            VACC[00].w[00] = VR[vt].s[01];
            VACC[01].w[00] = VR[vt].s[01];
            VACC[02].w[00] = VR[vt].s[01];
            VACC[03].w[00] = VR[vt].s[01];
            VACC[04].w[00] = VR[vt].s[05];
            VACC[05].w[00] = VR[vt].s[05];
            VACC[06].w[00] = VR[vt].s[05];
            VACC[07].w[00] = VR[vt].s[05];
            break;
        case 0x6:
            VACC[00].w[00] = VR[vt].s[02];
            VACC[01].w[00] = VR[vt].s[02];
            VACC[02].w[00] = VR[vt].s[02];
            VACC[03].w[00] = VR[vt].s[02];
            VACC[04].w[00] = VR[vt].s[06];
            VACC[05].w[00] = VR[vt].s[06];
            VACC[06].w[00] = VR[vt].s[06];
            VACC[07].w[00] = VR[vt].s[06];
            break;
        case 0x7:
            VACC[00].w[00] = VR[vt].s[03];
            VACC[01].w[00] = VR[vt].s[03];
            VACC[02].w[00] = VR[vt].s[03];
            VACC[03].w[00] = VR[vt].s[03];
            VACC[04].w[00] = VR[vt].s[07];
            VACC[05].w[00] = VR[vt].s[07];
            VACC[06].w[00] = VR[vt].s[07];
            VACC[07].w[00] = VR[vt].s[07];
            break;
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:{
            register short source = VR[vt].s[sel];
            VACC[00].w[00] = source;
            VACC[01].w[00] = source;
            VACC[02].w[00] = source;
            VACC[03].w[00] = source;
            VACC[04].w[00] = source;
            VACC[05].w[00] = source;
            VACC[06].w[00] = source;
            VACC[07].w[00] = source;
            break;
        }
    }
    rsp.square_root_res = sqr;
    VR[vd].s[del & 07] = (short)rsp.square_root_res; /* store low part */
    return;
}

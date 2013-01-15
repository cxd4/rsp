#include "vu.h"

void VRCP(int vd, int del, int vt, int element)
{
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif
    register int sel = element & 07; /* Недавнее предполож-е Мугли */
    register int rec = (signed short)VR[vt].s[sel];

    if (rec == 0)
    { // divide by zero -> overflow
        rec = 0x7FFFFFFF;
    }
    else
    {
        int negative = 0;
        if (rec < 0)
        {
            rec = ~rec; /* NOT(rec) followed by INC(rec), ... */
            ++rec; /* ... I believe is the same as just NEG(rec) ? */
            negative = 1;
        }
/* Old rounding code used in older zilmar RSP plugins.
        for (i = 15; i > 0; i--)
        {
            if (rec & (1 << i))
            {
                rec &= ((0xffc0) >> (15 - i));
                i = 0;
            }
        }
*/
#ifdef FP_CORRECTIONS
        old_model = _controlfp(_RC_CHOP, _MCW_RC);
#endif
        rec = (signed int)(0x7FFFFFFF / (double)rec);
#ifdef FP_CORRECTIONS
        old_model = _controlfp(old_model, _MCW_RC);
#endif
/* I am not sure what the newer method is exactly, but this is used for sqrt.
        for (i = 31; i > 0; i--)
        {
            if (rec & (1 << i))
            {
                rec &= ((0xffff8000) >> (31 - i));
                i = 0;
            }
        }
*/
        if (negative)
        {
            rec = ~rec;
        }
    }
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
            break;
        case 0x2:
            VACC[00].w[LO] = VR[vt].s[00];
            VACC[01].w[LO] = VR[vt].s[00];
            VACC[02].w[LO] = VR[vt].s[02];
            VACC[03].w[LO] = VR[vt].s[02];
            VACC[04].w[LO] = VR[vt].s[04];
            VACC[05].w[LO] = VR[vt].s[04];
            VACC[06].w[LO] = VR[vt].s[06];
            VACC[07].w[LO] = VR[vt].s[06];
            break;
        case 0x3:
            VACC[00].w[LO] = VR[vt].s[01];
            VACC[01].w[LO] = VR[vt].s[01];
            VACC[02].w[LO] = VR[vt].s[03];
            VACC[03].w[LO] = VR[vt].s[03];
            VACC[04].w[LO] = VR[vt].s[05];
            VACC[05].w[LO] = VR[vt].s[05];
            VACC[06].w[LO] = VR[vt].s[07];
            VACC[07].w[LO] = VR[vt].s[07];
            break;
        case 0x4:
            VACC[00].w[LO] = VR[vt].s[00];
            VACC[01].w[LO] = VR[vt].s[00];
            VACC[02].w[LO] = VR[vt].s[00];
            VACC[03].w[LO] = VR[vt].s[00];
            VACC[04].w[LO] = VR[vt].s[04];
            VACC[05].w[LO] = VR[vt].s[04];
            VACC[06].w[LO] = VR[vt].s[04];
            VACC[07].w[LO] = VR[vt].s[04];
            break;
        case 0x5:
            VACC[00].w[LO] = VR[vt].s[01];
            VACC[01].w[LO] = VR[vt].s[01];
            VACC[02].w[LO] = VR[vt].s[01];
            VACC[03].w[LO] = VR[vt].s[01];
            VACC[04].w[LO] = VR[vt].s[05];
            VACC[05].w[LO] = VR[vt].s[05];
            VACC[06].w[LO] = VR[vt].s[05];
            VACC[07].w[LO] = VR[vt].s[05];
            break;
        case 0x6:
            VACC[00].w[LO] = VR[vt].s[02];
            VACC[01].w[LO] = VR[vt].s[02];
            VACC[02].w[LO] = VR[vt].s[02];
            VACC[03].w[LO] = VR[vt].s[02];
            VACC[04].w[LO] = VR[vt].s[06];
            VACC[05].w[LO] = VR[vt].s[06];
            VACC[06].w[LO] = VR[vt].s[06];
            VACC[07].w[LO] = VR[vt].s[06];
            break;
        case 0x7:
            VACC[00].w[LO] = VR[vt].s[03];
            VACC[01].w[LO] = VR[vt].s[03];
            VACC[02].w[LO] = VR[vt].s[03];
            VACC[03].w[LO] = VR[vt].s[03];
            VACC[04].w[LO] = VR[vt].s[07];
            VACC[05].w[LO] = VR[vt].s[07];
            VACC[06].w[LO] = VR[vt].s[07];
            VACC[07].w[LO] = VR[vt].s[07];
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
            VACC[00].w[LO] = source;
            VACC[01].w[LO] = source;
            VACC[02].w[LO] = source;
            VACC[03].w[LO] = source;
            VACC[04].w[LO] = source;
            VACC[05].w[LO] = source;
            VACC[06].w[LO] = source;
            VACC[07].w[LO] = source;
            break;
        }
    }
    rsp.reciprocal_res = rec;
    VR[vd].s[del & 07] = (short)rsp.reciprocal_res; /* store low part */
    return;
}

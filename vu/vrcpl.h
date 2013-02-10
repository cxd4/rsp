#include "vu.h"

void VRCPL(int vd, int del, int vt, int element)
{
    register int i;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif
    register int sel = element & 07; /* element_index[element][del]; */
    register int rec = rsp.reciprocal_high;

    rec <<= 16;
    rec  |= (unsigned short)VR[vt].s[sel];
    if (rec == 0)
    { // divide by zero -> overflow
        rec = 0x7FFFFFFF;
    }
    else
    {
        int negative = 0;
        if (rec < 0)
        {
            negative = 1;
            rec = ~rec;
            if ((rec & 0xFFFF8000) == 0x00000000)
            {
                ++rec;
            }
        }
/* Goodie.  More controversial rounding.
        for (i = 31; i > 0; i--)
        {
            if (rec & (1 << i))
            {
                rec &= ((0xFFC00000) >> (31 - i));
                i = 0;
            }
        }
*/
#ifdef FP_CORRECTIONS
        old_model = _controlfp(_RC_CHOP, _MCW_RC);
#endif
        rec = 0x7FFFFFFF / rec;
#ifdef FP_CORRECTIONS
        old_model = _controlfp(old_model, _MCW_RC);
#endif
/* Nuh-uh!!
        for (i = 31; i > 0; i--)
        {
            if (rec & (1 << i))
            {
                rec &= ((0xFFFF8000) >> (31 - i));
                i = 0;
            }
        }
*/
        if (negative)
        {
            rec = ~rec;
        }
    }
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q >>= 16;
        /* VACC[i].q <<= 16; // undo zilmar's ACC hack */
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
    for (i = 0; i < 8; i++)
    { /* 48 bits left by 16 to use high DW sign bit */
        VACC[i].q <<= 16;
        /* VACC[i].q >>= 16; */
    }
    rsp.reciprocal_res = rec;
    VR[vd].s[del & 07] = (short)rsp.reciprocal_res; /* store low part */
    return;
}

#include "vu.h"

void VRSQL(int vd, int del, int vt, int element)
{
    register int i, j;
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
    if (element == 0x0) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[i];
    else if ((element & 0xE) == 02) /* scalar quarter */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xE) | (element & 01);
            VACC[i].s[LO] = VR[vt].s[j];
        }
    else if ((element & 0xC) == 04) /* scalar half */
        for (i = 0; i < 8; i++)
        {
            j = (i & 0xC) | (element & 03);
            VACC[i].s[LO] = VR[vt].s[j];
        }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
        for (i = 0, j = element & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j];
    rsp.square_root_res = sqr;
    VR[vd].s[del & 07] = (short)rsp.square_root_res; /* store low part */
    return;
}

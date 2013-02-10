#include "vu.h"

void VRCPL(int vd, int del, int vt, int element)
{
    register int i, j;
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
    rsp.reciprocal_res = rec;
    VR[vd].s[del & 07] = (short)rsp.reciprocal_res; /* store low part */
    return;
}

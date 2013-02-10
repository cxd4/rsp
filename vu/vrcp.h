#include "vu.h"

void VRCP(int vd, int del, int vt, int element)
{
    register int i, j;
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

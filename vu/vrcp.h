#include "vu.h"
#include "divrom.h"

static const void VRCP(int vd, int del, int vt, int e)
{
    register int i, j;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif
    register int rec;

    DivIn = (int)VR[vt].s[e & 07];
    rec = DivIn;
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
    if (!e)
        for (i = 0; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j = i];
    else if (e < 4) /* e != 1 */
        for (i = 0, j = e & 01; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j | (i & 0xE)];
    else if (e < 8)
        for (i = 0, j = e & 03; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j | (i & 0xC)];
    else /* if (8 <= e <= 15) */
        for (i = 0, j = e & 07; i < 8; i++)
            VACC[i].s[LO] = VR[vt].s[j];
    DivOut = rec;
    VR[vd].s[del & 07] = (short)DivOut; /* store low part */
    DPH = 0;
    return;
}

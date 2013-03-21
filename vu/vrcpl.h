#include "vu.h"
#include "divrom.h"

static void VRCPL(int vd, int de, int vt, int e)
{
    register int rec;
    register int i;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif

    DivIn = DPH
          ? DivIn | (unsigned short)VR[vt][e & 07]
          : (int)VR[vt][e & 07];
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
        VACC[i].s[LO] = VR[vt][ei[e][i]];
    DivOut = rec;
    VR[vd][de &= 07] = (short)DivOut; /* store low part */
    DPH = 0;
    return;
}

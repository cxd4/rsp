#include "vu.h"
#include "divrom.h"
#include "math.h" // temp until fixed correct FP precision

static void VRSQL(int vd, int del, int vt, int e)
{
    register int sqr;
    register int i, j;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif

    DivIn = DPH
          ? DivIn | (unsigned short)VR[vt].s[e & 07]
          : (int)VR[vt].s[e & 07];
    sqr = DivIn;
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
        sqr = (int)(0x7FFFFFFF / sqrtf(sqr)); /* `sqrtf` instead of `sqrt`? */
#ifdef FP_CORRECTIONS
        old_model = _controlfp(old_model, _MCW_RC);
#endif

        if (negative)
        {
            sqr = ~sqr;
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
    DivOut = sqr;
    VR[vd].s[del & 07] = (short)DivOut;
    DPH = 0;
    return;
}

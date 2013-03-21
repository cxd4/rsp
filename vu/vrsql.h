#include <math.h>
#include "vu.h"
#include "divrom.h"

static void VRSQL(int vd, int de, int vt, int e)
{
    register int sqr;
    register int i;
#ifdef FP_CORRECTIONS
    unsigned int old_model;
#endif

    DivIn = DPH
          ? DivIn | (unsigned short)VR[vt][e & 07]
          : (int)VR[vt][e & 07];
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
        sqr = (int)(0x7FFFFFFF / sqrtf(sqr));
#ifdef FP_CORRECTIONS
        old_model = _controlfp(old_model, _MCW_RC);
#endif

        if (negative)
        {
            sqr = ~sqr;
        }
    }
    for (i = 0; i < 8; i++)
        VACC[i].s[LO] = VR[vt][ei[e][i]];
    DivOut = sqr;
    VR[vd][de &= 07] = (short)DivOut;
    DPH = 0;
    return;
}

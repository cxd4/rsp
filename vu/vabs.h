#include "vu.h"

static void VABS(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        if (VR[vs][i] < 0)
            VACC[i].s[LO] = -(VR[vt][ei[e][i]] ^ (VR[vt][ei[e][i]] == 0x8000));
        else if (VR[vs][i] == 0)
            VACC[i].s[LO] = 0x0000;
        else
            VACC[i].s[LO] = +VR[vt][ei[e][i]];
    for (i = 0; i < 8; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

/*
 * Note about fetching the additive inverse of 16-bit integers.
 *
 * On Intel, the effective formula for negating `x` is:
 * f(x) = ~(x) + 1 # or, f(x) = ~(x - 1)
 *
 * While this effectively negatives almost every integer correctly, there is
 * an abstract corner case representing negative infinity:  0x8000 or -32768.
 *
 * Since abs(-Inf) = +Inf we should make sure to take -0x8000^01, not 0x8000.
 * In that case, the binary Intel formula fails where the SP vector succeeds.
 */

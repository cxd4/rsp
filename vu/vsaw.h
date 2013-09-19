#include "vu.h"

#ifdef VU_EMULATE_SCALAR_ACCUMULATOR_READ
static void VSAR(int vd, int vs, int vt, int e)
{
    short oldval[N];
    register int i;

    for (i = 0; i < N; i++)
        oldval[i] = VR[vs][i];
    vt = 0;
/* Even though VT is ignored in VSAR, according to official sources as well
 * as reversing, lots of games seem to specify it as non-zero, possibly to
 * avoid register stalling or other VU hazards.  Not really certain why yet.
 */
    e ^= 0x8;
/* Or, for exception overrides, should this be `e &= 0x7;` ?
 * Currently this code is safer because &= is less likely to catch oddities.
 * Either way, documentation shows that the switch range is 0:2, not 8:A.
 */
    if (e > 2)
    {
        message("VSAR\nInvalid mask.", 2);
        for (i = 0; i < N; i++)
            VR[vd][i] = 0x0000; /* override behavior (zilmar) */
    }
    else
        for (i = 0; i < N; i++)
            VR[vd][i] = VACC[e][i];
    for (i = 0; i < N; i++)
        VACC[e][i] = oldval[i]; /* ... = VS */
    return;
}
#endif

static void VSAWH(void)
{
    const int vd = inst.R.sa;

    memcpy(VR[vd], VACC_H, N*sizeof(short));
    return;
}
static void VSAWM(void)
{
    const int vd = inst.R.sa;

    memcpy(VR[vd], VACC_M, N*sizeof(short));
    return;
}
static void VSAWL(void)
{
    const int vd = inst.R.sa;

    memcpy(VR[vd], VACC_L, N*sizeof(short));
    return;
}

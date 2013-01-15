#include "vu.h"

void VSAW(int vd, int vs, int vt, int element)
{
    register int i;
#ifdef VU_EMULATE_SCALAR_ACCUMULATOR_READ
    short result[8]; /* Prebuffer VR[vs] to prevent source overwrite. */

    for (i = 0; i < 8; i++)
        result[i] = VR[vs].s[i];
#else
    vs = 0;
#endif
    vt = 0;
/* Even though `vt` is ignored in VSAR, according to official sources as well
 * as reversing, lots of games seem to specify it as nonzero, possibly to
 * avoid register stalling or other VU hazards.  Not really certain why yet.
 */
    element ^= 0x8;
/* Or, for exception overrides, should this be `element &= 0x7;` ?
 * Currently this code is safer because &= is less likely to catch oddities.
 * Either way, documentation shows that the switch range is 0:2, not 8:A.
 */
    if (element > 2)
    { /* Corrupt instruction or not assembled by an assembler. */
        for (i = 0; i < 8; i++)
            VR[vd].s[i] = 0;
#ifdef VU_EMULATE_SCALAR_ACCUMULATOR_READ
        message("VSAR", 3);
#endif
        return;
    }
    element ^= 03; /* accumulator indexing using 3:1, not 0:2 */
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].w[element];
#ifdef VU_EMULATE_SCALAR_ACCUMULATOR_READ
    for (i = 0; i < 8; i++)
        VACC[i].w[element] = result[i]; /* ... = VR[vs].s[i]; */
#endif
    return;
}

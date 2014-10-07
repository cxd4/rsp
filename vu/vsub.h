/******************************************************************************\
* Authors:  Iconoclast                                                         *
* Release:  2014.08.13                                                         *
* License:  CC0 Public Domain Dedication                                       *
*                                                                              *
* To the extent possible under law, the author(s) have dedicated all copyright *
* and related and neighboring rights to this software to the public domain     *
* worldwide. This software is distributed without any warranty.                *
*                                                                              *
* You should have received a copy of the CC0 Public Domain Dedication along    *
* with this software.                                                          *
* If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.             *
\******************************************************************************/
#include "vu.h"

INLINE static void clr_bi(short* VD, short* VS, short* VT)
{ /* clear CARRY and borrow in to accumulators */
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VS[i] - VT[i] - co[i];
    SIGNED_CLAMP_SUB(VD, VS, VT);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

VECTOR_OPERATION VSUB(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(__m128i *)VD = vd;
    *(__m128i *)VS = vs;
    *(__m128i *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    clr_bi(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(__m128i *)VD;
#endif
    return (vd);
}

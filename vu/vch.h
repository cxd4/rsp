/******************************************************************************\
* Project:  C Interpretation of Vector Select Clip Test High                   *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.07                                                         *
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

INLINE static void do_ch(short* VD, short* VS, short* VT)
{
    ALIGNED short VC[N];
    ALIGNED short eq[N], ge[N], le[N];
    ALIGNED short sn[N];
#ifndef _DEBUG
    short diff[N];
#endif
    register int i;

    vector_copy(VC, VT);
    for (i = 0; i < N; i++)
        sn[i] = VS[i] ^ VT[i];
    for (i = 0; i < N; i++)
        sn[i] = (sn[i] < 0) ? ~0 :  0; /* signed SRA (sn), 15 */
    for (i = 0; i < N; i++)
        VC[i] ^= sn[i]; /* if (sn == ~0) {VT = ~VT;} else {VT =  VT;} */
    for (i = 0; i < N; i++)
        vce[i]  = (VS[i] == VC[i]); /* 2's complement:  VC = -VT - 1, or ~VT. */
    for (i = 0; i < N; i++)
        vce[i] &= sn[i];
    for (i = 0; i < N; i++)
        VC[i] -= sn[i]; /* converts ~(VT) into -(VT) if (sign) */
    for (i = 0; i < N; i++)
        eq[i]  = (VS[i] == VC[i]);
    for (i = 0; i < N; i++)
        eq[i] |= vce[i];

#ifdef _DEBUG
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VS[i] <= VC[i]) : (VC[i] < 0);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (VC[i] > 0x0000) : (VS[i] >= VC[i]);
#elif (0)
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VT[i] <= -VS[i]) : (VT[i] <= ~0x0000);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (~0x0000 >= VT[i]) : (VS[i] >= VT[i]);
#else
    for (i = 0; i < N; i++)
        diff[i] = sn[i] | VS[i];
    for (i = 0; i < N; i++)
        ge[i] = (diff[i] >= VT[i]);

    for (i = 0; i < N; i++)
        sn[i] = (unsigned short)(sn[i]) >> 15; /* ~0 to 1, 0 to 0 */

    for (i = 0; i < N; i++)
        diff[i] = VC[i] - VS[i];
    for (i = 0; i < N; i++)
        diff[i] = (diff[i] >= 0);
    for (i = 0; i < N; i++)
        le[i] = (VT[i] < 0);
    merge(le, sn, diff, le);
#endif

    merge(comp, sn, le, ge);
    merge(VACC_L, comp, VC, VS);
    vector_copy(VD, VACC_L);

    vector_copy(clip, ge);
    vector_copy(comp, le);
    for (i = 0; i < N; i++)
        ne[i] = eq[i] ^ 1;
    vector_copy(co, sn);
    return;
}

VECTOR_OPERATION VCH(v16 vd, v16 vs, v16 vt)
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
    do_ch(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(__m128i *)VD;
#endif
    return (vd);
}

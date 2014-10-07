/******************************************************************************\
* Project:  C Interpretation of Vector Absolute Value                          *
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

/*
 * -1:  VT *= -1, because VS < 0 // VT ^= -2 if even, or ^= -1, += 1
 *  0:  VT *=  0, because VS = 0 // VT ^= VT
 * +1:  VT *= +1, because VS > 0 // VT ^=  0
 *      VT ^= -1, "negate" -32768 as ~+32767 (corner case hack for N64 SP)
 */
INLINE static void do_abs(short* VD, short* VS, short* VT)
{
    short neg[N], pos[N];
    short nez[N], cch[N]; /* corner case hack -- abs(-32768) == +32767 */
    ALIGNED short res[N];
    register int i;

    vector_copy(res, VT);
#ifndef ARCH_MIN_SSE2
#define MASK_XOR
#endif
    for (i = 0; i < N; i++)
        neg[i]  = (VS[i] <  0x0000);
    for (i = 0; i < N; i++)
        pos[i]  = (VS[i] >  0x0000);
    for (i = 0; i < N; i++)
        nez[i]  = 0;
#ifdef MASK_XOR
    for (i = 0; i < N; i++)
        neg[i]  = -neg[i];
    for (i = 0; i < N; i++)
        nez[i] += neg[i];
#else
    for (i = 0; i < N; i++)
        nez[i] -= neg[i];
#endif
    for (i = 0; i < N; i++)
        nez[i] += pos[i];
#ifdef MASK_XOR
    for (i = 0; i < N; i++)
        res[i] ^= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (res[i] != -32768);
    for (i = 0; i < N; i++)
        res[i] += cch[i]; /* -(x) === (x ^ -1) + 1 */
#else
    for (i = 0; i < N; i++)
        res[i] *= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (res[i] == -32768);
    for (i = 0; i < N; i++)
        res[i] -= cch[i];
#endif
    vector_copy(VACC_L, res);
    vector_copy(VD, VACC_L);
    return;
}

VECTOR_OPERATION VABS(v16 vd, v16 vs, v16 vt)
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
    do_abs(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(__m128i *)VD;
#endif
    return (vd);
}

/******************************************************************************\
* Project:  MSP Simulation Layer for Vector Unit Computational Bit-Wise Logic  *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.09                                                         *
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

#include "logical.h"

VECTOR_OPERATION VAND(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_and_si128(vs, vt);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] & vt[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

VECTOR_OPERATION VNAND(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_and_si128(vs, vt);
    vd = _mm_xor_si128(vd, XMM_ONES);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] & vt[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = ~VACC_L[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

VECTOR_OPERATION VOR(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_or_si128(vs, vt);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] | vt[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

VECTOR_OPERATION VNOR(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_or_si128(vs, vt);
    vd = _mm_xor_si128(vd, XMM_ONES);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] | vt[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = ~VACC_L[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

VECTOR_OPERATION VXOR(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_xor_si128(vs, vt);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] ^ vt[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

VECTOR_OPERATION VNXOR(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_xor_si128(vs, vt);
    vd = _mm_xor_si128(vd, XMM_ONES);
    *(v16 *)VACC_L = vd;
#else
    register unsigned int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = vs[i] ^ vt[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = ~VACC_L[i];
    for (i = 0; i < N; i++)
        vd[i] = VACC_L[i];
#endif
    return (vd);
}

/******************************************************************************\
* Project:  MSP Simulation Layer for Vector Unit Computational Bit-Wise Logic  *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.14                                                         *
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
    vector_and(vt, vs);
    vector_wipe(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

VECTOR_OPERATION VNAND(v16 vd, v16 vs, v16 vt)
{
    vector_and(vt, vs);
    vector_fill(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

VECTOR_OPERATION VOR(v16 vd, v16 vs, v16 vt)
{
    vector_or(vt, vs);
    vector_wipe(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

VECTOR_OPERATION VNOR(v16 vd, v16 vs, v16 vt)
{
    vector_or(vt, vs);
    vector_fill(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

VECTOR_OPERATION VXOR(v16 vd, v16 vs, v16 vt)
{
    vector_xor(vt, vs);
    vector_wipe(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

VECTOR_OPERATION VNXOR(v16 vd, v16 vs, v16 vt)
{
    vector_xor(vt, vs);
    vector_fill(vd);
    vector_xor(vd, vt);
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vd;
#else
    vector_copy(VACC_L, vd);
#endif
    return (vd);
}

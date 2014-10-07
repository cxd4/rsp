/******************************************************************************\
* Project:  MSP Emulation Layer for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2013.11.26                                                         *
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
#ifndef _VU_H
#define _VU_H

#define N      8
/* N:  number of processor elements in SIMD processor */

/*
 * RSP virtual registers (of vector unit)
 * The most important are the 32 general-purpose vector registers.
 * The correct way to accurately store these is using big-endian vectors.
 *
 * For ?WC2 we may need to do byte-precision access just as directly.
 * This is amended by using the `VU_S` and `VU_B` macros defined in `rsp.h`.
 */
ALIGNED short VR[32][N];

/*
 * accumulator-indexing macros (inverted access dimensions, suited for SSE)
 */
#define HI      00
#define MD      01
#define LO      02

ALIGNED static short VACC[3][N];

#define VACC_L      (VACC[LO])
#define VACC_M      (VACC[MD])
#define VACC_H      (VACC[HI])

#define ACC_L(i)    (VACC_L[i])
#define ACC_M(i)    (VACC_M[i])
#define ACC_H(i)    (VACC_H[i])

#ifdef ARCH_MIN_SSE2
typedef __m128i v16;
#else
typedef short * v16;
#endif

#define VECTOR_OPERATION    INLINE static v16
#define VECTOR_EXTERN       VECTOR_OPERATION

#include "shuffle.h"
#include "clamp.h"
#include "cf.h"

VECTOR_OPERATION res_V(v16 vd, v16 vs, v16 vt)
{
    register int i;

    vs = vt = vd; /* unused */
    message("C2\nRESERVED", 2); /* uncertain how to handle reserved, untested */
#ifdef ARCH_MIN_SSE2
    vd = _mm_setzero_si128();
#else
    for (i = 0; i < N; i++)
        vd[i] = 0x0000; /* override behavior (bpoint) */
#endif
    return (vd);
}
VECTOR_OPERATION res_M(v16 vd, v16 vs, v16 vt)
{ /* Ultra64 OS did have these, so one could implement this ext. */
    message("VMUL IQ", 2);
    vd = res_V(vd, vs, vt);
    return (vd);
}

#include "vabs.h"
#include "vadd.h"
#include "vaddc.h"
#include "vand.h"
#include "vch.h"
#include "vcl.h"
#include "vcr.h"
#include "veq.h"
#include "vge.h"
#include "vlt.h"
#include "vmacf.h"
#include "vmacq.h"
#include "vmacu.h"
#include "vmadh.h"
#include "vmadl.h"
#include "vmadm.h"
#include "vmadn.h"
#include "vmov.h"
#include "vmrg.h"
#include "vmudh.h"
#include "vmudl.h"
#include "vmudm.h"
#include "vmudn.h"
#include "vmulf.h"
#include "vmulu.h"
#include "vnand.h"
#include "vne.h"
#include "vnop.h"
#include "vnor.h"
#include "vnxor.h"
#include "vor.h"
#include "vrcp.h"
#include "vrcph.h"
#include "vrcpl.h"
#include "vrsq.h"
#include "vrsqh.h"
#include "vrsql.h"
#include "vsaw.h"
#include "vsub.h"
#include "vsubc.h"
#include "vxor.h"

static v16 (*COP2_C2[64])(v16, v16, v16) = {
    VMULF  ,VMULU  ,res_M  ,res_M  ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_M  ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
    VADD   ,VSUB   ,res_V  ,VABS   ,VADDC  ,VSUBC  ,res_V  ,res_V  , /* 010 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,VSAW   ,res_V  ,res_V  , /* 011 */
    VLT    ,VEQ    ,VNE    ,VGE    ,VCL    ,VCH    ,VCR    ,VMRG   , /* 100 */
    VAND   ,VNAND  ,VOR    ,VNOR   ,VXOR   ,VNXOR  ,res_V  ,res_V  , /* 101 */
    VRCP   ,VRCPL  ,VRCPH  ,VMOV   ,VRSQ   ,VRSQL  ,VRSQH  ,VNOP   , /* 110 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  , /* 111 */
}; /* 000     001     010     011     100     101     110     111 */
#endif

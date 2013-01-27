/******************************************************************************\
* Project:  MSP Emulation Table for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2013.01.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/
#ifndef _VU_H
#define _VU_H

const int element_index[16][8] = {
    { 00, 01, 02, 03, 04, 05, 06, 07 }, /* none */
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 00, 00, 02, 02, 04, 04, 06, 06 }, /* 0Q */
    { 01, 01, 03, 03, 05, 05, 07, 07 }, /* 1Q */
    { 00, 00, 00, 00, 04, 04, 04, 04 }, /* 0H */
    { 01, 01, 01, 01, 05, 05, 05, 05 }, /* 1H */
    { 02, 02, 02, 02, 06, 06, 06, 06 }, /* 2H */
    { 03, 03, 03, 03, 07, 07, 07, 07 }, /* 3H */
    { 00, 00, 00, 00, 00, 00, 00, 00 }, /* 0 */
    { 01, 01, 01, 01, 01, 01, 01, 01 }, /* 1 */
    { 02, 02, 02, 02, 02, 02, 02, 02 }, /* 2 */
    { 03, 03, 03, 03, 03, 03, 03, 03 }, /* 3 */
    { 04, 04, 04, 04, 04, 04, 04, 04 }, /* 4 */
    { 05, 05, 05, 05, 05, 05, 05, 05 }, /* 5 */
    { 06, 06, 06, 06, 06, 06, 06, 06 }, /* 6 */
    { 07, 07, 07, 07, 07, 07, 07, 07 }  /* 7 */
};

/* This is zilmar's method of transposing the source element read order,
 * based on the loop iteration count and destination element, to avoid
 * premature vector element overwrites.  The more modern method however
 * is to just not transpose the read orders and write to a prebuffer,
 * temporary vector register, then do one single hit to move the result
 * over to the destination vector register.  So this probably has no use.
 */
const int element_source_transpose[16][8] = {
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 00, 01, 02, 03, 04, 05, 06, 07 },
    { 01, 03, 05, 07, 00, 02, 04, 06 },
    { 00, 02, 04, 06, 01, 03, 05, 07 },
    { 01, 02, 03, 05, 06, 07, 00, 04 },
    { 00, 02, 03, 04, 06, 07, 01, 05 },
    { 00, 01, 03, 04, 05, 07, 02, 06 },
    { 00, 01, 02, 04, 05, 06, 03, 07 },
    { 01, 02, 03, 04, 05, 06, 07, 00 },
    { 00, 02, 03, 04, 05, 06, 07, 01 },
    { 00, 01, 03, 04, 05, 06, 07, 02 },
    { 00, 01, 02, 04, 05, 06, 07, 03 },
    { 00, 01, 02, 03, 05, 06, 07, 04 },
    { 00, 01, 02, 03, 04, 06, 07, 05 },
    { 00, 01, 02, 03, 04, 05, 07, 06 },
    { 00, 01, 02, 03, 04, 05, 06, 07 }
};

unsigned short int UNSIGNED_CLAMP(signed int accum)
{
    if (VACC[accum].q < (long long)0xFFFF800000000000) return 0x0000;
    if (VACC[accum].q > (long long)0x00007FFFFFFFFFFF) return 0xFFFF;
    return (VACC[accum].w[LO]);
}

signed short int SIGNED_CLAMP(signed long element) {
    if (element < -32768) return 0x8000; /* if (element < (signed)0xFFFF8000) */
    if (element > +32767) return 0x7FFF; /* if (element & 0xFFFF8000) */
    return ((signed short)element);
} /* At first glance I didn't like doing this either; good luck doing better! */

#include "vmulf.h"
#include "vmulu.h"
#include "vmudl.h"
#include "vmudm.h"
#include "vmudn.h"
#include "vmudh.h"
#include "vmacf.h"
#include "vmacu.h"
#include "vmacq.h"
#include "vmadl.h"
#include "vmadm.h"
#include "vmadn.h"
#include "vmadh.h"
#include "vadd.h"
#include "vsub.h"
#include "vabs.h"
#include "vaddc.h"
#include "vsubc.h"
#include "vsaw.h"
#include "vlt.h"
#include "veq.h"
#include "vne.h"
#include "vge.h"
#include "vcl.h"
#include "vch.h"
#include "vcr.h"
#include "vmrg.h"
#include "vand.h"
#include "vnand.h"
#include "vor.h"
#include "vnor.h"
#include "vxor.h"
#include "vnxor.h"
#include "vrcp.h"
#include "vrcpl.h"
#include "vrcph.h"
#include "vmov.h"
#include "vrsq.h"
#include "vrsql.h"
#include "vrsqh.h"
#include "vnop.h"

void res_V(int vd, int rd, int rt, int element)
{
    element = rt = rd = vd = 0;
    message("VU reserved instruction", 3);
    return;
}

static void (*SP_COP2_VECTOP[64])(int, int, int, int) = {
    VMULF  ,VMULU  ,res_V  ,res_V  ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_V  ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
    VADD   ,VSUB   ,res_V  ,VABS   ,VADDC  ,VSUBC  ,res_V  ,res_V  , /* 010 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,VSAW   ,res_V  ,res_V  , /* 011 */
    VLT    ,VEQ    ,VNE    ,VGE    ,VCL    ,VCH    ,VCR    ,VMRG   , /* 100 */
    VAND   ,VNAND  ,VOR    ,VNOR   ,VXOR   ,VNXOR  ,res_V  ,res_V  , /* 101 */
    VRCP   ,VRCPL  ,VRCPH  ,VMOV   ,VRSQ   ,VRSQL  ,VRSQH  ,VNOP   , /* 110 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V   /* 111 */
}; /* 000     001     010     011     100     101     110     111 */

/* Some notes about the vector operation codes matrix.
 * VMULQ, VRNDN, and VRNDP did exist but were all for MPEG DCT and omitted.
 * VMACQ ignores `vs` and `vt` and only oddifies, but no games would do that.
 * VSAR operation was perhaps modified, so it is instead called VSAW.
 * VNXOR in other VUs is often called "VXNOR", but not here.
 * VRSQ is the single-precision FP for square roots, not favored by Nintendo.
 * "VNOOP" is a typo of "VNOP", the latter being correct for assemblers.
 */
#endif

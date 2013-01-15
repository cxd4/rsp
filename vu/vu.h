/******************************************************************************\
* Project:  MSP Emulation Table for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2013.01.15                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#ifndef _VU_H
#define _VU_H

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

unsigned short int UNSIGNED_CLAMP_HI(signed long element) {
    if (element < -32768) return 0x0000;
    if (element > +32767) return 0xFFFF;
    return ((unsigned short)element);
}

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

extern void VMULF(int vd, int vs, int vt, int element);
extern void VMULU(int vd, int vs, int vt, int element);
extern void VMUDL(int vd, int vs, int vt, int element);
extern void VMUDM(int vd, int vs, int vt, int element);
extern void VMUDN(int vd, int vs, int vt, int element);
extern void VMUDH(int vd, int vs, int vt, int element);
extern void VMACF(int vd, int vs, int vt, int element);
extern void VMACU(int vd, int vs, int vt, int element);
extern void VMACQ(int vd, int vs, int vt, int element);
extern void VMADL(int vd, int vs, int vt, int element);
extern void VMADM(int vd, int vs, int vt, int element);
extern void VMADN(int vd, int vs, int vt, int element);
extern void VMADH(int vd, int vs, int vt, int element);
extern void VADD(int vd, int vs, int vt, int element);
extern void VSUB(int vd, int vs, int vt, int element);
extern void VABS(int vd, int vs, int vt, int element);
extern void VADDC(int vd, int vs, int vt, int element);
extern void VSUBC(int vd, int vs, int vt, int element);
extern void VSAW(int vd, int unused_rd, int unused_rt, int element);
extern void VLT(int vd, int vs, int vt, int element);
extern void VEQ(int vd, int vs, int vt, int element);
extern void VNE(int vd, int vs, int vt, int element);
extern void VGE(int vd, int vs, int vt, int element);
extern void VCL(int vd, int vs, int vt, int element);
extern void VCH(int vd, int vs, int vt, int element);
extern void VCR(int vd, int vs, int vt, int element);
extern void VMRG(int vd, int vs, int vt, int element);
extern void VAND(int vd, int vs, int vt, int element);
extern void VNAND(int vd, int vs, int vt, int element);
extern void VOR(int vd, int vs, int vt, int element);
extern void VNOR(int vd, int vs, int vt, int element);
extern void VXOR(int vd, int vs, int vt, int element);
extern void VNXOR(int vd, int vs, int vt, int element);
extern void VRCP(int vd, int del, int vt, int element);
extern void VRCPL(int vd, int del, int vt, int element);
extern void VRCPH(int vd, int del, int vt, int element);
extern void VMOV(int vd, int del, int vt, int element);
extern void VRSQ(int vd, int del, int vt, int element);
extern void VRSQL(int vd, int del, int vt, int element);
extern void VRSQH(int vd, int del, int vt, int element);
extern void VNOP(int unused_sa, int unused_rd, int unused_rt, int unused);

void res_VU(int vd, int rd, int rt, int element)
{
    element = rt = rd = vd = 0;
    message("VU reserved instruction", 3);
    return;
}

static void (*SP_COP2_VECTOP[64])(int, int, int, int) = {
    VMULF  ,VMULU  ,res_VU ,res_VU ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_VU ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
    VADD   ,VSUB   ,res_VU ,VABS   ,VADDC  ,VSUBC  ,res_VU ,res_VU , /* 010 */
    res_VU ,res_VU ,res_VU ,res_VU ,res_VU ,VSAW   ,res_VU ,res_VU , /* 011 */
    VLT    ,VEQ    ,VNE    ,VGE    ,VCL    ,VCH    ,VCR    ,VMRG   , /* 100 */
    VAND   ,VNAND  ,VOR    ,VNOR   ,VXOR   ,VNXOR  ,res_VU ,res_VU , /* 101 */
    VRCP   ,VRCPL  ,VRCPH  ,VMOV   ,VRSQ   ,VRSQL  ,VRSQH  ,VNOP   , /* 110 */
    res_VU ,res_VU ,res_VU ,res_VU ,res_VU ,res_VU ,res_VU ,res_VU   /* 111 */
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

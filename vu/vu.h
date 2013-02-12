/******************************************************************************\
* Project:  MSP Emulation Table for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2013.01.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/
#ifndef _VU_H
#define _VU_H

/*
 * accumulator-indexing macros
 */
#define LO  00
#define MD  01
#define HI  02

static union ACC {
    signed char SB[6];
    short int s[3]; /* Each element has a low, middle, and high 16-bit slice. */
 /* signed long long e:  48; /* There are eight elements in the accumulator. */
/* 64-bit access: */
    unsigned char B[8];
    short int HW[4];
    unsigned short UHW[4];
    int W[2];
    unsigned int UW[2];
    long long int DW;
    unsigned long long UDW;
} VACC[8];

/* special-purpose vector control registers */
unsigned short VCO; /* vector carry out register */
unsigned short VCC; /* vector compare code register */
unsigned char VCE; /* vector compare extension register */

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

void res_M(int vd, int vs, int vt, int element)
{
    element = vt = vs = vd = 0;
    message("VRNDP/VRNDN/VMULQ\nMPEG DCT canceled.", 3);
    return; /* Ultra64 OS did have these, so one could implement this ext. */
}
void res_V(int vd, int rd, int rt, int element)
{
    element = rt = rd = vd = 0;
    message("VU reserved instruction", 3);
    return;
}

static void (*SP_COP2_VECTOP[64])(int, int, int, int) = {
    VMULF  ,VMULU  ,res_M  ,res_M  ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_M  ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
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

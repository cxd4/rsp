/******************************************************************************\
* Project:  MSP Emulation Table for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/
#ifndef _VU_H
#define _VU_H

#define MAX_LONG (~0)
#if !(MAX_LONG < 0xFFFFFFFFFFFF)
#define MACHINE_SIZE_48_MIN
#endif

/*
 * RSP virtual registers (of vector unit)
 * The most important are the 32 general-purpose vector registers.
 * The correct way to accurately store these is using big-endian vectors.
 *
 * For ?WC2 we may need to do byte-precision access just as directly.
 * This is ammended by using the `VU_S` and `VU_B` macros defined in `rsp.h`.
 */
static short VR[32][8];

/*
 * vector-scalar element decoding
 *
 * Obviously, doing a switch jump table on (element & 0xF) is very fast
 * because it saves the decoding time of constantly fetching source elements.
 *
 * However, there are several disadvantages to the above method:
 *     * Extremely difficult to maintain.  (Algorithm fixes need 16 copies.)
 *     * Not accurate.  (Real H/W decodes all of the elements iteratively.)
 *     * Colossal boost in program size, cutting down command cache memory.
 *     * Using branch frames for performing at least one conditional jump.
 *     * Even if element = 0x0, it's still 8 un-merged, separate data movs.
 *     * Faster only for large-cache processors.  (RSP is very small-cache.)
 *     * Difficult to read.
 *     * Pointless to try to optimize that way when SSSE3 could be applied.
 */
static const int ei[16][8] = {
    { 00, 01, 02, 03, 04, 05, 06, 07 }, /* none (vector-only operand) */
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

/*
 * accumulator-indexing macros
 */
#define LO  00
#define MD  01
#define HI  02

static union ACC {
#ifdef MACHINE_SIZE_48_MIN
    signed e:  48; /* There are eight elements in the accumulator. */
#endif
    short int s[3]; /* Each element has a low, middle, and high 16-bit slice. */
    signed char SB[6];
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

/*
 * vector control register indexing pointer table
 * This is particularly useful for directly executing CFC2 and CTC2.
 */
static const void *vCR[4] = {
    &VCO,
    &VCC,
    &VCE,
    &VCE /* Invalid vector control register.  (There are only three.) */
};

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

static void res_M(int sa, int rd, int rt, int e)
{
    e = rt = rd = sa = 0;
    message("VRNDP/VRNDN/VMULQ\nMPEG DCT canceled.", 3);
    return; /* Ultra64 OS did have these, so one could implement this ext. */
}
static void res_V(int sa, int rd, int rt, int e)
{
    e = rt = rd = sa = 0;
    message("VU reserved instruction", 3);
    return;
}

static void (*SP_COP2_C2[64])(int, int, int, int) = {
    VMULF  ,VMULU  ,res_M  ,res_M  ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_M  ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
    VADD   ,VSUB   ,res_V  ,VABS   ,VADDC  ,VSUBC  ,res_V  ,res_V  , /* 010 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,VSAW   ,res_V  ,res_V  , /* 011 */
    VLT    ,VEQ    ,VNE    ,VGE    ,VCL    ,VCH    ,VCR    ,VMRG   , /* 100 */
    VAND   ,VNAND  ,VOR    ,VNOR   ,VXOR   ,VNXOR  ,res_V  ,res_V  , /* 101 */
    VRCP   ,VRCPL  ,VRCPH  ,VMOV   ,VRSQ   ,VRSQL  ,VRSQH  ,VNOP   , /* 110 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V    /* 111 */
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

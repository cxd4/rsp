/******************************************************************************\
* Project:  MSP Simulation Layer for Vector Unit Computational Multiplies      *
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

#include "multiply.h"
#include "select.h"

#ifdef ARCH_MIN_SSE2
static INLINE void SIGNED_CLAMP_AM(short* VD)
{ /* typical sign-clamp of accumulator-mid (bits 31:16) */
    v16 dst, src;
    v16 pvd, pvs;

    pvs = _mm_load_si128((v16 *)VACC_H);
    pvd = _mm_load_si128((v16 *)VACC_M);
    dst = _mm_unpacklo_epi16(pvd, pvs);
    src = _mm_unpackhi_epi16(pvd, pvs);

    dst = _mm_packs_epi32(dst, src);
    _mm_store_si128((v16 *)VD, dst);
    return;
}
#else
static INLINE void SIGNED_CLAMP_AM(short* VD)
{ /* typical sign-clamp of accumulator-mid (bits 31:16) */
    short hi[N], lo[N];
    register int i;

    for (i = 0; i < N; i++)
        lo[i]  = (VACC_H[i] < ~0);
    for (i = 0; i < N; i++)
        lo[i] |= (VACC_H[i] < 0) & !(VACC_M[i] < 0);
    for (i = 0; i < N; i++)
        hi[i]  = (VACC_H[i] >  0);
    for (i = 0; i < N; i++)
        hi[i] |= (VACC_H[i] == 0) & (VACC_M[i] < 0);
    vector_copy(VD, VACC_M);
    for (i = 0; i < N; i++)
        VD[i] &= -(lo[i] ^ 1);
    for (i = 0; i < N; i++)
        VD[i] |= -(hi[i] ^ 0);
    for (i = 0; i < N; i++)
        VD[i] ^= 0x8000 * (hi[i] | lo[i]);
    return;
}
#endif

static INLINE void UNSIGNED_CLAMP(short* VD)
{ /* sign-zero hybrid clamp of accumulator-mid (bits 31:16) */
    ALIGNED short temp[N];
    short cond[N];
    register int i;

    SIGNED_CLAMP_AM(temp); /* no direct map in SSE, but closely based on this */
    for (i = 0; i < N; i++)
        cond[i] = -(temp[i] >  VACC_M[i]); /* VD |= -(ACC47..16 > +32767) */
    for (i = 0; i < N; i++)
        VD[i] = temp[i] & ~(temp[i] >> 15); /* Only this clamp is unsigned. */
    for (i = 0; i < N; i++)
        VD[i] = VD[i] | cond[i];
    return;
}

static INLINE void SIGNED_CLAMP_AL(short* VD)
{ /* sign-clamp accumulator-low (bits 15:0) */
    ALIGNED short temp[N];
    short cond[N];
    register int i;

    SIGNED_CLAMP_AM(temp); /* no direct map in SSE, but closely based on this */
    for (i = 0; i < N; i++)
        cond[i] = (temp[i] != VACC_M[i]); /* result_clamped != result_raw ? */
    for (i = 0; i < N; i++)
        temp[i] ^= 0x8000; /* half-assed unsigned saturation mix in the clamp */
    merge(VD, cond, temp, VACC_L);
    return;
}

INLINE static void do_mulf(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = (SEMIFRAC << 1) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = (SEMIFRAC << 1) >> 16;
    for (i = 0; i < N; i++)
        VACC_H[i] = -((VACC_M[i] < 0) & (VS[i] != VT[i])); /* -32768 * -32768 */
#ifndef ARCH_MIN_SSE2
    vector_copy(VD, VACC_M);
    for (i = 0; i < N; i++)
        VD[i] -= (VACC_M[i] < 0) & (VS[i] == VT[i]); /* ACC b 31 set, min*min */
#else
    SIGNED_CLAMP_AM(VD);
#endif
    return;
}

INLINE static void do_mulu(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = (SEMIFRAC << 1) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = (SEMIFRAC << 1) >> 16;
    for (i = 0; i < N; i++)
        VACC_H[i] = -((VACC_M[i] < 0) & (VS[i] != VT[i])); /* -32768 * -32768 */
#if (0)
    UNSIGNED_CLAMP(VD);
#else
    vector_copy(VD, VACC_M);
    for (i = 0; i < N; i++)
        VD[i] |=  (VACC_M[i] >> 15); /* VD |= -(result == 0x000080008000) */
    for (i = 0; i < N; i++)
        VD[i] &= ~(VACC_H[i] >>  0); /* VD &= -(result >= 0x000000000000) */
#endif
    return;
}

INLINE static void do_mudl(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = (unsigned short)(VS[i])*(unsigned short)(VT[i]) >> 16;
    for (i = 0; i < N; i++)
        VACC_M[i] = 0x0000;
    for (i = 0; i < N; i++)
        VACC_H[i] = 0x0000;
    vector_copy(VD, VACC_L); /* no possibilities to clamp */
    return;
}

INLINE static void do_mudm(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = (VS[i]*(unsigned short)(VT[i]) & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = (VS[i]*(unsigned short)(VT[i]) & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        VACC_H[i] = -(VACC_M[i] < 0);
    vector_copy(VD, VACC_M); /* no possibilities to clamp */
    return;
}

INLINE static void do_mudn(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = ((unsigned short)(VS[i])*VT[i] & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = ((unsigned short)(VS[i])*VT[i] & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        VACC_H[i] = -(VACC_M[i] < 0);
    vector_copy(VD, VACC_L); /* no possibilities to clamp */
    return;
}

INLINE static void do_mudh(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = 0x0000;
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(VS[i]*VT[i] >>  0);
    for (i = 0; i < N; i++)
        VACC_H[i] = (short)(VS[i]*VT[i] >> 16);
    SIGNED_CLAMP_AM(VD);
    return;
}

INLINE static void do_macf(short* VD, short* VS, short* VT)
{
    i32 product[N];
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = VS[i] * VT[i];
    for (i = 0; i < N; i++)
        addend[i] = (product[i] << 1) & 0x00000000FFFF;
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        addend[i] = (addend[i] >> 16) + (unsigned short)(product[i] >> 15);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] -= (product[i] < 0);
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    SIGNED_CLAMP_AM(VD);
    return;
}

INLINE static void do_macu(short* VD, short* VS, short* VT)
{
    i32 product[N];
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = VS[i] * VT[i];
    for (i = 0; i < N; i++)
        addend[i] = (product[i] << 1) & 0x00000000FFFF;
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        addend[i] = (addend[i] >> 16) + (unsigned short)(product[i] >> 15);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] -= (product[i] < 0);
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    UNSIGNED_CLAMP(VD);
    return;
}

INLINE static void do_madl(short* VD, short* VS, short* VT)
{
    i32 product[N];
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = (unsigned short)(VS[i]) * (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (product[i] & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(addend[i] >> 16);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    SIGNED_CLAMP_AL(VD);
    return;
}

INLINE static void do_madm(short* VD, short* VS, short* VT)
{
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + (unsigned short)(VS[i]*VT[i]);
    for (i = 0; i < N; i++)
        VACC_L[i] += (short)(VS[i] * VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (addend[i] >> 16) + (VS[i]*(unsigned short)(VT[i]) >> 16);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)addend[i];
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    SIGNED_CLAMP_AM(VD);
    return;
}

INLINE static void do_madn(short* VD, short* VS, short* VT)
{
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + (unsigned short)(VS[i]*VT[i]);
    for (i = 0; i < N; i++)
        VACC_L[i] += (short)(VS[i] * VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (addend[i] >> 16) + ((unsigned short)(VS[i])*VT[i] >> 16);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)addend[i];
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    SIGNED_CLAMP_AL(VD);
    return;
}

INLINE static void do_madh(short* VD, short* VS, short* VT)
{
    i32 product[N];
    u32 addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = (signed short)(VS[i]) * (signed short)(VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + (unsigned short)(product[i]);
    for (i = 0; i < N; i++)
        VACC_M[i] += (short)(VS[i] * VT[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] += (addend[i] >> 16) + (product[i] >> 16);
    SIGNED_CLAMP_AM(VD);
    return;
}

VECTOR_OPERATION VMULF(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mulf(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMULU(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mulu(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMUDL(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mudl(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMUDM(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mudm(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMUDN(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mudn(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMUDH(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_mudh(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMACF(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_macf(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMACU(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_macu(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMACQ(v16 vd, v16 vs, v16 vt)
{
    vs = vt = vd; /* unused */

    message("VMACQ\nUnimplemented."); /* untested, any N64 ROMs use this?? */
    return (vd);
}

VECTOR_OPERATION VMADL(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_madl(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMADM(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_madm(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMADN(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_madn(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

VECTOR_OPERATION VMADH(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    ALIGNED short VD[N], VS[N], VT[N];

    *(v16 *)VD = vd;
    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VD, VS, VT;

    VD = vd;
    VS = vs;
    VT = vt;
#endif
    do_madh(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VD;
#endif
    return (vd);
}

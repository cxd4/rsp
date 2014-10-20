/******************************************************************************\
* Project:  MSP Simulation Layer for Vector Unit Computational Multiplies      *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.19                                                         *
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
#define _mm_cmple_epu16(dst, src) \
    _mm_cmpeq_epi16(_mm_subs_epu16(dst, src), _mm_setzero_si128())
#define _mm_cmpgt_epu16(dst, src) \
    _mm_andnot_si128(_mm_cmpeq_epi16(dst, src), _mm_cmple_epu16(src, dst))
#define _mm_cmplt_epu16(dst, src) \
    _mm_cmpgt_epu16(src, dst)

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

VECTOR_OPERATION VMULF(v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    v16 negative;
    v16 round;
    v16 prod_hi, prod_lo;

/*
 * We cannot save register allocations by doing xmm0 *= xmm1 or xmm1 *= xmm0
 * because we need to do a computation on (xmm0 ^ xmm1) before interference.
 */
    prod_lo = _mm_mullo_epi16(vs, vt);
    prod_hi = _mm_mulhi_epi16(vs, vt);

/*
 * Since -32768 * -32768 > 0, we cannot detect if VACC_H should be all ones
 * based solely on whether bit 31 of the 32-bit-stored product is set.
 * So we'll detect if (vs * vt < 0) an old-fashioned way:  ((vs ^ vt) < 0).
 */
    negative = _mm_xor_si128(vs, vt);
    negative = _mm_srai_epi16(negative, 15);
    *(v16 *)VACC_H = negative; /* i16*i16 only fills L/M; VACC_H = 0 or ~0. */

    prod_hi = _mm_slli_epi16(prod_hi, 1); /* Product requires special <<= 1. */
    negative = _mm_srli_epi16(prod_lo, 15); /* shifting overflows ? 1 : 0 */
    prod_hi = _mm_add_epi16(prod_hi, negative);
    prod_lo = _mm_slli_epi16(prod_lo, 1);

/*
 * special fractional round value:  (32-bit product) += 32768 (0x8000)
 * two's compliment computation:  (0xFFFF << 15) & 0xFFFF
 */
    round = _mm_cmpeq_epi16(vs, vs); /* PCMPEQ  xmmA, xmmA # all 1's forced */
    round = _mm_slli_epi16(round, 15);

    prod_lo = _mm_add_epi16(prod_lo, round); /* Or ^= 0x8000 works also. */
    *(v16 *)VACC_L = prod_lo;

/*
 * Did we overflow the 16-bit low word by adding 0x8000 to VACC_L?
 * Very easily checked.  If adding 32768 (equivalent, again, to XOR'ing by
 * 32768) changed the MSB from 1 to 0, we know that it DID overflow.
 * Although, doing += (0 >> 15) ? 1 : 0, isn't as easy as inverting 0 first.
 */
    prod_lo = _mm_xor_si128(prod_lo, round);
    prod_lo = _mm_srli_epi16(prod_lo, 15); /* += 1:0 or _srai_ for -= ~0:0 */
    prod_hi = _mm_add_epi16(prod_hi, prod_lo);
    *(v16 *)VACC_M = prod_hi;

/*
 * VMULF does signed clamping.  However, in VMULF's case, the only possible
 * combination of inputs to even cause a 32-bit signed clamp to a saturated
 * 16-bit result is (-32768 * -32768), so, rather than fully emulating a
 * signed clamp with SSE, we do an accurate-enough hack for this corner case.
 */
    vs = _mm_cmpeq_epi16(vs, vt); /* vs == vt */
    vt = _mm_cmpeq_epi16(vt, round); /* vt == -32768 (conveniently, "round") */
    vs = _mm_and_si128(vs, vt); /* vs == vt == -32768:  corner case confirmed */
    vs = _mm_add_epi16(vs, prod_hi); /* prod_hi must be -32768; + -1 = +32767 */
    return (vs);
#else
    word_32 product[N];
    register unsigned int i;

    for (i = 0; i < N; i++)
        product[i].W = vs[i] * vt[i];
    for (i = 0; i < N; i++)
        product[i].W <<= 1; /* special fractional shift value */
    for (i = 0; i < N; i++)
        product[i].W += 32768; /* special fractional round value */
    for (i = 0; i < N; i++)
        VACC_L[i] = (product[i].UW & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = (product[i].UW & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        VACC_H[i] = ((vs[i] ^ vt[i]) < 0) ? -1 :  0;
    SIGNED_CLAMP_AM(V_result);
    return;
#endif
}

VECTOR_OPERATION VMULU(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_mulu(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMUDL(v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vs = _mm_mulhi_epu16(vs, vt);
    vector_wipe(vt); /* (UINT16_MAX * UINT16_MAX) >> 16 too small for MD/HI */
    *(v16 *)VACC_L = vs;
    *(v16 *)VACC_M = vt;
    *(v16 *)VACC_H = vt;
    return (vs); /* no possibilities to clamp */
#else
    word_32 product[N];
    register unsigned int i;

    for (i = 0; i < N; i++)
        product[i].UW = (u16)vs[i] * (u16)vt[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = product[i].UW >> 16; /* product[i].H[HES(0) >> 1] */
    vector_copy(V_result, VACC_L);
    vector_wipe(VACC_M);
    vector_wipe(VACC_H);
    return;
#endif
}

VECTOR_OPERATION VMUDM(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_mudm(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMUDN(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_mudn(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMUDH(v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    v16 prod_high;

    prod_high = _mm_mulhi_epi16(vs, vt);
    vs        = _mm_mullo_epi16(vs, vt);

    *(v16 *)VACC_L = _mm_setzero_si128();
    *(v16 *)VACC_M = vs; /* acc 31..16 storing (VS*VT)15..0 */
    *(v16 *)VACC_H = prod_high; /* acc 47..32 storing (VS*VT)31..16 */

/*
 * "Unpack" the low 16 bits and the high 16 bits of each 32-bit product to a
 * couple xmm registers, re-storing them as 2 32-bit products each.
 */
    vt = _mm_unpackhi_epi16(vs, prod_high);
    vs = _mm_unpacklo_epi16(vs, prod_high);

/*
 * Re-interleave or pack both 32-bit products in both xmm registers with
 * signed saturation:  prod < -32768 to -32768 and prod > +32767 to +32767.
 */
    vs = _mm_packs_epi32(vs, vt);
    return (vs);
#else
    word_32 product[N];
    register unsigned int i;

    for (i = 0; i < N; i++)
        product[i].SW = (s16)vs[i] * (s16)vt[i];
    vector_wipe(VACC_L);
    for (i = 0; i < N; i++)
        VACC_M[i] = (s16)(product[i].W >>  0); /* product[i].HW[HES(0) >> 1] */
    for (i = 0; i < N; i++)
        VACC_H[i] = (s16)(product[i].W >> 16); /* product[i].HW[HES(2) >> 1] */
    SIGNED_CLAMP_AM(V_result);
    return;
#endif
}

VECTOR_OPERATION VMACF(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_macf(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMACU(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_macu(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMACQ(v16 vs, v16 vt)
{
    vs = vt; /* both unused ... Only the vector accumulator is a source. */

    message("VMACQ\nUnimplemented."); /* untested, any N64 ROMs use this?? */
#ifdef ARCH_MIN_SSE2
    return (vs);
#else
    return;
#endif
}

VECTOR_OPERATION VMADL(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_madl(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMADM(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_madm(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMADN(v16 vs, v16 vt)
{
    ALIGNED i16 VD[N];
#ifdef ARCH_MIN_SSE2
    ALIGNED i16 VS[N], VT[N];

    *(v16 *)VS = vs;
    *(v16 *)VT = vt;
#else
    v16 VS, VT;

    VS = vs;
    VT = vt;
#endif
    do_madn(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMADH(v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    v16 acc_mid;
    v16 prod_high;

    prod_high = _mm_mulhi_epi16(vs, vt);
    vs        = _mm_mullo_epi16(vs, vt);

/*
 * We're required to load the source product from the accumulator to add to.
 * While we're at it, conveniently sneak in a acc[31..16] += (vs*vt)[15..0].
 */
    acc_mid = *(v16 *)VACC_M;
    vs = _mm_add_epi16(vs, acc_mid);
    *(v16 *)VACC_M = vs;
    vt = *(v16 *)VACC_H;

/*
 * While accumulating base_lo + product_lo is easy, getting the correct data
 * for base_hi + product_hi is tricky and needs unsigned overflow detection.
 *
 * The one-liner solution to detecting unsigned overflow (thus adding a carry
 * value of 1 to the higher word) is _mm_cmplt_epu16, but none of the Intel
 * MMX-based instruction sets define unsigned comparison ops FOR us, so...
 */
    vt = _mm_add_epi16(vt, prod_high);
    vs = _mm_cmplt_epu16(vs, acc_mid); /* acc.mid + prod.low < acc.mid */
    vt = _mm_sub_epi16(vt, vs); /* += 1 if overflow, by doing -= ~0 */
    *(v16 *)VACC_H = vt;

    vs = *(v16 *)VACC_M;
    prod_high = _mm_unpackhi_epi16(vs, vt);
    vs        = _mm_unpacklo_epi16(vs, vt);
    vs = _mm_packs_epi32(vs, prod_high);
    return (vs);
#else
    word_32 product[N], addend[N];
    register unsigned int i;

    for (i = 0; i < N; i++)
        product[i].SW = (s16)vs[i] * (s16)vt[i];
    for (i = 0; i < N; i++)
        addend[i].UW = (u16)VACC_M[i] + (u16)(product[i].W);
    for (i = 0; i < N; i++)
        VACC_M[i] += (i16)product[i].SW;
    for (i = 0; i < N; i++)
        VACC_H[i] += (addend[i].UW >> 16) + (product[i].SW >> 16);
    SIGNED_CLAMP_AM(V_result);
    return;
#endif
}

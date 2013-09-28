#ifndef _CLAMP_H
#define _CLAMP_H

/*
 * for ANSI compliance (null INLINE attribute if not already set to `inline`)
 * Include "rsp.h" for active, non-ANSI inline definition.
 */
#ifndef INLINE
#define INLINE
#endif

/*
 * dependency for 48-bit accumulator access
 */
#include "vu.h"

/*
 * vector select merge (`VMRG`) formula
 *
 * This is really just a vectorizer for ternary conditional storage.
 * I've named it so because it directly maps to the VMRG op-code.
 * -- example --
 * for (i = 0; i < N; i++)
 *     if (c_pass)
 *         dest = element_a;
 *     else
 *         dest = element_b;
 */
static INLINE void merge(short* VD, short* cmp, short* pass, short* fail)
{
    register int i;
#if (0)
/* Do not use this version yet, as it still does not vectorize to SSE2. */
    for (i = 0; i < N; i++)
        VD[i] = (cmp[i] != 0) ? pass[i] : fail[i];
#else
    short diff[N];

    for (i = 0; i < N; i++)
        diff[i] = pass[i] - fail[i];
    for (i = 0; i < N; i++)
        VD[i] = fail[i] + cmp[i]*diff[i]; /* actually `(cmp[i] != 0)*diff[i]` */
#endif
    return;
}

/*
 * modes of saturation (unofficial labels, just made up by file author)
 */
enum {
    SM_MUL_X, /* clamp acc. bits 31:16, crossing through zero (0x8000:0x7FFF) */
    SM_MUL_Z, /* clamp acc. bits 15:0 with zero-extension (0x0000:0xFFFF) */
    SM_MUL_Q, /* oddified DCT inverse quantization (for N64 SP, VMACQ only) */
    SM_MUL_I, /* (reserved) for VMULI and VMACI (VRNDP and VRNDN) */
    SM_ADD_A, /* VADD and VSUB arithmetic */
    SM_ADD_L, /* VABS dynamic inversion/negation logic */
    SM_DIV_R, /* reciprocal of the vector */
    SM_DIV_S, /* square root of the vector reciprocal */
    EOL /* more stuff here if you want */
};

INLINE void SIGNED_CLAMP(short* VD, int mode)
{
    short hi[N], lo[N];
    register int i;

    switch (mode)
    {
        case SM_MUL_X: /* typical sign-clamp of accumulator-mid (bits 31:16) */
            for (i = 0; i < N; i++)
                lo[i]  = (VACC_H[i] < ~0);
            for (i = 0; i < N; i++)
                lo[i] |= (VACC_H[i] < 0) & !(VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                hi[i]  = (VACC_H[i] >  0);
            for (i = 0; i < N; i++)
                hi[i] |= (VACC_H[i] == 0) & (VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                VD[i]  = VACC_M[i];
            for (i = 0; i < N; i++)
                VD[i] &= -(lo[i] ^ 1);
            for (i = 0; i < N; i++)
                VD[i] |= -(hi[i] ^ 0);
            for (i = 0; i < N; i++)
                VD[i] ^= 0x8000 * (hi[i] | lo[i]);
            return;
        case SM_MUL_Z: /* sign-clamp accumulator-low (bits 15:0) */
            for (i = 0; i < N; i++)
                lo[i]  = (VACC_H[i] < ~0);
            for (i = 0; i < N; i++)
                lo[i] |= (VACC_H[i] < 0) & !(VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                hi[i]  = (VACC_H[i] >  0);
            for (i = 0; i < N; i++)
                hi[i] |= (VACC_H[i] == 0) & (VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                VD[i]  = VACC_L[i];
            for (i = 0; i < N; i++)
                VD[i] &= -(lo[i] ^ 1);
            for (i = 0; i < N; i++)
                VD[i] |= -(hi[i] ^ 0);
            return;
        case SM_MUL_Q: /* possible DCT inverse quantization (VMACQ only) */
            for (i = 0; i < N; i++)
                VD[i]  = (VACC_H[i] << 15) | ((unsigned short)(VACC_M[i]) >> 1);
            message("VMACQ\nClamping unimplemented.", 3);
            for (i = 0; i < N; i++)
                VD[i] &= 0xFFF0;
            return;
        case SM_ADD_A: /* VADD and VSUB */
            message("ADD\nMoved.", 3);
            return;
    }
}

INLINE static void UNSIGNED_CLAMP(short* VD)
{
    short hi[N], lo[N];
    register int i;

    for (i = 0; i < N; i++)
        VD[i] = VACC_M[i];
    for (i = 0; i < N; i++)
        lo[i] = -(VACC_H[i] < 0);
    for (i = 0; i < N; i++)
        hi[i] = -(VACC_M[i] < 0); /* NOTE:  -(VACC_M[i] < 0) ^ lo[i]; */
    for (i = 0; i < N; i++)
        hi[i] = hi[i] | -(VACC_H[i] > 0); /* hi[i] = -(ACC[47..32] > +32767); */
    for (i = 0; i < N; i++)
        VD[i] |=  hi[i];
    for (i = 0; i < N; i++)
        VD[i] &= ~lo[i]; /* in this case, must do AFTER |= hi (See NOTE.) */
    return;
}

#ifndef ARCH_MIN_SSE2
static INLINE void vector_copy(short* VD, short* VS)
{
#if (0)
    memcpy(VD, VS, N*sizeof(short));
#else
    register int i;

    for (i = 0; i < N; i++)
        VD[i] = VS[i];
#endif
    return;
}

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
    for (i = 0; i < N; i++)
        VD[i]  = VACC_M[i];
    for (i = 0; i < N; i++)
        VD[i] &= -(lo[i] ^ 1);
    for (i = 0; i < N; i++)
        VD[i] |= -(hi[i] ^ 0);
    for (i = 0; i < N; i++)
        VD[i] ^= 0x8000 * (hi[i] | lo[i]);
    return;
}
static INLINE void SIGNED_CLAMP_AL(short* VD)
{ /* sign-clamp accumulator-low (bits 15:0) */
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
    for (i = 0; i < N; i++)
        VD[i]  = VACC_L[i];
    for (i = 0; i < N; i++)
        VD[i] &= -(lo[i] ^ 1);
    for (i = 0; i < N; i++)
        VD[i] |= -(hi[i] ^ 0);
    return;
}
#else
#include <emmintrin.h>

/*
 * We actually need to write explicit SSE2 code for this because GCC 4.8.1
 * (and possibly later versions) has a code generation bug with vectorizing
 * the accumulator when it's a signed short (but not when it's unsigned, for
 * some stupid and buggy reason).
 *
 * In addition, as of the more stable GCC 4.7.2 release, while vectorizing
 * the accumulator write-backs into SSE2 for me is successfully done, we save
 * just one extra scalar x86 instruction for every RSP vector op-code when we
 * use SSE2 explicitly for this particular goal instead of letting GCC do it.
 */
static INLINE void vector_copy(short* VD, short* VS)
{
    __m128i xmm;

    xmm = _mm_load_si128((__m128i *)VS);
    _mm_store_si128((__m128i *)VD, xmm);
    return;
}

static INLINE void SIGNED_CLAMP_AM(short* VD)
{ /* typical sign-clamp of accumulator-mid (bits 31:16) */
    __m128i dst, src;
    __m128i pvd, pvs;

    pvs = _mm_load_si128((__m128i *)VACC_H);
    pvd = _mm_load_si128((__m128i *)VACC_M);
    dst = _mm_unpacklo_epi16(pvd, pvs);
    src = _mm_unpackhi_epi16(pvd, pvs);

    dst = _mm_packs_epi32(dst, src);
    _mm_store_si128((__m128i *)VD, dst);
    return;
}
static INLINE void SIGNED_CLAMP_AL(short* VD)
{ /* sign-clamp accumulator-low (bits 15:0) */
    short cond[N];
    short temp[N];
    register int i;

    SIGNED_CLAMP_AM(temp); /* no direct map in SSE, but closely based on this */
    for (i = 0; i < N; i++)
        cond[i] = (temp[i] == VACC_M[i]); /* same storage as without clamping */
    for (i = 0; i < N; i++)
        temp[i] ^= 0x8000; /* half-assed unsigned saturation mix in the clamp */
    merge(VD, cond, VACC_L, temp);
    return;
}
#endif
#endif

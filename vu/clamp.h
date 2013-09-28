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
static INLINE void _MM_sclampz_lo(short* VD)
{
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
 * MarathonMan's accumulator-LOW signed clamp method (SSE2 subset)
 * All credit for the below code goes to CEN64 lead author, not me.
 *
 * I was previously using an ANSI C loop which very closely approached the
 * speed of his algorithm below, but using his intrinsics saved 10 instructs.
 * (And yes, the "_MM_" is a symbolic pun on the author, not MMX/SSE "_mm_".)
 */
static INLINE void _MM_sclampz_lo(short* VD)
{
    __m128i accHi, accMid, accLow;
    __m128i negVal, posVal;
    __m128i negCheck, useValMask;
    __m128i setMask = _mm_cmpeq_epi16(_mm_setzero_si128(), _mm_setzero_si128());

    accHi  = _mm_load_si128((__m128i *)VACC_H);
    accMid = _mm_load_si128((__m128i *)VACC_M);
    accLow = _mm_load_si128((__m128i *)VACC_L);

    /* Compute some common values ahead of time. */
    negCheck = _mm_cmplt_epi16(accHi, _mm_setzero_si128());

    /* If accumulator < 0, clamp to Val if Val != TMin. */
    useValMask = _mm_and_si128(accHi, _mm_srai_epi16(accMid, 15));
    useValMask = _mm_cmpeq_epi16(useValMask, setMask);
    negVal = _mm_and_si128(useValMask, accLow);

    /* Otherwise, clamp to ~0 if any high bits are set. */
    useValMask = _mm_or_si128(accHi, _mm_srai_epi16(accMid, 15));
    useValMask = _mm_cmpeq_epi16(useValMask, _mm_setzero_si128());
    posVal = _mm_and_si128(useValMask, accLow);

    negVal = _mm_and_si128(negCheck, negVal);
    posVal = _mm_andnot_si128(negCheck, posVal);

    _mm_store_si128((__m128i *)VD, _mm_or_si128(negVal, posVal));
    return;
}
#endif
#endif

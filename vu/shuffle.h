#ifndef _SHUFFLE_H
#define _SHUFFLE_H

/*
 * for ANSI compliance (null INLINE attribute if not already set to `inline`)
 * Include "rsp.h" for active, non-ANSI inline definition.
 */
#ifndef INLINE
#define INLINE
#endif

#ifndef ARCH_MIN_SSE2
/*
 * vector-scalar element decoding
 * Obsolete.  Consider using at least the SSE2 algorithms instead.
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

int sub_mask[16] = {
    0x0,
    0x0,
    0x1, 0x1,
    0x3, 0x3, 0x3, 0x3,
    0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7
};

INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{
    short SV[8];
    register int i, j;
#if (0 == 0)
    j = sub_mask[e];
    for (i = 0; i < N; i++)
        SV[i] = VT[(i & ~j) | (e & j)];
#else
    if (e & 0x8)
        for (i = 0; i < N; i++)
            SV[i] = VT[(i & 0x0) | (e & 0x7)];
    else if (e & 0x4)
        for (i = 0; i < N; i++)
            SV[i] = VT[(i & 0xC) | (e & 0x3)];
    else if (e & 0x2)
        for (i = 0; i < N; i++)
            SV[i] = VT[(i & 0xE) | (e & 0x1)];
    else /* if ((e == 0b0000) || (e == 0b0001)) */
        for (i = 0; i < N; i++)
            SV[i] = VT[(i & 0x7) | (e & 0x0)];
#endif
    for (i = 0; i < N; i++)
        *(VD + i) = *(SV + i);
    return;
}
#else
#ifdef ARCH_MIN_SSSE3
static const unsigned char smask[16][16] = {
    {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF},
    {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF},
    {0x0,0x1,0x0,0x1,0x4,0x5,0x4,0x5,0x8,0x9,0x8,0x9,0xC,0xD,0xC,0xD},
    {0x2,0x3,0x2,0x3,0x6,0x7,0x6,0x7,0xA,0xB,0xA,0xB,0xE,0xF,0xE,0xF},
    {0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9},
    {0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB},
    {0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD},
    {0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF},
    {0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1},
    {0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3},
    {0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5},
    {0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7},
    {0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9},
    {0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB},
    {0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD},
    {0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF}
};

INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{ /* SSSE3 shuffling method was written entirely by CEN64 author MarathonMan. */
    __m128i xmm;
    __m128i key;

    xmm = _mm_load_si128((__m128i *)VT);
    key = _mm_load_si128((__m128i *)smask[e & 0xF]);
    xmm = _mm_shuffle_epi8(xmm, key);
    _mm_store_si128((__m128i *)VD, xmm);
    return;
}
#else
#define B(x)    ((x) & 3)
#define SHUFFLE(a,b,c,d)    ((B(d)<<6) | (B(c)<<4) | (B(b)<<2) | (B(a)<<0))

INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{
    __m128i xmm;

    xmm = _mm_load_si128((__m128i *)VT);
    switch (e & 0xF)
    {
        case 0x0:
        case 0x1:
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x2:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(00, 00, 02, 02));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 02, 02));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x3:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(01, 01, 03, 03));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 03, 03));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x4:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(00, 00, 00, 00));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 00, 00));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x5:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(01, 01, 01, 01));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 01, 01));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x6:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(02, 02, 02, 02));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(02, 02, 02, 02));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x7:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(03, 03, 03, 03));
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(03, 03, 03, 03));
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x8:
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 00, 00));
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0x9:
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 01, 01));
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xA:
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(02, 02, 02, 02));
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xB:
            xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(03, 03, 03, 03));
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xC:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(04, 04, 04, 04));
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xD:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(05, 05, 05, 05));
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xE:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(06, 06, 06, 06));
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
        case 0xF:
            xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(07, 07, 07, 07));
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            _mm_store_si128((__m128i *)VD, xmm);
            return;
    }
}
#endif
#endif
#endif

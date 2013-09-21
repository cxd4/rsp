#ifndef _SHUFFLE_H
#define _SHUFFLE_H

#include <emmintrin.h>
/*
 * Another alternative for shuffling is to use SSSE3, but this shuffles on
 * 8-bit iterations, which is less accurate for the 16-bit-slice RSP vectors.
 *
 * SSE2 intrinsics are more than sufficient for RSP vector decoding.
 * The only problem is that they cannot be wielded dynamically per element.
 */

#define B(x)    ((x) & 3)
#define SHUFFLE(a,b,c,d)    ((B(d)<<6) | (B(c)<<4) | (B(b)<<2) | (B(a)<<0))

const unsigned char simm[16] = {
    SHUFFLE(00, 01, 02, 03), /* vector operands */
    SHUFFLE(00, 01, 02, 03),
    SHUFFLE(00, 00, 02, 02), /* scalar quarters */
    SHUFFLE(01, 01, 03, 03),
    SHUFFLE(00, 00, 00, 00), /* scalar halves */
    SHUFFLE(01, 01, 01, 01),
    SHUFFLE(02, 02, 02, 02),
    SHUFFLE(03, 03, 03, 03),
    SHUFFLE(00, 00, 00, 00), /* scalar wholes */
    SHUFFLE(01, 01, 01, 01),
    SHUFFLE(02, 02, 02, 02),
    SHUFFLE(03, 03, 03, 03),
    SHUFFLE(04, 04, 04, 04),
    SHUFFLE(05, 05, 05, 05),
    SHUFFLE(06, 06, 06, 06),
    SHUFFLE(07, 07, 07, 07)
};

static __m128i shuffle_none(__m128i xmm)
{
    const int order = SHUFFLE(00, 01, 02, 03);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_0q(__m128i xmm)
{
    const int order = SHUFFLE(00, 00, 02, 02);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_1q(__m128i xmm)
{
    const int order = SHUFFLE(01, 01, 03, 03);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_0h(__m128i xmm)
{
    const int order = SHUFFLE(00, 00, 00, 00);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_1h(__m128i xmm)
{
    const int order = SHUFFLE(01, 01, 01, 01);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_2h(__m128i xmm)
{
    const int order = SHUFFLE(02, 02, 02, 02);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_3h(__m128i xmm)
{
    const int order = SHUFFLE(03, 03, 03, 03);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_shufflelo_epi16(xmm, order);
    return (xmm);
}
static __m128i shuffle_0w(__m128i xmm)
{
    const int order = SHUFFLE(00, 00, 00, 00);

    xmm = _mm_shufflelo_epi16(xmm, order);
    xmm = _mm_unpacklo_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_1w(__m128i xmm)
{
    const int order = SHUFFLE(01, 01, 01, 01);

    xmm = _mm_shufflelo_epi16(xmm, order);
    xmm = _mm_unpacklo_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_2w(__m128i xmm)
{
    const int order = SHUFFLE(02, 02, 02, 02);

    xmm = _mm_shufflelo_epi16(xmm, order);
    xmm = _mm_unpacklo_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_3w(__m128i xmm)
{
    const int order = SHUFFLE(03, 03, 03, 03);

    xmm = _mm_shufflelo_epi16(xmm, order);
    xmm = _mm_unpacklo_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_4w(__m128i xmm)
{
    const int order = SHUFFLE(04, 04, 04, 04);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_unpackhi_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_5w(__m128i xmm)
{
    const int order = SHUFFLE(05, 05, 05, 05);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_unpackhi_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_6w(__m128i xmm)
{
    const int order = SHUFFLE(06, 06, 06, 06);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_unpackhi_epi16(xmm, xmm);
    return (xmm);
}
static __m128i shuffle_7w(__m128i xmm)
{
    const int order = SHUFFLE(07, 07, 07, 07);

    xmm = _mm_shufflehi_epi16(xmm, order);
    xmm = _mm_unpackhi_epi16(xmm, xmm);
    return (xmm);
}

static __m128i (*SSE2_SHUFFLE_16[16])(__m128i) = {
    shuffle_none, shuffle_none,
    shuffle_0q, shuffle_1q,
    shuffle_0h, shuffle_1h, shuffle_2h, shuffle_3h,
    shuffle_0w, shuffle_1w, shuffle_2w, shuffle_3w,
    shuffle_4w, shuffle_5w, shuffle_6w, shuffle_7w
};

#if (1)
INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{
    __m128i xmm;

    xmm = _mm_load_si128((__m128i *)VT);
    xmm = SSE2_SHUFFLE_16[e](xmm);
    _mm_store_si128((__m128i *)VD, xmm);
    return;
}
#elif (1)
INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{
    __m128i xmm;

    xmm = _mm_load_si128((__m128i *)VT);
    if (e & 0x8) /* scalar wholes */
    {
        if (e & 0x4)
        {
            xmm = _mm_shufflehi_epi16(xmm, simm[e & 0xF]);
            xmm = _mm_unpackhi_epi16(xmm, xmm);
        }
        else
        {
            xmm = _mm_shufflelo_epi16(xmm, simm[e & 0xF]);
            xmm = _mm_unpacklo_epi16(xmm, xmm);
        }
    }
    else
    {
        xmm = _mm_shufflehi_epi16(xmm, simm[e & 0x7]);
        xmm = _mm_shufflelo_epi16(xmm, simm[e & 0x7]);
    }
    _mm_store_si128((__m128i *)VD, xmm);
    return;
}
#else
INLINE static void SHUFFLE_VECTOR(short* VD, short* VT, const int e)
{
    __m128i xmm;

    xmm = _mm_load_si128((__m128i *)VT);
    switch (e & 0xF)
    {
        case 0x0:
        case 0x1:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x0]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x0]);
            break;
        case 0x2:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x2]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x2]);
            break;
        case 0x3:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x3]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x3]);
            break;
        case 0x4:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x4]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x4]);
            break;
        case 0x5:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x5]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x5]);
            break;
        case 0x6:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x6]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x6]);
            break;
        case 0x7:
            xmm = _mm_shufflehi_epi16(xmm, simm[0x7]);
            xmm = _mm_shufflelo_epi16(xmm, simm[0x7]);
            break;
        case 0x8:
            xmm = _mm_shufflelo_epi16(xmm, simm[0x8]);
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            break;
        case 0x9:
            xmm = _mm_shufflelo_epi16(xmm, simm[0x9]);
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            break;
        case 0xA:
            xmm = _mm_shufflelo_epi16(xmm, simm[0xA]);
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            break;
        case 0xB:
            xmm = _mm_shufflelo_epi16(xmm, simm[0xB]);
            xmm = _mm_unpacklo_epi16(xmm, xmm);
            break;
        case 0xC:
            xmm = _mm_shufflehi_epi16(xmm, simm[0xC]);
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            break;
        case 0xD:
            xmm = _mm_shufflehi_epi16(xmm, simm[0xD]);
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            break;
        case 0xE:
            xmm = _mm_shufflehi_epi16(xmm, simm[0xE]);
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            break;
        case 0xF:
            xmm = _mm_shufflehi_epi16(xmm, simm[0xF]);
            xmm = _mm_unpackhi_epi16(xmm, xmm);
            break;
    }
    _mm_store_si128((__m128i *)VD, xmm);
    return;
}
#endif
#endif

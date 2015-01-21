/******************************************************************************\
* Project:  MSP Emulation Layer for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2015.01.21                                                         *
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
#ifndef _VU_H_
#define _VU_H_

#ifdef ARCH_MIN_SSE2
#include <emmintrin.h>
#endif

#include "../my_types.h"

#define N       8
/* N:  number of processor elements in SIMD processor */

/*
 * Illegal, unaligned LWC2 operations on the RSP may write past the terminal
 * byte of a vector, while SWC2 operations may have to wrap around stores
 * from the end to the start of a vector.  Both of these risk out-of-bounds
 * memory access, but by doubling the number of bytes allocated (shift left)
 * per each vector register, we could stabilize and probably optimize this.
 */
#if 0
#define VR_STATIC_WRAPAROUND    0
#else
#define VR_STATIC_WRAPAROUND    1
#endif

/*
 * We are going to need this for vector operations doing scalar things.
 * The divides and VSAW need bit-wise information from the instruction word.
 */
extern u32 inst;

/*
 * RSP virtual registers (of vector unit)
 * The most important are the 32 general-purpose vector registers.
 * The correct way to accurately store these is using big-endian vectors.
 *
 * For ?WC2 we may need to do byte-precision access just as directly.
 * This is amended by using the `VU_S` and `VU_B` macros defined in `rsp.h`.
 */
ALIGNED extern i16 VR[32][N << VR_STATIC_WRAPAROUND];

/*
 * The RSP accumulator is a vector of 3 48-bit integers.  Nearly all of the
 * vector operations access it, but it's for multiply-accumulate operations.
 *
 * Access dimensions would be VACC[8][3] but are inverted for SIMD benefits.
 */
ALIGNED extern i16 VACC[3][N];

/*
 * When compiling without SSE2, we need to use a pointer to a destination
 * vector instead of an XMM register in the return slot of the function.
 * The vector "result" register will be emulated to serve this pointer
 * as a shared global rather than the return slot of a function call.
 */
#ifndef ARCH_MIN_SSE2
ALIGNED extern i16 V_result[N];
#endif

/*
 * accumulator-indexing macros
 */
#define HI      00
#define MD      01
#define LO      02

#define VACC_L      (VACC[LO])
#define VACC_M      (VACC[MD])
#define VACC_H      (VACC[HI])

#define ACC_L(i)    (VACC_L)[i]
#define ACC_M(i)    (VACC_M)[i]
#define ACC_H(i)    (VACC_H)[i]

#ifdef ARCH_MIN_SSE2
typedef __m128i v16;
#else
typedef pi16 v16;
#endif

#ifdef ARCH_MIN_SSE2
#define VECTOR_OPERATION    v16
#else
#define VECTOR_OPERATION    void
#endif
#define VECTOR_EXTERN       extern VECTOR_OPERATION

NOINLINE extern void message(const char* body);

VECTOR_EXTERN (*COP2_C2[8*7 + 8])(v16, v16);

#ifdef ARCH_MIN_SSE2

#define vector_copy(vd, vs) { \
    *(v16 *)(vd) = *(v16 *)(vs); }
#define vector_wipe(vd) { \
    (vd) = _mm_xor_si128(vd, vd); }
#define vector_fill(vd) { \
    (vd) = _mm_cmpeq_epi16(vd, vd); }

#define vector_and(vd, vs) { \
    (vd) = _mm_and_si128    (vd, vs); }
#define vector_or(vd, vs) { \
    (vd) = _mm_or_si128     (vd, vs); }
#define vector_xor(vd, vs) { \
    (vd) = _mm_xor_si128    (vd, vs); }

/*
 * Every competent vector unit should have at least two vector comparison
 * operations:  EQ and LT/GT.  (MMX makes us say GT; SSE's LT is just a GT.)
 *
 * Default examples when compiling for the x86 SSE2 architecture below.
 */
#define vector_cmplt(vd, vs) { \
    (vd) = _mm_cmplt_epi16  (vd, vs); }
#define vector_cmpeq(vd, vs) { \
    (vd) = _mm_cmpeq_epi16  (vd, vs); }
#define vector_cmpgt(vd, vs) { \
    (vd) = _mm_cmpgt_epi16  (vd, vs); }

#else

#define vector_copy(vd, vs) { \
    (vd)[0] = (vs)[0]; \
    (vd)[1] = (vs)[1]; \
    (vd)[2] = (vs)[2]; \
    (vd)[3] = (vs)[3]; \
    (vd)[4] = (vs)[4]; \
    (vd)[5] = (vs)[5]; \
    (vd)[6] = (vs)[6]; \
    (vd)[7] = (vs)[7]; \
}
#define vector_wipe(vd) { \
    (vd)[0] =  0x0000; \
    (vd)[1] =  0x0000; \
    (vd)[2] =  0x0000; \
    (vd)[3] =  0x0000; \
    (vd)[4] =  0x0000; \
    (vd)[5] =  0x0000; \
    (vd)[6] =  0x0000; \
    (vd)[7] =  0x0000; \
}
#define vector_fill(vd) { \
    (vd)[0] = ~0x0000; \
    (vd)[1] = ~0x0000; \
    (vd)[2] = ~0x0000; \
    (vd)[3] = ~0x0000; \
    (vd)[4] = ~0x0000; \
    (vd)[5] = ~0x0000; \
    (vd)[6] = ~0x0000; \
    (vd)[7] = ~0x0000; \
}
#define vector_and(vd, vs) { \
    (vd)[0] &= (vs)[0]; \
    (vd)[1] &= (vs)[1]; \
    (vd)[2] &= (vs)[2]; \
    (vd)[3] &= (vs)[3]; \
    (vd)[4] &= (vs)[4]; \
    (vd)[5] &= (vs)[5]; \
    (vd)[6] &= (vs)[6]; \
    (vd)[7] &= (vs)[7]; \
}
#define vector_or(vd, vs) { \
    (vd)[0] |= (vs)[0]; \
    (vd)[1] |= (vs)[1]; \
    (vd)[2] |= (vs)[2]; \
    (vd)[3] |= (vs)[3]; \
    (vd)[4] |= (vs)[4]; \
    (vd)[5] |= (vs)[5]; \
    (vd)[6] |= (vs)[6]; \
    (vd)[7] |= (vs)[7]; \
}
#define vector_xor(vd, vs) { \
    (vd)[0] ^= (vs)[0]; \
    (vd)[1] ^= (vs)[1]; \
    (vd)[2] ^= (vs)[2]; \
    (vd)[3] ^= (vs)[3]; \
    (vd)[4] ^= (vs)[4]; \
    (vd)[5] ^= (vs)[5]; \
    (vd)[6] ^= (vs)[6]; \
    (vd)[7] ^= (vs)[7]; \
}

#define vector_cmplt(vd, vs) { \
    (vd)[0] = ((vd)[0] < (vs)[0]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[1] < (vs)[1]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[2] < (vs)[2]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[3] < (vs)[3]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[4] < (vs)[4]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[5] < (vs)[5]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[6] < (vs)[6]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[7] < (vs)[7]) ? ~0x0000 :  0x0000; \
}
#define vector_cmpeq(vd, vs) { \
    (vd)[0] = ((vd)[0] == (vs)[0]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[1] == (vs)[1]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[2] == (vs)[2]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[3] == (vs)[3]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[4] == (vs)[4]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[5] == (vs)[5]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[6] == (vs)[6]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[7] == (vs)[7]) ? ~0x0000 :  0x0000; \
}
#define vector_cmpgt(vd, vs) { \
    (vd)[0] = ((vd)[0] > (vs)[0]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[1] > (vs)[1]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[2] > (vs)[2]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[3] > (vs)[3]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[4] > (vs)[4]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[5] > (vs)[5]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[6] > (vs)[6]) ? ~0x0000 :  0x0000; \
    (vd)[0] = ((vd)[7] > (vs)[7]) ? ~0x0000 :  0x0000; \
}

#endif

/*
 * Considering that almost all of the computational vector unit operations
 * concern a shuffled, halfword-swapped target vector, a centralized method
 * for shuffling said vector into a new vector temporary register,
 * ST = VR[vt], should be pretty convenient.
 */
INLINE VECTOR_EXTERN SHUFFLE_VECTOR(v16 VD, const int e);

/*
 * Many vector units have pairs of "vector condition flags" registers.
 * In SGI's vector unit implementation, these are denoted as the
 * "vector control registers" under coprocessor 2.
 *
 * VCF-0 is the carry-out flags register:  $vco.
 * VCF-1 is the compare code flags register:  $vcc.
 * VCF-2 is the compare extension flags register:  $vce.
 * There is no fourth RSP flags register.
 */
extern u16 VCO;
extern u16 VCC;
extern u8 VCE;

ALIGNED extern i16 ne[8];
ALIGNED extern i16 co[8];
ALIGNED extern i16 clip[8];
ALIGNED extern i16 comp[8];
ALIGNED extern i16 vce[8];

extern u16 get_VCO(void);
extern u16 get_VCC(void);
extern u8 get_VCE(void);

extern void set_VCO(u16 VCO);
extern void set_VCC(u16 VCC);
extern void set_VCE(u8 VCE);

/*
 * shuffling convenience macros for Intel SIMD
 * An 8-bit shuffle imm. of SHUFFLE(0, 1, 2, 3) should be a null operation.
 */
#define B(x)    ((x) & 3)
#define SHUFFLE(a,b,c,d)    ((B(d)<<6) | (B(c)<<4) | (B(b)<<2) | (B(a)<<0))

#endif

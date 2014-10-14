/******************************************************************************\
* Project:  MSP Emulation Layer for Vector Unit Computational Operations       *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.14                                                         *
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

#include "vu.h"

#include "multiply.h"
#include "add.h"
#include "select.h"
#include "logical.h"
#include "divide.h"
#if 0
#include "pack.h"
#endif

ALIGNED short VR[32][N];
ALIGNED short VACC[3][N];

/*
 * These normally should have type `int` because they are Boolean T/F arrays.
 * However, since SSE2 uses 128-bit XMM's, and Win32 `int` storage is 32-bit,
 * we have the problem of 32*8 > 128 bits, so we use `short` to reduce packs.
 */
ALIGNED short ne[8]; /* $vco:  high byte "NOTEQUAL" */
ALIGNED short co[8]; /* $vco:  low byte "carry/borrow in/out" */
ALIGNED short clip[8]; /* $vcc:  high byte (clip tests:  VCL, VCH, VCR) */
ALIGNED short comp[8]; /* $vcc:  low byte (VEQ, VNE, VLT, VGE, VCL, VCH, VCR) */
ALIGNED short vce[8]; /* $vce:  vector compare extension register */

VECTOR_OPERATION res_V(v16 vd, v16 vs, v16 vt)
{
#ifdef ARCH_MIN_SSE2
    vd = _mm_setzero_si128();
#else
    register int i;

    for (i = 0; i < N; i++)
        vd[i] = 0x0000; /* override behavior (bpoint) */
#endif
    vs = vt = vd; /* unused */
    message("C2\nRESERVED"); /* uncertain how to handle reserved, untested */
    return (vd);
}
VECTOR_OPERATION res_M(v16 vd, v16 vs, v16 vt)
{ /* Ultra64 OS did have these, so one could implement this ext. */
    message("VMUL IQ");
    vd = res_V(vd, vs, vt);
    return (vd);
}

v16 (*COP2_C2[64])(v16, v16, v16) = {
    VMULF  ,VMULU  ,res_M  ,res_M  ,VMUDL  ,VMUDM  ,VMUDN  ,VMUDH  , /* 000 */
    VMACF  ,VMACU  ,res_M  ,VMACQ  ,VMADL  ,VMADM  ,VMADN  ,VMADH  , /* 001 */
    VADD   ,VSUB   ,res_V  ,VABS   ,VADDC  ,VSUBC  ,res_V  ,res_V  , /* 010 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,VSAW   ,res_V  ,res_V  , /* 011 */
    VLT    ,VEQ    ,VNE    ,VGE    ,VCL    ,VCH    ,VCR    ,VMRG   , /* 100 */
    VAND   ,VNAND  ,VOR    ,VNOR   ,VXOR   ,VNXOR  ,res_V  ,res_V  , /* 101 */
    VRCP   ,VRCPL  ,VRCPH  ,VMOV   ,VRSQ   ,VRSQL  ,VRSQH  ,VNOP   , /* 110 */
    res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  ,res_V  , /* 111 */
}; /* 000     001     010     011     100     101     110     111 */

#ifndef ARCH_MIN_SSE2
unsigned short get_VCO(void)
{
    register unsigned short VCO;

    VCO = 0x0000
      | (ne[0xF % 8] << 0xF)
      | (ne[0xE % 8] << 0xE)
      | (ne[0xD % 8] << 0xD)
      | (ne[0xC % 8] << 0xC)
      | (ne[0xB % 8] << 0xB)
      | (ne[0xA % 8] << 0xA)
      | (ne[0x9 % 8] << 0x9)
      | (ne[0x8 % 8] << 0x8)
      | (co[0x7 % 8] << 0x7)
      | (co[0x6 % 8] << 0x6)
      | (co[0x5 % 8] << 0x5)
      | (co[0x4 % 8] << 0x4)
      | (co[0x3 % 8] << 0x3)
      | (co[0x2 % 8] << 0x2)
      | (co[0x1 % 8] << 0x1)
      | (co[0x0 % 8] << 0x0);
    return (VCO); /* Big endian becomes little. */
}
unsigned short get_VCC(void)
{
    register unsigned short VCC;

    VCC = 0x0000
      | (clip[0xF % 8] << 0xF)
      | (clip[0xE % 8] << 0xE)
      | (clip[0xD % 8] << 0xD)
      | (clip[0xC % 8] << 0xC)
      | (clip[0xB % 8] << 0xB)
      | (clip[0xA % 8] << 0xA)
      | (clip[0x9 % 8] << 0x9)
      | (clip[0x8 % 8] << 0x8)
      | (comp[0x7 % 8] << 0x7)
      | (comp[0x6 % 8] << 0x6)
      | (comp[0x5 % 8] << 0x5)
      | (comp[0x4 % 8] << 0x4)
      | (comp[0x3 % 8] << 0x3)
      | (comp[0x2 % 8] << 0x2)
      | (comp[0x1 % 8] << 0x1)
      | (comp[0x0 % 8] << 0x0);
    return (VCC); /* Big endian becomes little. */
}
unsigned char get_VCE(void)
{
    int result;
    register unsigned char VCE;

    result = 0x00
      | (vce[07] << 0x7)
      | (vce[06] << 0x6)
      | (vce[05] << 0x5)
      | (vce[04] << 0x4)
      | (vce[03] << 0x3)
      | (vce[02] << 0x2)
      | (vce[01] << 0x1)
      | (vce[00] << 0x0);
    VCE = (unsigned char)(result);
    return (VCE); /* Big endian becomes little. */
}
#else
unsigned short get_VCO(void)
{
    v16 xmm, hi, lo;
    register unsigned short VCO;

    hi = _mm_load_si128((v16 *)ne);
    lo = _mm_load_si128((v16 *)co);

/*
 * Rotate Boolean storage from LSB to MSB.
 */
    hi = _mm_slli_epi16(hi, 15);
    lo = _mm_slli_epi16(lo, 15);

    xmm = _mm_packs_epi16(lo, hi); /* Decompress INT16 Booleans to INT8 ones. */
    VCO = _mm_movemask_epi8(xmm) & 0x0000FFFF; /* PMOVMSKB combines each MSB. */
    return (VCO);
}
unsigned short get_VCC(void)
{
    v16 xmm, hi, lo;
    register unsigned short VCC;

    hi = _mm_load_si128((v16 *)clip);
    lo = _mm_load_si128((v16 *)comp);

/*
 * Rotate Boolean storage from LSB to MSB.
 */
    hi = _mm_slli_epi16(hi, 15);
    lo = _mm_slli_epi16(lo, 15);

    xmm = _mm_packs_epi16(lo, hi); /* Decompress INT16 Booleans to INT8 ones. */
    VCC = _mm_movemask_epi8(xmm) & 0x0000FFFF; /* PMOVMSKB combines each MSB. */
    return (VCC);
}
unsigned char get_VCE(void)
{
    v16 xmm, hi, lo;
    register unsigned char VCE;

    hi = _mm_setzero_si128();
    lo = _mm_load_si128((v16 *)vce);

    lo = _mm_slli_epi16(lo, 15); /* Rotate Boolean storage from LSB to MSB. */

    xmm = _mm_packs_epi16(lo, hi); /* Decompress INT16 Booleans to INT8 ones. */
    VCE = _mm_movemask_epi8(xmm) & 0x000000FF; /* PMOVMSKB combines each MSB. */
    return (VCE);
}
#endif

/*
 * CTC2 resources
 * not sure how to vectorize going the other direction into SSE2
 */
void set_VCO(unsigned short VCO)
{
    register int i;

    for (i = 0; i < 8; i++)
        co[i] = (VCO >> (i + 0x0)) & 1;
    for (i = 0; i < 8; i++)
        ne[i] = (VCO >> (i + 0x8)) & 1;
    return; /* Little endian becomes big. */
}
void set_VCC(unsigned short VCC)
{
    register int i;

    for (i = 0; i < 8; i++)
        comp[i] = (VCC >> (i + 0x0)) & 1;
    for (i = 0; i < 8; i++)
        clip[i] = (VCC >> (i + 0x8)) & 1;
    return; /* Little endian becomes big. */
}
void set_VCE(unsigned char VCE)
{
    register int i;

    for (i = 0; i < 8; i++)
        vce[i] = (VCE >> i) & 1;
    return; /* Little endian becomes big. */
}

#ifndef ARCH_MIN_SSE2
/*
 * vector-scalar element decoding
 * Obsolete.  Consider using at least the SSE2 algorithms instead.
 */
static const int ei[1 << 4][8] = {
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

INLINE v16 SHUFFLE_VECTOR(v16 VD, i16* VT, const int e)
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
    return (VD);
}
#else
#ifdef ARCH_MIN_SSSE3
static const unsigned char smask[16][16] = {
    { 0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF },
    { 0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF },
    { 0x0,0x1,0x0,0x1,0x4,0x5,0x4,0x5,0x8,0x9,0x8,0x9,0xC,0xD,0xC,0xD },
    { 0x2,0x3,0x2,0x3,0x6,0x7,0x6,0x7,0xA,0xB,0xA,0xB,0xE,0xF,0xE,0xF },
    { 0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9 },
    { 0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB },
    { 0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD },
    { 0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF },
    { 0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1 },
    { 0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3,0x2,0x3 },
    { 0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5,0x4,0x5 },
    { 0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7,0x6,0x7 },
    { 0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9,0x8,0x9 },
    { 0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB,0xA,0xB },
    { 0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD,0xC,0xD },
    { 0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF,0xE,0xF },
};

INLINE v16 SHUFFLE_VECTOR(v16 VD, i16* VT, const int e)
{ /* SSSE3 shuffling method was written entirely by CEN64 author MarathonMan. */
    v16 xmm;
    v16 key;

    xmm = _mm_load_si128((v16 *)VT);
    key = _mm_load_si128((v16 *)(smask[e]));
    xmm = _mm_shuffle_epi8(xmm, key);
    VD = xmm;
    return (VD);
}
#else
#define B(x)    ((x) & 3)
#define SHUFFLE(a,b,c,d)    ((B(d)<<6) | (B(c)<<4) | (B(b)<<2) | (B(a)<<0))

INLINE v16 SHUFFLE_VECTOR(v16 VD, i16* VT, const int e)
{
    v16 xmm;

    xmm = *(v16 *)VT;
    switch (e & 0xF)
    {
case 0x0: /* none */
case 0x1:
     /* xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 01, 02, 03)); */
     /* xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(04, 05, 06, 07)); */
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x2: /* 0q */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 02, 02));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(04, 04, 06, 06));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x3: /* 1q */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 03, 03));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(05, 05, 07, 07));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x4: /* 0h */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 00, 00));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(04, 04, 04, 04));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x5: /* 1h */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 01, 01));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(05, 05, 05, 05));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x6: /* 2h */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(02, 02, 02, 02));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(06, 06, 06, 06));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x7: /* 3h */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(03, 03, 03, 03));
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(07, 07, 07, 07));
     /* xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 2/2, 4/2, 6/2)); */
        break;
case 0x8: /* 0w */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(00, 00, 00, 00));
     /* xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(00, 00, 00, 00)); */
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(0/2, 0/2, 0/2, 0/2));
        break;
case 0x9: /* 1w */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(01, 01, 01, 01));
     /* xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(01, 01, 01, 01)); */
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(1/2, 1/2, 1/2, 1/2));
        break;
case 0xA: /* 2w */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(02, 02, 02, 02));
     /* xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(02, 02, 02, 02)); */
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(2/2, 2/2, 2/2, 2/2));
        break;
case 0xB: /* 3w */
        xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(03, 03, 03, 03));
     /* xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(03, 03, 03, 03)); */
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(3/2, 3/2, 3/2, 3/2));
        break;
case 0xC: /* 4w */
     /* xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(04, 04, 04, 04)); */
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(04, 04, 04, 04));
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(4/2, 4/2, 4/2, 4/2));
        break;
case 0xD: /* 5w */
     /* xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(05, 05, 05, 05)); */
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(05, 05, 05, 05));
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(5/2, 5/2, 5/2, 5/2));
        break;
case 0xE: /* 6w */
     /* xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(06, 06, 06, 06)); */
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(06, 06, 06, 06));
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(6/2, 6/2, 6/2, 6/2));
        break;
case 0xF: /* 7w */
     /* xmm = _mm_shufflelo_epi16(xmm, SHUFFLE(07, 07, 07, 07)); */
        xmm = _mm_shufflehi_epi16(xmm, SHUFFLE(07, 07, 07, 07));
        xmm = _mm_shuffle_epi32(xmm, SHUFFLE(7/2, 7/2, 7/2, 7/2));
        break;
    }
    VD = xmm;
    return (VD);
}
#endif
#endif

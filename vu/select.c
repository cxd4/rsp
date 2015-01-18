/******************************************************************************\
* Project:  MSP Simulation Layer for Vector Unit Computational Test Selects    *
* Authors:  Iconoclast                                                         *
* Release:  2015.01.17                                                         *
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

#include "select.h"

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
INLINE void merge(short* VD, short* cmp, short* pass, short* fail)
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

INLINE static void do_lt(short* VD, short* VS, short* VT)
{
    short cn[N];
    short eq[N];
    register int i;

    for (i = 0; i < N; i++)
        eq[i] = (VS[i] == VT[i]);
    for (i = 0; i < N; i++)
        cn[i] = ne[i] & co[i];
    for (i = 0; i < N; i++)
        eq[i] = eq[i] & cn[i];
    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] < VT[i]); /* less than */
    for (i = 0; i < N; i++)
        comp[i] = comp[i] | eq[i]; /* ... or equal (uncommonly) */

    merge(VACC_L, comp, VS, VT);
    vector_copy(VD, VACC_L);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

INLINE static void do_eq(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] == VT[i]);
    for (i = 0; i < N; i++)
        comp[i] = comp[i] & (ne[i] ^ 1);
#if (0)
    merge(VACC_L, comp, VS, VT); /* correct but redundant */
#else
    vector_copy(VACC_L, VT);
#endif
    vector_copy(VD, VACC_L);

    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

INLINE static void do_ne(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] != VT[i]);
    for (i = 0; i < N; i++)
        comp[i] = comp[i] | ne[i];
#if (0)
    merge(VACC_L, comp, VS, VT); /* correct but redundant */
#else
    vector_copy(VACC_L, VS);
#endif
    vector_copy(VD, VACC_L);

    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

INLINE static void do_ge(short* VD, short* VS, short* VT)
{
    short ce[N];
    short eq[N];
    register int i;

    for (i = 0; i < N; i++)
        eq[i] = (VS[i] == VT[i]);
    for (i = 0; i < N; i++)
        ce[i] = (ne[i] & co[i]) ^ 1;
    for (i = 0; i < N; i++)
        eq[i] = eq[i] & ce[i];
    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] > VT[i]); /* greater than */
    for (i = 0; i < N; i++)
        comp[i] = comp[i] | eq[i]; /* ... or equal (commonly) */

    merge(VACC_L, comp, VS, VT);
    vector_copy(VD, VACC_L);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

INLINE static void do_cl(short* VD, short* VS, short* VT)
{
    ALIGNED unsigned short VB[N], VC[N];
    ALIGNED short eq[N], ge[N], le[N];
    ALIGNED short gen[N], len[N], lz[N], uz[N], sn[N];
    short diff[N];
    short cmp[N];
    register int i;

    vector_copy((short *)VB, VS);
    vector_copy((short *)VC, VT);

/*
    for (i = 0; i < N; i++)
        ge[i] = clip[i];
    for (i = 0; i < N; i++)
        le[i] = comp[i];
*/
    for (i = 0; i < N; i++)
        eq[i] = ne[i] ^ 1;
    vector_copy(sn, co);

/*
 * Now that we have extracted all the flags, we will essentially be masking
 * them back in where they came from redundantly, unless the corresponding
 * NOTEQUAL bit from VCO upper was not set....
 */
    for (i = 0; i < N; i++)
        VC[i] = VC[i] ^ -sn[i];
    for (i = 0; i < N; i++)
        VC[i] = VC[i] + sn[i]; /* conditional negation, if sn */
    for (i = 0; i < N; i++)
        diff[i] = VB[i] - VC[i];
    for (i = 0; i < N; i++)
        uz[i] = (VB[i] + (unsigned short)VT[i] - 65536) >> 31;
    for (i = 0; i < N; i++)
        lz[i] = (diff[i] == 0x0000);
    for (i = 0; i < N; i++)
        gen[i] = lz[i] | uz[i];
    for (i = 0; i < N; i++)
        len[i] = lz[i] & uz[i];
    for (i = 0; i < N; i++)
        gen[i] = gen[i] & vce[i];
    for (i = 0; i < N; i++)
        len[i] = len[i] & (vce[i] ^ 1);
    for (i = 0; i < N; i++)
        len[i] = len[i] | gen[i];
    for (i = 0; i < N; i++)
        gen[i] = (VB[i] >= VC[i]);

    for (i = 0; i < N; i++)
        cmp[i] = eq[i] & sn[i];
    merge(le, cmp, len, comp);

    for (i = 0; i < N; i++)
        cmp[i] = eq[i] & (sn[i] ^ 1);
    merge(ge, cmp, gen, clip);

    merge(cmp, sn, le, ge);
    merge(VACC_L, cmp, (short *)VC, VS);
    vector_copy(VD, VACC_L);

    vector_copy(clip, ge);
    vector_copy(comp, le);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    for (i = 0; i < N; i++)
        vce[i] = 0;
    return;
}

INLINE static void do_ch(short* VD, short* VS, short* VT)
{
    ALIGNED short VC[N];
    ALIGNED short eq[N], ge[N], le[N];
    ALIGNED short sn[N];
#ifndef _DEBUG
    short diff[N];
#endif
    register int i;

    vector_copy(VC, VT);
    for (i = 0; i < N; i++)
        sn[i] = VS[i] ^ VT[i];
    for (i = 0; i < N; i++)
        sn[i] = (sn[i] < 0) ? ~0 :  0; /* signed SRA (sn), 15 */
    for (i = 0; i < N; i++)
        VC[i] ^= sn[i]; /* if (sn == ~0) {VT = ~VT;} else {VT =  VT;} */
    for (i = 0; i < N; i++)
        vce[i]  = (VS[i] == VC[i]); /* 2's complement:  VC = -VT - 1, or ~VT. */
    for (i = 0; i < N; i++)
        vce[i] &= sn[i];
    for (i = 0; i < N; i++)
        VC[i] -= sn[i]; /* converts ~(VT) into -(VT) if (sign) */
    for (i = 0; i < N; i++)
        eq[i]  = (VS[i] == VC[i]);
    for (i = 0; i < N; i++)
        eq[i] |= vce[i];

#ifdef _DEBUG
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VS[i] <= VC[i]) : (VC[i] < 0);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (VC[i] > 0x0000) : (VS[i] >= VC[i]);
#elif (0)
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VT[i] <= -VS[i]) : (VT[i] <= ~0x0000);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (~0x0000 >= VT[i]) : (VS[i] >= VT[i]);
#else
    for (i = 0; i < N; i++)
        diff[i] = sn[i] | VS[i];
    for (i = 0; i < N; i++)
        ge[i] = (diff[i] >= VT[i]);

    for (i = 0; i < N; i++)
        sn[i] = (unsigned short)(sn[i]) >> 15; /* ~0 to 1, 0 to 0 */

    for (i = 0; i < N; i++)
        diff[i] = VC[i] - VS[i];
    for (i = 0; i < N; i++)
        diff[i] = (diff[i] >= 0);
    for (i = 0; i < N; i++)
        le[i] = (VT[i] < 0);
    merge(le, sn, diff, le);
#endif

    merge(comp, sn, le, ge);
    merge(VACC_L, comp, VC, VS);
    vector_copy(VD, VACC_L);

    vector_copy(clip, ge);
    vector_copy(comp, le);
    for (i = 0; i < N; i++)
        ne[i] = eq[i] ^ 1;
    vector_copy(co, sn);
    return;
}

INLINE static void do_cr(short* VD, short* VS, short* VT)
{
    ALIGNED short ge[N], le[N], sn[N];
    ALIGNED short VC[N];
    short cmp[N];
    register int i;

    vector_copy(VC, VT);
    for (i = 0; i < N; i++)
        sn[i] = VS[i] ^ VT[i];
    for (i = 0; i < N; i++)
        sn[i] = (sn[i] < 0) ? ~0 : 0;
#ifdef _DEBUG
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VT[i] <= ~VS[i]) : (VT[i] <= ~0x0000);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (~0x0000 >= VT[i]) : (VS[i] >= VT[i]);
#else
    for (i = 0; i < N; i++)
        cmp[i] = ~(VS[i] & sn[i]);
    for (i = 0; i < N; i++)
        le[i] = (VT[i] <= cmp[i]);
    for (i = 0; i < N; i++)
        cmp[i] =  (VS[i] | sn[i]);
    for (i = 0; i < N; i++)
        ge[i] = (cmp[i] >= VT[i]);
#endif
    for (i = 0; i < N; i++)
        VC[i] ^= sn[i]; /* if (sn == ~0) {VT = ~VT;} else {VT =  VT;} */
    merge(cmp, sn, le, ge);
    merge(VACC_L, cmp, VC, VS);
    vector_copy(VD, VACC_L);

    vector_copy(clip, ge);
    vector_copy(comp, le);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    for (i = 0; i < N; i++)
        vce[i] = 0;
    return;
}

INLINE static void do_mrg(short* VD, short* VS, short* VT)
{
    merge(VACC_L, comp, VS, VT);
    vector_copy(VD, VACC_L);
    return;
}

VECTOR_OPERATION VLT(v16 vs, v16 vt)
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
    do_lt(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VEQ(v16 vs, v16 vt)
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
    do_eq(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VNE(v16 vs, v16 vt)
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
    do_ne(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VGE(v16 vs, v16 vt)
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
    do_ge(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VCL(v16 vs, v16 vt)
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
    do_cl(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VCH(v16 vs, v16 vt)
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
    do_ch(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VCR(v16 vs, v16 vt)
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
    do_cr(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

VECTOR_OPERATION VMRG(v16 vs, v16 vt)
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
    do_mrg(VD, VS, VT);
#ifdef ARCH_MIN_SSE2
    vs = *(v16 *)VD;
    return (vs);
#else
    vector_copy(V_result, VD);
    return;
#endif
}

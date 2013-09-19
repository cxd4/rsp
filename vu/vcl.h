#include "vu.h"

void do_cl(short* VD, short* VS, short* VT)
{
    int eq[N];
    int ge[N], le[N];
    int lz[N], uz[N];
    int dif[N], gen[N], len[N]; /* temporaries for computing flag corrections */
    short VC[N];
    signed short sn[N];
    register int i;

    memcpy(VC, VT, N*sizeof(short));
    for (i = 0; i < N; i++)
        ge[i] = clip[i];
    for (i = 0; i < N; i++)
        le[i] = comp[i];
    for (i = 0; i < N; i++)
        eq[i] = ne[i] ^ 1;
    for (i = 0; i < N; i++)
        sn[i] = -co[i];
/*
 * Now that we have extracted all the flags, we will essentially be masking
 * them back in where they came from redundantly, unless the corresponding
 * NOTEQUAL bit from VCO upper was not set....
 */
    for (i = 0; i < N; i++)
        VC[i] = VC[i] ^ sn[i];
    for (i = 0; i < N; i++)
        VC[i] = VC[i] - sn[i]; /* conditional negation, if sn */
    for (i = 0; i < N; i++)
        dif[i] = VS[i] - VC[i]; /* of course, if sn, VS + VT, not VS - VT */
    for (i = 0; i < N; i++)
        lz[i] = !(dif[i] &  0x0000FFFF);
    for (i = 0; i < N; i++)
        uz[i] = !(dif[i] & ~0x0000FFFF);
    for (i = 0; i < N; i++)
        gen[i] = lz[i] | uz[i];
    for (i = 0; i < N; i++)
        len[i] = lz[i] & uz[i];
    for (i = 0; i < N; i++)
        gen[i] = gen[i] & vce[i];
    for (i = 0; i < N; i++)
        vce[i] = ~vce[i]; /* vce[i] = (vce[i] ^ 1) */
    for (i = 0; i < N; i++)
        len[i] = len[i] & vce[i]; /* ... & (vce[i] ^ 1) */
    for (i = 0; i < N; i++)
        len[i] = len[i] | gen[i];
    for (i = 0; i < N; i++)
        gen[i] = (dif[i] >= 0x0000);
    for (i = 0; i < N; i++)
        le[i] = (eq[i] &  sn[i]) ? len[i] : le[i];
    for (i = 0; i < N; i++)
        ge[i] = (eq[i] & ~sn[i]) ? gen[i] : ge[i];
    for (i = 0; i < N; i++)
        eq[i] = sn[i] ? le[i] : ge[i];
    for (i = 0; i < N; i++)
        ACC_L(i) = eq[i] ? VC[i] : VS[i];
    memcpy(VD, VACC_L, N*sizeof(short));

    for (i = 0; i < N; i++)
        clip[i] = ge[i];
    for (i = 0; i < N; i++)
        comp[i] = le[i];
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    for (i = 0; i < N; i++)
        vce[i] = 0;
    return;
}

static void VCL_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_cl(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VCL0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}
static void VCL7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    do_cl(VR[vd], VR[vs], SV);
    return;
}

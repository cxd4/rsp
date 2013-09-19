#include "vu.h"

void do_cr(short* VD, short* VS, short* VT)
{
    int ge[N], le[N];
    short temp[N];
    short VC[N];
    signed short sn[N];
    register int i;

    memcpy(VC, VT, N*sizeof(short));
    for (i = 0; i < N; i++)
        sn[i] = VS[i] ^ VC[i];
    for (i = 0; i < N; i++)
        sn[i] = sn[i] >> 15;
#if (0)
    for (i = 0; i < N; i++)
        le[i] = sn[i] ? (VC[i] <= ~VS[i]) : (VC[i] <= ~0x0000);
    for (i = 0; i < N; i++)
        ge[i] = sn[i] ? (~0x0000 >= VC[i]) : (VS[i] >= VC[i]);
#else
    for (i = 0; i < N; i++)
        temp[i] = VS[i] & sn[i];
    for (i = 0; i < N; i++)
        le[i] = (VC[i] <= ~temp[i]);
    for (i = 0; i < N; i++)
        temp[i] = VS[i] | sn[i];
    for (i = 0; i < N; i++)
        ge[i] = (temp[i] >=  VC[i]);
#endif
    for (i = 0; i < N; i++)
        VC[i] ^= sn[i]; /* if (sn == ~0) {VT = ~VT;} else {VT =  VT;} */
    for (i = 0; i < N; i++)
        ACC_L(i) = le[i] ? VC[i] : VS[i];
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

static void VCR_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_cr(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VCR0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}
static void VCR7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    do_cr(VR[vd], VR[vs], SV);
    return;
}

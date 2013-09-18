#include "vu.h"

INLINE void do_mudn(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = (unsigned short)(VS[i]) * (signed short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (acc[i] & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        ACC_M(i) = (acc[i] & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        ACC_H(i) = -(ACC_M(i) < 0); /* internal sign-extended shift */
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i); /* no possibilities to clamp */
    return;
}

static void VMUDN_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mudn(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMUDN0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 02);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 03);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 04);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 05);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 06);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 07);
    STORE_VECTOR(SV, VT);
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN0w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x8 & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN1w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x9 & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN2w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xA & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN3w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xB & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN4w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xC & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN5w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xD & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN6w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xE & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}
static void VMUDN7w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xF & 0x7) + (i & 0x0)];
    do_mudn(VR[vd], VR[vs], SV);
    return;
}

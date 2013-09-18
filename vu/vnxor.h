#include "vu.h"

INLINE void do_nxor(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VS[i] ^ VT[i]);
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    return;
}

static void VNXOR_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_nxor(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VNXOR0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 02);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 03);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 04);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 05);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 06);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 07);
    STORE_VECTOR(SV, VT);
    do_nxor(VR[vd], VR[vs], SV);
    return;
}
static void VNXOR0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0x8 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0x9 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xA & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xB & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xC & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xD & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xE & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNXOR7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] ^ VR[vt][(0xF & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

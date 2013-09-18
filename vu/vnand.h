#include "vu.h"

INLINE void do_nand(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VS[i] & VT[i]);
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    return;
}

static void VNAND_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_nand(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VNAND0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 02);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 03);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 04);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 05);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 06);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 07);
    STORE_VECTOR(SV, VT);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0x8 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0x9 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xA & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xB & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xC & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xD & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xE & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNAND7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = ~(VR[vs][i] & VR[vt][(0xF & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

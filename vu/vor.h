#include "vu.h"

INLINE void do_or(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        ACC_L(i) = VS[i] | VT[i];
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    return;
}

static void VOR_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_or(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VOR0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 02);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 03);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 04);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 05);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 06);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 07);
    STORE_VECTOR(SV, VT);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0x8 & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0x9 & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xA & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xB & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xC & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xD & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xE & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VOR7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i] | VR[vt][(0xF & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

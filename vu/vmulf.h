#include "vu.h"

INLINE void do_mulf(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = (VS[i]*VT[i]) << 1;
    for (i = 0; i < N; i++)
        acc[i] = acc[i] + 0x8000;
    for (i = 0; i < N; i++)
        ACC_H(i) = -(acc[i] < 0);
    for (i = 0; i < N; i++)
        ACC_M(i) = acc[i] >> 16;
    for (i = 0; i < N; i++)
        ACC_L(i) = acc[i];
    for (i = 0; i < N; i++)
        VD[i] = ACC_M(i);
    for (i = 0; i < N; i++)
        VD[i] = VD[i] - !!(VD[i] & 0x8000); /* only possible product to clamp */
    return;
}

static void VMULF_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mulf(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMULF0q(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x2 & 0x1) + (i & 0xE)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1q(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x3 & 0x1) + (i & 0xE)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF0h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x4 & 0x3) + (i & 0xC)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x5 & 0x3) + (i & 0xC)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF2h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x6 & 0x3) + (i & 0xC)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF3h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x7 & 0x3) + (i & 0xC)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF0w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x8 & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x9 & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF2w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xA & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF3w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xB & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF4w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xC & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF5w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xD & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF6w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xE & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF7w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xF & 0x7) + (i & 0x0)];
    do_mulf(VR[vd], VR[vs], SV);
    return;
}

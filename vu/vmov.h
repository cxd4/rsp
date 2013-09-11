#include "vu.h"

static void VMOV(int vd, int de, int vt, int e)
{
    register int i;

    /* MovIn = (int)VR[vt][e & 07]; */
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR_T(i);
    VR_D(de &= 07) = VACC[de].s[LO];
    return;
}

static void VMOVv0(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x0 & 0x0) + (i & 0x7)];
    VR[vd][de] = VACC[00].s[LO];
    return;
}
static void VMOVv1(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x1 & 0x0) + (i & 0x7)];
    VR[vd][de] = VACC[01].s[LO];
    return;
}
static void VMOV0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x2 & 0x1) + (i & 0xE)];
    VR[vd][de] = VACC[02].s[LO];
    return;
}
static void VMOV1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x3 & 0x1) + (i & 0xE)];
    VR[vd][de] = VACC[03].s[LO];
    return;
}
static void VMOV0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x4 & 0x3) + (i & 0xC)];
    VR[vd][de] = VACC[04].s[LO];
    return;
}
static void VMOV1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x5 & 0x3) + (i & 0xC)];
    VR[vd][de] = VACC[05].s[LO];
    return;
}
static void VMOV2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x6 & 0x3) + (i & 0xC)];
    VR[vd][de] = VACC[06].s[LO];
    return;
}
static void VMOV3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x7 & 0x3) + (i & 0xC)];
    VR[vd][de] = VACC[07].s[LO];
    return;
}
static void VMOV0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x8 & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[00].s[LO];
    return;
}
static void VMOV1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x9 & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[01].s[LO];
    return;
}
static void VMOV2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xA & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[02].s[LO];
    return;
}
static void VMOV3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xB & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[03].s[LO];
    return;
}
static void VMOV4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xC & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[04].s[LO];
    return;
}
static void VMOV5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xD & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[05].s[LO];
    return;
}
static void VMOV6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xE & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[06].s[LO];
    return;
}
static void VMOV7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xF & 0x7) + (i & 0x0)];
    VR[vd][de] = VACC[07].s[LO];
    return;
}

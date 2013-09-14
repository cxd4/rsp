#include "vu.h"

void do_lt(int vs)
{
    int lt[8];
    int vce[8]; /* !(NOTEQUAL) */
    int vcc[8]; /* !(CARRY) */
    register int i;

    for (i = 0; i < N; i++)
        vcc[i] = (VCO >> (i+0x0)) & 1;
    for (i = 0; i < N; i++)
        vce[i] = (VCO >> (i+0x8)) & 1;
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        lt[i] = vce[i] & vcc[i]; /* le = (VS < VT) || (VS == VT && vcc&vce) */
    for (i = 0; i < N; i++)
        lt[i] = lt[i] & (VR[vs][i] == VC[i]); /* equal to */
    for (i = 0; i < N; i++)
        lt[i] = lt[i] | (VR[vs][i] <  VC[i]); /* less than */
    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = lt[i];
    for (i = 0; i < N; i++)
        ACC_L(i) = lt[i] ? VR[vs][i] : VC[i];
    return;
}

static void VLT_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][i];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VLT7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_lt(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

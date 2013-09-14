#include "vu.h"

void do_eq(int vs)
{
    int eq[8];
    register int i;

    VCO = ~VCO;
    for (i = 0; i < N; i++)
        eq[i]  = (VCO >> (i+0x8)) & 1;
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        eq[i] &= (VR[vs][i] == VC[i]);
    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = eq[i];
#if (0)
    for (i = 0; i < N; i++)
        ACC_L(i) = eq[i] ? VR[vs][i] : VC[i]; /* correct but redundant */
#else
    for (i = 0; i < N; i++)
        ACC_L(i) = VC[i];
#endif
    return;
}

static void VEQ_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][i];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VEQ7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_eq(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

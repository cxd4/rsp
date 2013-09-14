#include "vu.h"

void do_ne(int vs)
{
    int ne[8];
    register int i;

    for (i = 0; i < N; i++)
        ne[i]  = (VCO >> (i+0x8)) & 1;
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        ne[i] |= (VR[vs][i] != VC[i]);
    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = ne[i];
#if (0)
    for (i = 0; i < N; i++)
        ACC_L(i) = ne[i] ? VR[vs][i] : VC[i]; /* correct but redundant */
#else
    for (i = 0; i < N; i++)
        ACC_L(i) = VR[vs][i];
#endif
    return;
}

static void VNE_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][i];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VNE7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_ne(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

#include "vu.h"

static void VMRG_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][i];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x2 & 01) + (i & 0xE)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x3 & 01) + (i & 0xE)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x4 & 03) + (i & 0xC)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x5 & 03) + (i & 0xC)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x6 & 03) + (i & 0xC)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x7 & 03) + (i & 0xC)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x8 & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0x9 & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xA & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xB & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xC & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xD & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xE & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}
static void VMRG7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VR[vs][i] : VR[vt][(0xF & 07) + (i & 0x0)];
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    return;
}

#include "vu.h"

static void VNXOR(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < N; i++)
        ACC_R(i) = ~(VR[vs][i] ^ VR_T(i));
    for (i = 0; i < N; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

static void VNXOR_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x2 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x3 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x4 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x5 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x6 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x7 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x8 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0x9 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xA & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xB & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xC & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xD & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xE & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VNXOR7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ~(VR[vs][i] ^ VR[vt][(0xF & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}

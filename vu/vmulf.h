#include "vu.h"

static void VMULF(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC[i].DW = (VR[vs][i]*VR_T(i) << 1) + 0x8000;
    for (i = 0; i < N; i++)
        VR_D(i) = VACC[i].s[MD];
    for (i = 0; i < N; i++) /* Only one reachable value can expose overflow. */
        VR_D(i) -= !!(VR_D(i) & 0x8000);
    return;
}

static void VMULF_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][i] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x2 & 01) + (i & 0xE)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x3 & 01) + (i & 0xE)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x4 & 03) + (i & 0xC)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x5 & 03) + (i & 0xC)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x6 & 03) + (i & 0xC)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x7 & 03) + (i & 0xC)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x8 & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0x9 & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xA & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xB & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xC & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xD & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xE & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}
static void VMULF7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW = 2*VR[vs][i]*VR[vt][(0xF & 07) + (i & 0x0)] + 0x8000;
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[MD];
    for (i = 0; i < N; i++)
        VR[vd][i] -= !!(VR[vd][i] & 0x8000);
    return;
}

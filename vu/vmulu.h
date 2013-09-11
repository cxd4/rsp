#include "vu.h"

static void VMULU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC[i].DW = (VR[vs][i]*VR_T(i) << 1) + 0x8000;
    for (i = 0; i < N; i++) /* Zero-clamp bits 31..16 of ACC to dest. VR. */
    {
        VR_D(i)  = VACC[i].s[MD];   /* VD  = ACC[31..16] */
        VR_D(i) |= VR_D(i) >> 15;   /* VD |= -(result == 0x80008000) */
        VR_D(i) &= ~VACC[i].HW[03]; /* VD  = (ACC < 0) ? 0 : ACC[31..16]; */
    }
    return;
}

static void VMULU_v(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU0q(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU1q(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU0h(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU1h(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU2h(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU3h(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU0w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU1w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU2w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU3w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU4w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU5w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU6w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}
static void VMULU7w(void)
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
        VR[vd][i] |= VACC[i].s[MD] >> 15;
    for (i = 0; i < N; i++)
        VR[vd][i] &= VACC[i].s[HI] >> 15;
    return;
}

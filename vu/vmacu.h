#include "vu.h"

void UNSIGNED_CLAMP(int vd)
{
    register int i;

    for (i = 0; i < N; i++) /* Zero-clamp bits 31..16 of ACC to dest. VR. */
    {
        register signed short result;
        register short int tmp;

        result  = VACC[i].s[MD]; /* raw slice before clamping */
        tmp = (signed short)(VACC[i].DW >> 31) != 0x0000;
        result |= -tmp; /* slice overflow */
        tmp = VACC[i].s[HI] >> 15; /* Zero- or one-extend. */
        result &= ~tmp; /* slice underflow */
        VR[vd][i] = result;
    }
}

static void VMACU(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC[i].DW += VR[vs][i]*VR_T(i) << 1;
    UNSIGNED_CLAMP(vd);
    return;
}

static void VMACU_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][i];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x2 & 01) + (i & 0xE)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x3 & 01) + (i & 0xE)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x4 & 03) + (i & 0xC)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x5 & 03) + (i & 0xC)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x6 & 03) + (i & 0xC)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x7 & 03) + (i & 0xC)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x8 & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0x9 & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xA & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xB & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xC & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xD & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xE & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}
static void VMACU7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VACC[i].DW += 2*VR[vs][i]*VR[vt][(0xF & 07) + (i & 0x0)];
    UNSIGNED_CLAMP(vd);
    return;
}

#include "vu.h"

static void VSUB(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < N; i++) /* Try to vectorize the subtracts to be parallel. */
        result[i] = VR[vs][i] - VR_T(i);
    for (i = 0; i < N; i++)
    {
        result[i] -= VCO & 0x0001;
        VCO >>= 1;
    }
    VCO = 0x0000; /* Clear the remaining, upper NOTEQUAL bits. */
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)result[i];
    SIGNED_CLAMP(VMUL_PTR, SM_ADD_A);
    return;
}

void clr_bi(void) /* clear CARRY and borrow in to accumulators */
{
    int bi[8];
    register int i;

    for (i = 0; i < N; i++)
        bi[i] = !!(VCO & 0x01<<i); /* (VCO >> i) & 1 */
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        result[i] -= bi[i];
    return;
}
static void VSUB_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][i];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x2 & 01) + (i & 0xE)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x3 & 01) + (i & 0xE)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x4 & 03) + (i & 0xC)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x5 & 03) + (i & 0xC)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x6 & 03) + (i & 0xC)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x7 & 03) + (i & 0xC)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x8 & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0x9 & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xA & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xB & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xC & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xD & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xE & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}
static void VSUB7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vs][i] - VR[vt][(0xF & 07) + (i & 0x0)];
    clr_bi();
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    SIGNED_CLAMP(VR[vd], SM_ADD_A);
    return;
}

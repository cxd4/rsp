#include "vu.h"

INLINE static void clr_ci(short* VD, short* VS, short* VT)
{ /* clear CARRY and carry in to accumulators */
    register int i;

    for (i = 0; i < N; i++)
        result[i] = VS[i] + VT[i];
    for (i = 0; i < N; i++)
        result[i] += co[i];
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    SIGNED_CLAMP(VD, SM_ADD_A);
    return;
}

static void VADD(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    clr_ci(VR[vd], VR[vs], ST);
    return;
}

static void VADD_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    clr_ci(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VADD0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}

#include "vu.h"

void clr_ci(short* VD, short* VS, short* VT)
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
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}
static void VADD7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    clr_ci(VR[vd], VR[vs], SV);
    return;
}

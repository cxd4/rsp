#include "vu.h"

INLINE void do_nor(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = ~(VS[i] | VT[i]);
    for (i = 0; i < N; i++)
        VD[i] = VACC_L[i];
    return;
}

static void VNOR(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_nor(VR[vd], VR[vs], ST);
    return;
}

static void VNOR_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_nor(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VNOR0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_nor(VR[vd], VR[vs], SV);
    return;
}
static void VNOR7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_nor(VR[vd], VR[vs], SV);
    return;
}

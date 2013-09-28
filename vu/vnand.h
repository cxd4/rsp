#include "vu.h"

INLINE void do_nand(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = ~(VS[i] & VT[i]);
    vector_copy(VD, VACC_L);
    return;
}

static void VNAND(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_nand(VR[vd], VR[vs], ST);
    return;
}

static void VNAND_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_nand(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VNAND0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_nand(VR[vd], VR[vs], SV);
    return;
}
static void VNAND7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_nand(VR[vd], VR[vs], SV);
    return;
}

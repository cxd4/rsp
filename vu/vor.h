#include "vu.h"

INLINE void do_or(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VS[i] | VT[i];
    vector_copy(VD, VACC_L);
    return;
}

static void VOR(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_or(VR[vd], VR[vs], ST);
    return;
}

static void VOR_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_or(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VOR0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_or(VR[vd], VR[vs], SV);
    return;
}
static void VOR7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_or(VR[vd], VR[vs], SV);
    return;
}

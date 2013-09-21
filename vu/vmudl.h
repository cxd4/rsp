#include "vu.h"

INLINE static void do_mudl(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = (unsigned short)(VS[i]) * (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = acc[i] >> 16;
    for (i = 0; i < N; i++)
        ACC_M(i) = 0x0000;
    for (i = 0; i < N; i++)
        ACC_H(i) = 0x0000;
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i); /* no possibilities to clamp */
    return;
}

static void VMUDL(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mudl(VR[vd], VR[vs], ST);
    return;
}

static void VMUDL_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mudl(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMUDL0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}

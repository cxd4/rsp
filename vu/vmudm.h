#include "vu.h"

INLINE void do_mudm(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = (signed short)(VS[i]) * (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (acc[i] & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        ACC_M(i) = (acc[i] & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        ACC_H(i) = -(ACC_M(i) < 0);
    for (i = 0; i < N; i++)
        VD[i] = ACC_M(i); /* no possibilities to clamp */
    return;
}

static void VMUDM_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mudm(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMUDM0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}
static void VMUDM7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_mudm(VR[vd], VR[vs], SV);
    return;
}

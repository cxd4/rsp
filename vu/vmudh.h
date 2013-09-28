#include "vu.h"

INLINE static void do_mudh(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = 0x0000;
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(VS[i]*VT[i] >>  0);
    for (i = 0; i < N; i++)
        VACC_H[i] = (short)(VS[i]*VT[i] >> 16);
    SIGNED_CLAMP_AM(VD);
    return;
}

static void VMUDH(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mudh(VR[vd], VR[vs], ST);
    return;
}

static void VMUDH_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mudh(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMUDH0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}
static void VMUDH7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_mudh(VR[vd], VR[vs], SV);
    return;
}

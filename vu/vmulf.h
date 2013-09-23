#include "vu.h"

INLINE static void do_mulf(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = VS[i] * VT[i];
    for (i = 0; i < N; i++)
        VACC_H[i] = -(acc[i] < 0);
    for (i = 0; i < N; i++)
        acc[i] = (acc[i] << 1) + 0x8000;
    for (i = 0; i < N; i++)
        VACC_L[i] = (acc[i] & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        VACC_M[i] = (acc[i] & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        VD[i] = VACC_M[i];
    for (i = 0; i < N; i++)
        VD[i] = VD[i] - (VACC_M[i] < 0); /* only possible product to clamp */
    return;
}

static void VMULF(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mulf(VR[vd], VR[vs], ST);
    return;
}

static void VMULF_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mulf(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMULF0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}
static void VMULF7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_mulf(VR[vd], VR[vs], SV);
    return;
}

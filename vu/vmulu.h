#include "vu.h"

INLINE static void do_mulu(short* VD, short* VS, short* VT)
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
        VD[i]  =  (VACC_M[i]);
    for (i = 0; i < N; i++)
        VD[i] |=  (VACC_M[i] >> 15); /* VD |= -(result == 0x000080008000) */
    for (i = 0; i < N; i++)
        VD[i] &= ~(VACC_H[i] ^ 0); /* VD &= -(result >= 0x000000000000) */
    return;
}

static void VMULU(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_mulu(VR[vd], VR[vs], ST);
    return;
}

static void VMULU_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mulu(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMULU0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}
static void VMULU7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_mulu(VR[vd], VR[vs], SV);
    return;
}

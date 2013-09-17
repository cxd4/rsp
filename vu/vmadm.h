#include "vu.h"

INLINE void do_madm(short* VD, short* VS, short* VT)
{
    long product[N];
    unsigned long addend[N];
    register int i;

    for (i = 0; i < N; i++)
        product[i] = (signed short)(VS[i]) * (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        addend[i] = (product[i] & 0x00000000FFFF) >>  0;
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)ACC_L(i) + addend[i];
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)addend[i];
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(addend[i] >> 16) + (product[i] >> 16);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)ACC_M(i) + addend[i];
    for (i = 0; i < N; i++)
        ACC_M(i) = (short)addend[i];
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(addend[i] >> 16);
    for (i = 0; i < N; i++)
        ACC_H(i) = ACC_H(i) + (short)addend[i];
    SIGNED_CLAMP(VD, SM_MUL_X);
    return;
}

static void VMADM_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_madm(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMADM0q(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x2 & 0x1) + (i & 0xE)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM1q(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x3 & 0x1) + (i & 0xE)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM0h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x4 & 0x3) + (i & 0xC)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM1h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x5 & 0x3) + (i & 0xC)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM2h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x6 & 0x3) + (i & 0xC)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM3h(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x7 & 0x3) + (i & 0xC)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM0w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x8 & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM1w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0x9 & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM2w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xA & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM3w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xB & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM4w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xC & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM5w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xD & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM6w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xE & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}
static void VMADM7w(void)
{
    short SV[N];
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        SV[i] = VR[vt][(0xF & 0x7) + (i & 0x0)];
    do_madm(VR[vd], VR[vs], SV);
    return;
}

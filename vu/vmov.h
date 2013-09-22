#include "vu.h"

static void VMOV(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = ST[i];
    VR[vd][de] = VACC_L[inst.R.rs & 07];
    return;
}

static void VMOVv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VR[vt][i];
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOVv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VR[vt][i];
    VR[vd][de] = ACC_L(01);
    return;
}
static void VMOV0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(07);
    return;
}
static void VMOV0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOV1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(01);
    return;
}
static void VMOV2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = ACC_L(07);
    return;
}

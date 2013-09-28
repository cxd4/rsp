#include "vu.h"

static void VMOV(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;

    vector_copy(VACC_L, ST);
    VR[vd][de] = VACC_L[inst.R.rs & 07];
    return;
}

static void VMOVv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOVv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = ACC_L(01);
    return;
}
static void VMOV0q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x2);
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV1q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x3);
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV0h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x4);
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV1h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x5);
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV2h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x6);
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV3h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x7);
    VR[vd][de] = ACC_L(07);
    return;
}
static void VMOV0w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x8);
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOV1w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x9);
    VR[vd][de] = ACC_L(01);
    return;
}
static void VMOV2w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xA);
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV3w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xB);
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV4w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xC);
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV5w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xD);
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV6w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xE);
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV7w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xF);
    VR[vd][de] = ACC_L(07);
    return;
}

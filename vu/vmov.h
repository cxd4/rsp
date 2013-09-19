#include "vu.h"

static void VMOVv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    memcpy(VACC_L, VR[vt], 8*sizeof(short));
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOVv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    memcpy(VACC_L, VR[vt], 8*sizeof(short));
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOV0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(07);
    return;
}
static void VMOV0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(00);
    return;
}
static void VMOV1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(01);
    return;
}
static void VMOV2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(02);
    return;
}
static void VMOV3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(03);
    return;
}
static void VMOV4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(04);
    return;
}
static void VMOV5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(05);
    return;
}
static void VMOV6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(06);
    return;
}
static void VMOV7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = ACC_L(07);
    return;
}

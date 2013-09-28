#include "vu.h"
#include "divrom.h"

static void VRSQH(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][inst.R.rs & 07] << 16;
    vector_copy(VACC_L, ST);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

static void VRSQHv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][00] << 16;
    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQHv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][01] << 16;
    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH0q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x2);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH1q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x3);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH0h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x4);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH1h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x5);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH2h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x6);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH3h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x7);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH0w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][00] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x8);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH1w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][01] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x9);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH2w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xA);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH3w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xB);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH4w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xC);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH5w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xD);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH6w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xE);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRSQH7w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xF);
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

#include "vu.h"
#include "divrom.h"

static void VRCPHv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][00] << 16;
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPHv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][01] << 16;
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][00] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][01] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

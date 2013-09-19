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
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][00] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][01] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][02] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][03] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][04] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][05] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][06] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPH7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = VR[vt][07] << 16;
    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

#include "vu.h"
#include "divrom.h"

static void VRCPH(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    DivIn = VR[vt][inst.R.rs & 07] << 16;
    for (i = 0; i < N; i++)
        VACC_L[i] = ST[i];
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

static void VRCPHv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    DivIn = VR[vt][00] << 16;
    for (i = 0; i < N; i++)
        VACC_L[i] = VR[vt][i];
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}
static void VRCPHv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;
    register int i;

    DivIn = VR[vt][01] << 16;
    for (i = 0; i < N; i++)
        VACC_L[i] = VR[vt][i];
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
    register int i;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][00] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][01] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][02] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][03] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][04] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][05] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][06] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
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
    register int i;

    DivIn = VR[vt][07] << 16;
    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    for (i = 0; i < N; i++)
        VACC_L[i] = SV[i];
    VR[vd][de] = DivOut >> 16;
    DPH = 1;
    return;
}

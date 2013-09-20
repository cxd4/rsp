#include "vu.h"
#include "divrom.h"

void do_rcp(int data)
{
    unsigned int addr;
    int fetch;
    int shift = 32;

    DPH = 0;
    if (data < 0)
        data = -data;
    do
    {
        --shift;
        if (data & (1 << shift))
            goto FOUND_MSB;
    } while (shift); /* while (shift > 0) or ((shift ^ 31) < 32) */
    shift = 16 ^ 31; /* No bits found in (data == 0x00000000), so shift = 16. */
FOUND_MSB:
    shift ^= 31; /* Right-to-left shift direction conversion. */
    addr = (data << shift) >> 22;
    fetch = div_ROM[addr &= 0x000001FF];
    shift ^= 31; /* Flipped shift direction back to right-. */
    DivOut = (0x40000000 | (fetch << 14)) >> shift;
    if (DivIn < 0)
        DivOut = ~DivOut;
    else if (DivIn == 0) /* corner case:  overflow via division by zero */
        DivOut = 0x7FFFFFFF;
    else if (DivIn == -32768) /* corner case:  signed underflow barrier */
        DivOut = 0xFFFF0000;
    return;
}

static void VRCPv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][00];
    do_rcp(DivIn);
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][01];
    do_rcp(DivIn);
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][02];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][03];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][04];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][05];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][06];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][07];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][00];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][01];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][02];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][03];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][04];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][05];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][06];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][07];
    do_rcp(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}

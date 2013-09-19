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
    memcpy(VACC_L, VR[vt], 8*sizeof(short));
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
    memcpy(VACC_L, VR[vt], 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][02];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][03];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][04];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][05];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][06];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][07];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][00];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][01];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][02];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][03];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][04];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][05];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][06];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCP7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn = (int)VR[vt][07];
    do_rcp(DivIn);
    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    memcpy(VACC_L, SV, 8*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}

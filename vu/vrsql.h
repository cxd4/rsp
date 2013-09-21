#include "vu.h"
#include "divrom.h"

INLINE static void do_rsql(int data)
{
    unsigned int addr;
    int fetch;
    int shift = 32;

    if (data < 0)
        data = -data - (data < -32768); /* -(x) if >=; ~(x) if < */
    do
    {
        --shift;
        if (data & (1 << shift))
            goto FOUND_MSB;
    } while (shift); /* while (shift > 0) or ((shift ^ 31) < 32) */
    shift = 31 - 16*DPH; /* if (data == 0) shift = DPH ? 16 ^ 31 : 0 ^ 31; */
FOUND_MSB:
    DPH = 0;
    shift ^= 31; /* Right-to-left shift direction conversion. */
    addr = (data << shift) >> 22;
    addr &= 0x000001FE;
    addr |= 0x00000200 | (shift & 1);
    fetch = div_ROM[addr];
    shift ^= 31; /* Flipped shift direction back to right-. */
    shift >>= 1;
    DivOut = (0x40000000 | (fetch << 14)) >> shift;
    if (DivIn < 0)
        DivOut = ~DivOut;
    else if (DivIn == 0) /* corner case:  overflow via division by zero */
        DivOut = 0x7FFFFFFF;
    else if (DivIn == -32768) /* corner case:  signed underflow barrier */
        DivOut = 0xFFFF0000;
    return;
}

static void VRSQL(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][inst.R.rs & 07];
    do_rsql(DivIn);
    memcpy(VACC_L, ST, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}

static void VRSQLv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rsql(DivIn);
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQLv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rsql(DivIn);
    memcpy(VACC_L, VR[vt], N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRSQL7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rsql(DivIn);
    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    memcpy(VACC_L, SV, N*sizeof(short));
    VR[vd][de] = (short)DivOut;
    return;
}

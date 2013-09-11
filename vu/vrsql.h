#include "vu.h"
#include "divrom.h"

static void VRSQL(int vd, int de, int vt, int e)
{
    unsigned int addr;
    int data;
    int fetch;
    int shift = 32;

    if (DPH)
        DivIn |= (unsigned short)VR[vt][e & 07];
    else
        DivIn  = VR[vt][e & 07] & 0x0000FFFF; /* Do not sign-extend. */
    data = DivIn;
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
    for (addr = 0; addr < N; addr++)
        VACC[addr].s[LO] = VR_T(addr);
    VR_D(de &= 07) = (short)DivOut;
    DPH = 0;
    return;
}

void do_rsql(int data)
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

static void VRSQLv0(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x0 & 0x0) + (i & 0x7)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQLv1(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x1 & 0x0) + (i & 0x7)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x2 & 0x1) + (i & 0xE)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x3 & 0x1) + (i & 0xE)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x4 & 0x3) + (i & 0xC)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x5 & 0x3) + (i & 0xC)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x6 & 0x3) + (i & 0xC)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x7 & 0x3) + (i & 0xC)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x8 & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0x9 & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xA & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xB & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xC & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xD & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xE & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}
static void VRSQL7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rsql(DivIn);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = VR[vt][(0xF & 0x7) + (i & 0x0)];
    VR[vd][de] = (short)DivOut;
    DPH = 0;
    return;
}

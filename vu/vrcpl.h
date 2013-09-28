#include "vu.h"
#include "divrom.h"

INLINE static void do_rcpl(int data)
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

static void VRCPL(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][inst.R.rs & 07];
    do_rcpl(DivIn);
    vector_copy(VACC_L, ST);
    VR[vd][de] = (short)DivOut;
    return;
}

static void VRCPLv0(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rcpl(DivIn);
    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPLv1(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rcpl(DivIn);
    vector_copy(VACC_L, VR[vt]);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL0q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x2);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL1q(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x3);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL0h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x4);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL1h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x5);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL2h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x6);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL3h(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x7);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL0w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][00];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x8);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL1w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][01];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0x9);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL2w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][02];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xB);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL3w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][03];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xC);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL4w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][04];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xC);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL5w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][05];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xD);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL6w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][06];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xE);
    VR[vd][de] = (short)DivOut;
    return;
}
static void VRCPL7w(void)
{
    const int vd = inst.R.sa;
    const int de = inst.R.rd & 07;
    const int vt = inst.R.rt;

    DivIn &= -DPH;
    DivIn |= (unsigned short)VR[vt][07];
    do_rcpl(DivIn);
    SHUFFLE_VECTOR(VACC_L, VR[vt], 0xF);
    VR[vd][de] = (short)DivOut;
    return;
}

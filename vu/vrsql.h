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
    for (addr = 0; addr < 8; addr++)
        VACC[addr].s[LO] = VR_T(addr);
    VR_D(de &= 07) = (short)DivOut;
    DPH = 0;
    return;
}

#include "vu.h"
#include "divrom.h"

static void VRCP(int vd, int de, int vt, int e)
{
    unsigned int addr;
    int data;
    int fetch;
    int shift = 32;

    DivIn = (int)VR[vt][e & 07];
    data = DivIn;
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
    for (addr = 0; addr < 8; addr++)
        VACC[addr].s[LO] = VR[vt][ei[e][addr]];
    VR[vd][de &= 07] = (short)DivOut;
    DPH = 0;
    return;
}

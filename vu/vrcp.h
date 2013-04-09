#include "vu.h"
#include "divrom.h"

static void VRCP(int vd, int de, int vt, int e)
{
    unsigned int addr;
    int data;
    int fetch;
    int shift;

    DivIn = (int)VR[vt][e & 07];
    data = DivIn;
    if (data < 0)
        data = -data;
    for (shift = 0; shift < 32; shift++)
        if (data & (1 << (shift ^ 31)))
            break;
    if (data == 0)
        shift = 0x10;
    addr = (data << shift) >> 22;
    fetch = div_ROM[addr &= 0x000001FF];
    shift ^= 31; /* For shift &= 31, ^= 31 to flip left- to right-shift. */
    DivOut = (0x40000000 | (fetch << 14)) >> shift;
    if (DivIn < 0)
        DivOut = ~DivOut;
    else if (DivIn == 0) /* corner case:  overflow via division by zero */
        DivOut = 0x7FFFFFFF;
    else if (DivIn == -32768) /* corner case:  signed underflow barrier */
        DivOut = 0xFFFF0000;
    for (shift = 0; shift < 8; shift++)
        VACC[shift].s[LO] = VR[vt][ei[e][shift]];
    VR[vd][de &= 07] = (short)DivOut;
    DPH = 0;
    return;
}

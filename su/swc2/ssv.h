/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Shortword from Vector Unit (SSV)     *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.27                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SSV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 2);

    addr &= 0x00000FFF;
    if ((element & 0x1) != 0x0 || (addr & 0x001) != 0x000)
    {
        message("SSV\nCrossed halfword index barrier.", 0);
        if (element == 0xF)
            message("Yay, get to debug what happens here!", 9999);
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF; /* Obviously, only for f(0xFFF) = 0xFFF + 1. */
        RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 01];
        return;
    }
    addr ^= 0x002; /* halfword endian swap */
    element >>= 01;
    *(short *)(RSP.DMEM + addr) = VR[vt].s[element];
    return;
}

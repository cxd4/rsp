/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Shortword to Vector Unit (LSV)        *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.27                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LSV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 2);

    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    if ((element & 0x1) != 0x0 || (addr & 0x001) != 0x000)
    {
        message("LSV\nCrossed halfword index barrier.", 0);
        if (element == 0xF)
        {
            VR[vt].b[element ^ 01] = RSP.DMEM[addr ^ 03];
            return;
        }
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF; /* Obviously, only for f(0xFFF) = 0xFFF + 1. */
        VR[vt].b[element ^ 01] = RSP.DMEM[addr ^ 03];
        return;
    }
    addr ^= 0x002; /* halfword endian swap */
    element >>= 01;
    VR[vt].s[element] = *(short *)(RSP.DMEM + addr);
    return;
}

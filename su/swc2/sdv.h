/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Doubleword from Vector Unit (SDV)    *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SDV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 8);

    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    if (element & 0x7 || addr & 0x007)
    {
        message("SDV\nCrossed doubleword index barrier.", 0);
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 01];
        return;
    }
    element >>= 01;
    *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 00];
    *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 01];
    *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[element + 02];
    *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[element + 03];
    return;
}

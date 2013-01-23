/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Longword from Vector Unit (SLV)      *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SLV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 4);

    addr &= 0x00000FFF;
    if (element & 0x3 || addr & 0x003)
    { /* Castlevania [LoD] gfx ucode will do this. */
        message("SLV\nCrossed word index barrier.", 0);
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        element &= 0xF;
        addr &= 0x00000FFF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        element &= 0xF;
        addr &= 0x00000FFF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        element &= 0xF;
        addr &= 0x00000FFF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        return;
    }
    element >>= 01;
    *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 00];
    *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 01];
    return;
}

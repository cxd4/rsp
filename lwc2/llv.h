/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Longword to Vector Unit (LLV)         *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LLV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 4);

    addr &= 0x00000FFF;
    if (element & 0x3 || addr & 0x003)
    { /* World Driver Championship gfx ucode will do this in START screen. */
        message("LLV\nCrossed word index barrier.", 0);
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        return;
    }
    element >>= 01;
    VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
    VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
    return;
}

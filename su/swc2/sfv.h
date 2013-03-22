/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Fourths from Vector Unit   *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SFV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    addr &= 0x00000FF3;
    addr ^= 0x003; /* byte endian swap */
    switch (element)
    {
        case 0x0:
            RSP.DMEM[addr + 0x0] = (unsigned char)(VR[vt][00] >> 7);
            RSP.DMEM[addr + 0x4] = (unsigned char)(VR[vt][01] >> 7);
            RSP.DMEM[addr + 0x8] = (unsigned char)(VR[vt][02] >> 7);
            RSP.DMEM[addr + 0xC] = (unsigned char)(VR[vt][03] >> 7);
            return;
        case 0x8:
            RSP.DMEM[addr + 0x0] = (unsigned char)(VR[vt][04] >> 7);
            RSP.DMEM[addr + 0x4] = (unsigned char)(VR[vt][05] >> 7);
            RSP.DMEM[addr + 0x8] = (unsigned char)(VR[vt][06] >> 7);
            RSP.DMEM[addr + 0xC] = (unsigned char)(VR[vt][07] >> 7);
            return;
        default:
            message("SFV\nIllegal element.", 3);
            return;
    }
}

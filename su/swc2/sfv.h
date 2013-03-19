/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Fourths from Vector Unit   *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SFV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
    /* register int b = addr 0x003; */

    addr &= 0x00000FF3;
    addr ^= 0x003; /* byte endian swap */
    switch (element)
    {
        case 0x0:
            RSP.DMEM[addr + 0x0] = (unsigned char)(VR[vt].s[00] >> 7);
            RSP.DMEM[addr + 0x4] = (unsigned char)(VR[vt].s[01] >> 7);
            RSP.DMEM[addr + 0x8] = (unsigned char)(VR[vt].s[02] >> 7);
            RSP.DMEM[addr + 0xC] = (unsigned char)(VR[vt].s[03] >> 7);
            return;
        case 0x8:
            RSP.DMEM[addr + 0x0] = (unsigned char)(VR[vt].s[04] >> 7);
            RSP.DMEM[addr + 0x4] = (unsigned char)(VR[vt].s[05] >> 7);
            RSP.DMEM[addr + 0x8] = (unsigned char)(VR[vt].s[06] >> 7);
            RSP.DMEM[addr + 0xC] = (unsigned char)(VR[vt].s[07] >> 7);
            return;
        default:
            message("SFV\nWeird element.", 3);
            return; // Ville Linde:  "FIXME: only works for index 0 and index 8"
    }
}

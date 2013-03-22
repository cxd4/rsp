/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Bytes from Vector Unit     *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SHV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 0x0000000F)
    {
        case 0x0:
            RSP.DMEM[addr + (0x00F ^ 02)] = (unsigned char)(VR[vt][07] >> 7);
            RSP.DMEM[addr + (0x00D ^ 02)] = (unsigned char)(VR[vt][06] >> 7);
            RSP.DMEM[addr + (0x00B ^ 02)] = (unsigned char)(VR[vt][05] >> 7);
            RSP.DMEM[addr + (0x009 ^ 02)] = (unsigned char)(VR[vt][04] >> 7);
            RSP.DMEM[addr + (0x007 ^ 02)] = (unsigned char)(VR[vt][03] >> 7);
            RSP.DMEM[addr + (0x005 ^ 02)] = (unsigned char)(VR[vt][02] >> 7);
            RSP.DMEM[addr + (0x003 ^ 02)] = (unsigned char)(VR[vt][01] >> 7);
            RSP.DMEM[addr + (0x001 ^ 02)] = (unsigned char)(VR[vt][00] >> 7);
            return;
        case 0x1:
            --addr;
            RSP.DMEM[addr + (0x00E ^ 02)] = (unsigned char)(VR[vt][07] >> 7);
            RSP.DMEM[addr + (0x00C ^ 02)] = (unsigned char)(VR[vt][06] >> 7);
            RSP.DMEM[addr + (0x00A ^ 02)] = (unsigned char)(VR[vt][05] >> 7);
            RSP.DMEM[addr + (0x008 ^ 02)] = (unsigned char)(VR[vt][04] >> 7);
            RSP.DMEM[addr + (0x006 ^ 02)] = (unsigned char)(VR[vt][03] >> 7);
            RSP.DMEM[addr + (0x004 ^ 02)] = (unsigned char)(VR[vt][02] >> 7);
            RSP.DMEM[addr + (0x002 ^ 02)] = (unsigned char)(VR[vt][01] >> 7);
            RSP.DMEM[addr + (0x000 ^ 02)] = (unsigned char)(VR[vt][00] >> 7);
            return;
        default:
            message("SHV\nIllegal addr.", 3);
            return;
    }
bitch:
    message("SHV\nIllegal element.", 3);
    return;
}

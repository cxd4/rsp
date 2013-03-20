/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Bytes from Vector Unit     *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.25                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SHV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
	
    addr &= 0x00000FFF;
    if (element || addr & 0xE) /* NOT 0xF */
    {
        message("SHV\nWeird addr.", 3);
        return;
    }
    if ((addr & 0x001) == 0x000)
    {
        RSP.DMEM[addr + (0xF ^ 02)] = (unsigned char)(VR[vt][07] >> 7);
        RSP.DMEM[addr + (0xD ^ 02)] = (unsigned char)(VR[vt][06] >> 7);
        RSP.DMEM[addr + (0xB ^ 02)] = (unsigned char)(VR[vt][05] >> 7);
        RSP.DMEM[addr + (0x9 ^ 02)] = (unsigned char)(VR[vt][04] >> 7);
        RSP.DMEM[addr + (0x7 ^ 02)] = (unsigned char)(VR[vt][03] >> 7);
        RSP.DMEM[addr + (0x5 ^ 02)] = (unsigned char)(VR[vt][02] >> 7);
        RSP.DMEM[addr + (0x3 ^ 02)] = (unsigned char)(VR[vt][01] >> 7);
        RSP.DMEM[addr + (0x1 ^ 02)] = (unsigned char)(VR[vt][00] >> 7);
        return;
    }
    else
    {
        --addr; /* For readability, not efficiency (helps balance timing). */
        RSP.DMEM[addr + (0xE ^ 02)] = (unsigned char)(VR[vt][07] >> 7);
        RSP.DMEM[addr + (0xC ^ 02)] = (unsigned char)(VR[vt][06] >> 7);
        RSP.DMEM[addr + (0xA ^ 02)] = (unsigned char)(VR[vt][05] >> 7);
        RSP.DMEM[addr + (0x8 ^ 02)] = (unsigned char)(VR[vt][04] >> 7);
        RSP.DMEM[addr + (0x6 ^ 02)] = (unsigned char)(VR[vt][03] >> 7);
        RSP.DMEM[addr + (0x4 ^ 02)] = (unsigned char)(VR[vt][02] >> 7);
        RSP.DMEM[addr + (0x2 ^ 02)] = (unsigned char)(VR[vt][01] >> 7);
        RSP.DMEM[addr + (0x0 ^ 02)] = (unsigned char)(VR[vt][00] >> 7);
        return;
    }
}

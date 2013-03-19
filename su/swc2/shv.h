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
        register int i;

        message("SHV\nNonzero element / weird addr.", 2);
        for (i = 0; i < 8; i++)
        {
            RSP.DMEM[addr ^ 03] = *(char *)(&(VR[vt]) + (element ^ 01)) << 1;
            ++element;
            element &= 0xF;
            RSP.DMEM[addr ^ 03] = *(char *)(&(VR[vt]) + (element ^ 01)) >> 7;
            ++element;
            element &= 0xF;
            addr += 0x002;
            addr &= 0xFFF;
        }
        return;
    }
    if ((addr & 0x001) == 0x000)
    {
        RSP.DMEM[addr + (0xF ^ 02)] = (unsigned char)(VR[vt].s[07] >> 7);
        RSP.DMEM[addr + (0xD ^ 02)] = (unsigned char)(VR[vt].s[06] >> 7);
        RSP.DMEM[addr + (0xB ^ 02)] = (unsigned char)(VR[vt].s[05] >> 7);
        RSP.DMEM[addr + (0x9 ^ 02)] = (unsigned char)(VR[vt].s[04] >> 7);
        RSP.DMEM[addr + (0x7 ^ 02)] = (unsigned char)(VR[vt].s[03] >> 7);
        RSP.DMEM[addr + (0x5 ^ 02)] = (unsigned char)(VR[vt].s[02] >> 7);
        RSP.DMEM[addr + (0x3 ^ 02)] = (unsigned char)(VR[vt].s[01] >> 7);
        RSP.DMEM[addr + (0x1 ^ 02)] = (unsigned char)(VR[vt].s[00] >> 7);
        return;
    }
    else
    {
        --addr; /* For readability, not efficiency (helps balance timing). */
        RSP.DMEM[addr + (0xE ^ 02)] = (unsigned char)(VR[vt].s[07] >> 7);
        RSP.DMEM[addr + (0xC ^ 02)] = (unsigned char)(VR[vt].s[06] >> 7);
        RSP.DMEM[addr + (0xA ^ 02)] = (unsigned char)(VR[vt].s[05] >> 7);
        RSP.DMEM[addr + (0x8 ^ 02)] = (unsigned char)(VR[vt].s[04] >> 7);
        RSP.DMEM[addr + (0x6 ^ 02)] = (unsigned char)(VR[vt].s[03] >> 7);
        RSP.DMEM[addr + (0x4 ^ 02)] = (unsigned char)(VR[vt].s[02] >> 7);
        RSP.DMEM[addr + (0x2 ^ 02)] = (unsigned char)(VR[vt].s[01] >> 7);
        RSP.DMEM[addr + (0x0 ^ 02)] = (unsigned char)(VR[vt].s[00] >> 7);
        return;
    }
}

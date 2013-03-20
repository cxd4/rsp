/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Alternate Bytes to Vector Unit (LHV)  *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.24                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LHV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);

    addr &= 0x00000FFF;
    if (element || addr & 0xE) /* NOT addr & F; the LO bit is functional-use! */
    {
        message("LHV\nWeird addr.", 3);
        return;
    }
    if ((addr & 0x001) == 0x000)
    {
        VR[vt][07] = RSP.DMEM[addr + (0xF ^ 02)] << 7;
        VR[vt][06] = RSP.DMEM[addr + (0xD ^ 02)] << 7;
        VR[vt][05] = RSP.DMEM[addr + (0xB ^ 02)] << 7;
        VR[vt][04] = RSP.DMEM[addr + (0x9 ^ 02)] << 7;
        VR[vt][03] = RSP.DMEM[addr + (0x7 ^ 02)] << 7;
        VR[vt][02] = RSP.DMEM[addr + (0x5 ^ 02)] << 7;
        VR[vt][01] = RSP.DMEM[addr + (0x3 ^ 02)] << 7;
        VR[vt][00] = RSP.DMEM[addr + (0x1 ^ 02)] << 7;
        return;
    }
    else
    {
        --addr; /* For readability, not efficiency (helps balance timing). */
        VR[vt][07] = RSP.DMEM[addr + (0xE ^ 02)] << 7;
        VR[vt][06] = RSP.DMEM[addr + (0xC ^ 02)] << 7;
        VR[vt][05] = RSP.DMEM[addr + (0xA ^ 02)] << 7;
        VR[vt][04] = RSP.DMEM[addr + (0x8 ^ 02)] << 7;
        VR[vt][03] = RSP.DMEM[addr + (0x6 ^ 02)] << 7;
        VR[vt][02] = RSP.DMEM[addr + (0x4 ^ 02)] << 7;
        VR[vt][01] = RSP.DMEM[addr + (0x2 ^ 02)] << 7;
        VR[vt][00] = RSP.DMEM[addr + (0x0 ^ 02)] << 7;
        return;
    }
}

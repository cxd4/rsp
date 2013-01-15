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
        register int i;

        message("LHV\nNonzero element / weird addr.", 0);
        element = -element;
        for (i = 0; i < 8; i++)
        {
            VR[vt].s[i] = RSP.DMEM[((addr + element) & 0xFFF) ^ 03] << 7;
            element += 0x2;
            element &= 0xF;
        }
        return;
    }
    if ((addr & 0x001) == 0x000)
    {
        VR[vt].s[07] = RSP.DMEM[addr + (0xF ^ 02)] << 7;
        VR[vt].s[06] = RSP.DMEM[addr + (0xD ^ 02)] << 7;
        VR[vt].s[05] = RSP.DMEM[addr + (0xB ^ 02)] << 7;
        VR[vt].s[04] = RSP.DMEM[addr + (0x9 ^ 02)] << 7;
        VR[vt].s[03] = RSP.DMEM[addr + (0x7 ^ 02)] << 7;
        VR[vt].s[02] = RSP.DMEM[addr + (0x5 ^ 02)] << 7;
        VR[vt].s[01] = RSP.DMEM[addr + (0x3 ^ 02)] << 7;
        VR[vt].s[00] = RSP.DMEM[addr + (0x1 ^ 02)] << 7;
        return;
    }
    else
    {
        --addr; /* For readability, not efficiency (helps balance timing). */
        VR[vt].s[07] = RSP.DMEM[addr + (0xE ^ 02)] << 7;
        VR[vt].s[06] = RSP.DMEM[addr + (0xC ^ 02)] << 7;
        VR[vt].s[05] = RSP.DMEM[addr + (0xA ^ 02)] << 7;
        VR[vt].s[04] = RSP.DMEM[addr + (0x8 ^ 02)] << 7;
        VR[vt].s[03] = RSP.DMEM[addr + (0x6 ^ 02)] << 7;
        VR[vt].s[02] = RSP.DMEM[addr + (0x4 ^ 02)] << 7;
        VR[vt].s[01] = RSP.DMEM[addr + (0x2 ^ 02)] << 7;
        VR[vt].s[00] = RSP.DMEM[addr + (0x0 ^ 02)] << 7;
        return;
    }
}

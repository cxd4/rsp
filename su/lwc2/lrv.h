/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Rest to Vector Unit (LRV)             *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LRV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
    const unsigned b = addr & 0x0000000F;

    addr &= 0x00000FF0;
    if (element)
    {
        message("LRV\nWeird element.", 3);
        return;
    }
    switch (b)
    {
        case 0xE:
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            return;
        case 0xC:
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        case 0xA:
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            return;
        case 0x8:
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            return;
        case 0x6:
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            return;
        case 0x4:
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            return;
        case 0x2:
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            return;
        case 0x0:  return;
        default:
            message("LRV\nWeird addr.", 3);
            return;
    }
}

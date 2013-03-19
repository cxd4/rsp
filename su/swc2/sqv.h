/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Quadword from Vector Unit (SQV)      *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SQV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset << 4);
    const unsigned b = addr & 0x00000007;

    addr &= 0x00000FFF; /* World Driver Championship:  on load demo intro */
    if (element)
    {
        message("SQV\nWeird element.", 3);
        return;
    }
    switch (b)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt].s[07];
            return;
        case 02:
            addr -= 0x2;
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt].s[06];
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + 0x2) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + 0x0) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + 0x6) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + 0x4) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + 0xA) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + 0x8) = VR[vt].s[05];
            return;
        case 06:
            addr -= 0x2;
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[04];
            return;
        default:
            message("SQV\nWeird addr.", 3);
            return;
    }
}

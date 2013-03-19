/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Quadword to Vector Unit (LQV)         *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LQV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
    const unsigned b = addr & 0x00000007;

    addr &= 0x00000FFF;
    if (element != 0x0)
    { /* to-do:  check RE2 prologue cinnema */
        message("LQV\nWeird element.", 3);
        return;
    }
    switch (b)
    {
        case 00:
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 02:
            addr -= 0x002;
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 04:
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        case 06: /* Very rarely is b != 0, but Mario 64 title intro b == 6. */
            addr -= 0x002;
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        default:
            message("LQV\nUnaligned addr.", 3);
            return;
    }
}

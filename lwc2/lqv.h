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
    if (element || (addr & (0x008)) != 0x000)
    { /* weird gfx ucode tasks in Resident Evil 2, World Driver Championship */
        register int i;
        int end = element;

        message("LQV\nCrossed quadword index barrier.", 0);
        end += 16 - (addr & 0xF);
        end &= (end & 0x10) ? 0x10 : 0x0F;
        for (i = element; i < end; i++)
        {
            VR[vt].b[i ^ 01] = RSP.DMEM[addr ^ 03];
            addr++;
            addr &= 0x00000FFF;
        }
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
        case 01: /* to-do:  odd offsets not optimized, games ever use these? */
            VR[vt].b[0x0 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x1 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x2 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr ^ 03];
            return;
        case 02:
            addr -= 0x2;
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 03:
            VR[vt].b[0x0 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x1 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x2 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr ^ 03];
            return;
        case 04:
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        case 05:
            VR[vt].b[0x0 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x1 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x2 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr ^ 03];
            return;
        case 06: /* Very rarely is b != 0, but Mario 64 title intro b == 6. */
            addr -= 0x2;
            VR[vt].s[00] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        case 07:
            VR[vt].b[0x0 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x1 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x2 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr ^ 03];
            ++addr;
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr ^ 03];
            return;
    }
}

/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Unsigned to Vector Unit        *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LUV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 07)
    {
        case 00:
            VR[vt][07] = RSP.DMEM[addr + (0x007 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x006 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x005 ^ 03)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x004 ^ 03)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            return;
        case 01: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 01)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 01)] << 7;
            VR[vt][02] = RSP.DMEM[addr - 0x001] << 7;
            VR[vt][03] = RSP.DMEM[addr + 0x006] << 7;
            VR[vt][04] = RSP.DMEM[addr + 0x005] << 7;
            VR[vt][05] = RSP.DMEM[addr + 0x004] << 7;
            VR[vt][06] = RSP.DMEM[addr + 0x003] << 7;
            addr += 0x007 + 03; /* byte endian swap adjust */
            addr &= 0x00000FFF;
            VR[vt][07] = RSP.DMEM[addr] << 7;
            return;
        case 02: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr - 0x001] << 7;
            VR[vt][01] = RSP.DMEM[addr - 0x002] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 07)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 07)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x004 ^ 07)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x005 ^ 07)] << 7;
            addr += 0x006 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            VR[vt][06] = RSP.DMEM[addr + 0x001] << 7;
            VR[vt][07] = RSP.DMEM[addr | 0x000] << 7;
            return;
        case 03: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr - (0x000 ^ 03)] << 7;
            VR[vt][01] = RSP.DMEM[addr + 0x004] << 7;
            VR[vt][02] = RSP.DMEM[addr + 0x003] << 7;
            VR[vt][03] = RSP.DMEM[addr + 0x002] << 7;
            VR[vt][04] = RSP.DMEM[addr + 0x001] << 7;
            addr += 0x005 + 01; /* Make sure at least one target is base + 0. */
            addr &= 0x00000FFF;
            VR[vt][05] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][07] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            return;
        case 04: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            addr += 0x004;
            addr &= 0x00000FFF;
            VR[vt][04] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][07] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            return;
        case 05: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr + 0x001] << 7;
            VR[vt][01] = RSP.DMEM[addr | 0x000] << 7;
            VR[vt][02] = RSP.DMEM[addr - 0x001] << 7;
            addr += 0x003;
            addr &= 0x00000FFF;
            VR[vt][03] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            VR[vt][07] = RSP.DMEM[addr + (0x004 ^ 03)] << 7;
            return;
        case 06: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr - 0x001] << 7;
            VR[vt][01] = RSP.DMEM[addr - 0x002] << 7;
            addr += 0x002;
            addr &= 0x00000FFF;
            VR[vt][02] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x004 ^ 03)] << 7;
            VR[vt][07] = RSP.DMEM[addr + (0x005 ^ 03)] << 7;
            return;
        case 07: /* PKMN Puzzle League HVQM decoder */
            VR[vt][00] = RSP.DMEM[addr - (0x000 ^ 03)] << 7;
            addr += 0x001;
            addr &= 0x00000FFF;
            VR[vt][01] = RSP.DMEM[addr + 0x003] << 7;
            VR[vt][02] = RSP.DMEM[addr + 0x002] << 7;
            VR[vt][03] = RSP.DMEM[addr + 0x001] << 7;
            VR[vt][04] = RSP.DMEM[addr + 0x000] << 7;
            VR[vt][05] = RSP.DMEM[addr + 0x007] << 7;
            VR[vt][06] = RSP.DMEM[addr + 0x006] << 7;
            VR[vt][07] = RSP.DMEM[addr + 0x005] << 7;
            return;
    }
bitch:
    message("LUV\nIllegal element.", 3);
    return;
}

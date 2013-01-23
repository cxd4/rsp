/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Rest to Vector Unit (LRV)             *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LRV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
    const unsigned b = addr & 0x0000000F;

    addr &= 0x00000FF0;
    if (element)
    {
        unsigned e = element + 0x10 - b;

        message("LRV\nNonzero element.", 0);
        addr += (unsigned long)RSP.DMEM;
        switch (b)
        {
            case 0xF:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0xE:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0xD:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0xC:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0xB:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0xA:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x9:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x8:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x7:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x6:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x5:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x4:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x3:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x2:  VR[vt].b[e++ ^ 01] = *(unsigned char *)(addr++ ^ 03);
            case 0x1:  VR[vt].b[e   ^ 01] = *(unsigned char *)(addr   ^ 03);
            case 0x0:  return;
        }
        return;
    }
    switch (b)
    {
        case 0xF:
            VR[vt].b[0x1 ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0x2 ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr + (0x5 ^ 03)];
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr + (0x6 ^ 03)];
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr + (0x7 ^ 03)];
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr + (0x8 ^ 03)];
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr + (0x9 ^ 03)];
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0xA ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0xB ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0xC ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0xD ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0xE ^ 03)];
            return;
        case 0xE:
            VR[vt].s[01] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            return;
        case 0xD:
            VR[vt].b[0x3 ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0x4 ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr + (0x5 ^ 03)];
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr + (0x6 ^ 03)];
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr + (0x7 ^ 03)];
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0x8 ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0x9 ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0xA ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0xB ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0xC ^ 03)];
            return;
        case 0xC:
            VR[vt].s[02] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            return;
        case 0xB:
            VR[vt].b[0x5 ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0x6 ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr + (0x5 ^ 03)];
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0x6 ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0x7 ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0x8 ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0x9 ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0xA ^ 03)];
            return;
        case 0xA:
            VR[vt].s[03] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            return;
        case 0x9:
            VR[vt].b[0x7 ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0x8 ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0x5 ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0x6 ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0x7 ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0x8 ^ 03)];
            return;
        case 0x8:
            VR[vt].s[04] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            return;
        case 0x7:
            VR[vt].b[0x9 ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0xA ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0x5 ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0x6 ^ 03)];
            return;
        case 0x6:
            VR[vt].s[05] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            return;
        case 0x5:
            VR[vt].b[0xB ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0xC ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0x3 ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0x4 ^ 03)];
            return;
        case 0x4:
            VR[vt].s[06] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            return;
        case 0x3:
            VR[vt].b[0xD ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
            VR[vt].b[0xE ^ 01] = RSP.DMEM[addr + (0x1 ^ 03)];
            VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0x2 ^ 03)];
            return;
        case 0x2:
            VR[vt].s[07] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            return;
        case 0x1:  VR[vt].b[0xF ^ 01] = RSP.DMEM[addr + (0x0 ^ 03)];
        case 0x0:  return;
    }
}

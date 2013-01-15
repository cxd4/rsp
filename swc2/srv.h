/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Rest from Vector Unit (SRV)          *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SRV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);
    const unsigned b = addr & 0x0000000F;

    addr &= 0x00000FF0;
    if (element)
    {
#define VT_RD(x) VR[vt].b[x++ ^ 01]; x ^= 0xF;
        unsigned e = element;

        message("SRV\nNonzero element.", 0);
        addr += (unsigned long)RSP.DMEM;
        switch (b)
        {
            case 0xF:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0xE:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0xD:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0xC:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0xB:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0xA:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x9:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x8:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x7:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x6:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x5:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x4:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x3:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x2:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x1:  *(unsigned char *)(addr++ ^ 03) = VT_RD(e);
            case 0x0:  return;
        }
        return;
    }
    switch (b)
    {
        case 0xF:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0x1 ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0x2 ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0x3 ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0x4 ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0x5 ^ 01];
            RSP.DMEM[addr + (0x5 ^ 03)] = VR[vt].b[0x6 ^ 01];
            RSP.DMEM[addr + (0x6 ^ 03)] = VR[vt].b[0x7 ^ 01];
            RSP.DMEM[addr + (0x7 ^ 03)] = VR[vt].b[0x8 ^ 01];
            RSP.DMEM[addr + (0x8 ^ 03)] = VR[vt].b[0x9 ^ 01];
            RSP.DMEM[addr + (0x9 ^ 03)] = VR[vt].b[0xA ^ 01];
            RSP.DMEM[addr + (0xA ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0xB ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0xC ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0xD ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0xE ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0xE:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt].s[07];
            return;
        case 0xD:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0x3 ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0x4 ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0x5 ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0x6 ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0x7 ^ 01];
            RSP.DMEM[addr + (0x5 ^ 03)] = VR[vt].b[0x8 ^ 01];
            RSP.DMEM[addr + (0x6 ^ 03)] = VR[vt].b[0x9 ^ 01];
            RSP.DMEM[addr + (0x7 ^ 03)] = VR[vt].b[0xA ^ 01];
            RSP.DMEM[addr + (0x8 ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0x9 ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0xA ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0xB ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0xC ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[07];
            return;
        case 0xB:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0x5 ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0x6 ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0x7 ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0x8 ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0x9 ^ 01];
            RSP.DMEM[addr + (0x5 ^ 03)] = VR[vt].b[0xA ^ 01];
            RSP.DMEM[addr + (0x6 ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0x7 ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0x8 ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0x9 ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0xA ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[07];
            return;
        case 0x9:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0x7 ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0x8 ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0x9 ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0xA ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0x5 ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0x6 ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0x7 ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0x8 ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[07];
            return;
        case 0x7:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0x9 ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0xA ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0x5 ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0x6 ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[05];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[07];
            return;
        case 0x5:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0xB ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0xC ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0x3 ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0x4 ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[06];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[07];
            return;
        case 0x3:
            RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0xD ^ 01];
            RSP.DMEM[addr + (0x1 ^ 03)] = VR[vt].b[0xE ^ 01];
            RSP.DMEM[addr + (0x2 ^ 03)] = VR[vt].b[0xF ^ 01];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[07];
            return;
        case 0x1:  RSP.DMEM[addr + (0x0 ^ 03)] = VR[vt].b[0xF ^ 01];
        case 0x0:  return;
    }
}

/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Quadword from Vector Unit (SQV)      *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SQV(int vt, int element, signed offset, int base)
{
    unsigned long int addr = SR[base] + (offset * 16);
    const unsigned b = addr & 0x00000007;

    addr &= 0x00000FFF; /* World Driver Championship:  on load demo intro */
    if (element || (addr & 0x008) != 0x000)
    {
        register int i;
        int end = element;

        message("SQV\nNonzero element / weird addr.", 0);
        end += 16 - (addr & 0xF);
        for (i = element; i < end; i++)
        {
            RSP.DMEM[addr ^ 03] = VR[vt].b[(i & 0xF) ^ 01];
            ++addr;
            addr &= 0x00000FFF;
        }
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
        case 01: /* to-do:  odd offsets not optimized, games ever use these? */
            addr += (unsigned long)RSP.DMEM;
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x0 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x1 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x2 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x3 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x4 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x5 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x6 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x7 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x8 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x9 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xA ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xB ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xC ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xD ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xE ^ 01];
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
        case 03:
            addr += (unsigned long)RSP.DMEM;
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x0 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x1 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x2 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x3 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x4 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x5 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x6 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x7 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x8 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x9 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xA ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xB ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xC ^ 01];
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + 0x2) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + 0x0) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + 0x6) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + 0x4) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + 0xA) = VR[vt].s[04];
            *(short *)(RSP.DMEM + addr + 0x8) = VR[vt].s[05];
            return;
        case 05:
            addr += (unsigned long)RSP.DMEM;
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x0 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x1 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x2 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x3 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x4 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x5 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x6 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x7 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x8 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x9 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0xA ^ 01];
            return;
        case 06:
            addr -= 0x2;
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[00];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[01];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[02];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt].s[03];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt].s[04];
            return;
        case 07:
            addr += (unsigned long)RSP.DMEM;
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x0 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x1 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x2 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x3 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x4 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x5 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x6 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x7 ^ 01];
            *(unsigned char *)(addr++ ^ 03) = VR[vt].b[0x8 ^ 01];
            return;
    }
}

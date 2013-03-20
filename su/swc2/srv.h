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
        message("SRV\nNonzero element.", 3);
        return;
    }
    switch (b)
    {
        case 0xE:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt][07];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt][07];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt][07];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt][07];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt][07];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt][07];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt][07];
            return;
        case 0x0:  return;
        default:
            message("SRV\nUnaligned addr.", 3);
            return;
    }
}

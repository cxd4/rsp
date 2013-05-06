/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Rest from Vector Unit                *
* Authors:  Iconoclast                                                         *
* Release:  2013.05.06                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SRV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;

    addr  = SR[base] + (offset <<= 4);
    b = addr & 0x0000000F;
    addr &= 0x00000FF0;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (b)
    {
        case 0xE:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x00C)) = VR[vt][07];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][07];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][07];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][07];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][07];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][07];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][07];
            return;
        case 0x0:  return;
        default:
            message("SRV\nOdd addr.", 3);
            return;
    }
bitch:
    message("SRV\nIllegal element.", 3);
    return;
}

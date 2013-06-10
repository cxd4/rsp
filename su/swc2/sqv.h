/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Quadword from Vector Unit            *
* Authors:  Iconoclast                                                         *
* Release:  2013.06.09                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SQV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;

    addr  = SR[base] + (offset <<= 4);
    if (element != 0x0)
        goto ILLEGAL_EL;
    b = addr & 0x0000000F; /* experimental; patent says should & 07 */
    addr &= 0x00000FF0; /* World Driver Championship:  on load demo intro */
    switch (b)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR[vt][00];
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x00C)) = VR[vt][06];
            *(short *)(RSP.DMEM + addr + HES(0x00E)) = VR[vt][07];
            return;
        case 02:
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR[vt][00];
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x00C)) = VR[vt][05];
            *(short *)(RSP.DMEM + addr + HES(0x00E)) = VR[vt][06];
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR[vt][00];
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x00C)) = VR[vt][04];
            *(short *)(RSP.DMEM + addr + HES(0x00E)) = VR[vt][05];
            return;
        case 06:
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR[vt][00];
            *(short *)(RSP.DMEM + addr + HES(0x008)) = VR[vt][01];
            *(short *)(RSP.DMEM + addr + HES(0x00A)) = VR[vt][02];
            *(short *)(RSP.DMEM + addr + HES(0x00C)) = VR[vt][03];
            *(short *)(RSP.DMEM + addr + HES(0x00E)) = VR[vt][04];
            return;
        default:
            message("SQV\nWeird addr.", 3);
            return;
    }
ILLEGAL_EL: /* "Mia Hamm Soccer 64" SP exception override (Ville Linde) */
    b = element + 16 - (addr & 0x00F);
    for (offset = element; offset < b; offset++)
    {
        addr &= 0x00000FFF;
        RSP.DMEM[BES(addr)] = VR_B(vt, offset & 0xF);
        ++addr;
    }
    return;
}

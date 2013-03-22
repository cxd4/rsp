/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Transposed from Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.22                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void STV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    if (addr & 0x0000000F)
        goto bitch; /* Microsoft's branch weighs suck. */
    if (vt & 007)
        goto ass; /* Forced to do it this way. :) Need to be explicit. */
ret_addr:
    addr &= 0x00000FF0;
    switch (element)
    {
        case 0x0:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+0][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+1][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+2][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+3][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+4][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+5][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+6][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+7][07];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+1][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+2][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+3][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+4][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+5][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+6][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+7][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+0][07];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+2][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+3][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+4][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+5][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+6][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+7][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+0][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+1][07];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+3][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+4][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+5][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+6][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+7][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+0][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+1][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+2][07];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+4][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+5][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+6][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+7][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+0][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+1][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+2][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+3][07];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+5][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+6][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+7][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+0][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+1][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+2][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+3][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+4][07];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+6][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+7][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+0][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+1][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+2][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+3][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+4][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+5][07];
            return;
        case 0xE:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt+7][00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt+0][01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt+1][02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt+2][03];
            *(short *)(RSP.DMEM + addr + (0x008 ^ 02)) = VR[vt+3][04];
            *(short *)(RSP.DMEM + addr + (0x00A ^ 02)) = VR[vt+4][05];
            *(short *)(RSP.DMEM + addr + (0x00C ^ 02)) = VR[vt+5][06];
            *(short *)(RSP.DMEM + addr + (0x00E ^ 02)) = VR[vt+6][07];
            return;
        default:
            message("STV\nIllegal element.", 3);
            return;
    }
ass:
    message("STV\nUncertain case!", 2); /* Controversial between zilmar's RE. */
    vt &= 030; /* zilmar's method is almost certainly wrong (a copy-pasta). */
    goto ret_addr; /* This is the way SP simulator implemented + documented. */
bitch:
    message("STV\nIllegal addr.", 3);
    return;
}

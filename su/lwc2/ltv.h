/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Transposed to Vector Unit             *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.22                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* Note about LTV on the Nintendo 64 RCP:
 * This algorithm is not the same as the execution procedure illustrated in
 * SGI's patent on vector register file transactions.  STV however is the
 * same as the patented, documented mode of operation.  With LTV it is almost
 * the exact same except that which is a function of the other--the target
 * vector register as a function of the slice of that register, or vice
 * versa--has been mysteriously inverted.
 *
 * A couple sources show this was an honest mistake with the RCP's design.
 * It may have gone unexploited because if element = 0x0, it does not matter.
 * The RCP bug may be related to why there is no LTWV, but there is a SWV.
 * It may also be related to how vector loads enforce result prebuffers.
 */

void LTV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    if (addr & 0x0000000F)
        goto bitch; /* Microsoft's branch weighs suck. */
    if (vt & 007)
        goto ass; /* Forced to do it this way. :) Need to be explicit. */
    addr &= 0x00000FF0;
    switch (element)
    {
        case 0x0:
            VR[vt+0][00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][03] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][04] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][05] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][06] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][07] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x2:
            VR[vt+0][07] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][00] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][01] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][02] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][03] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][04] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][05] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][06] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x4:
            VR[vt+0][06] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][07] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][00] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][01] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][02] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][03] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][04] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][05] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x6:
            VR[vt+0][05] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][06] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][07] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][00] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][01] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][02] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][03] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][04] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x8:
            VR[vt+0][04] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][05] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][06] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][07] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][00] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][01] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][02] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][03] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xA:
            VR[vt+0][03] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][04] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][05] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][06] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][07] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][00] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][01] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][02] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xC:
            VR[vt+0][02] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][03] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][04] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][05] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][06] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][07] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][00] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][01] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xE:
            VR[vt+0][01] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt+1][02] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt+2][03] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt+3][04] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt+4][05] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt+5][06] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt+6][07] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt+7][00] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        default:
            message("LTV\nIllegal element.", 3);
            return;
    }
ass:
    message("LTV\nUncertain case!", 3); /* zilmar's method is probably right. */
    return; /* For LTV I am not sure; for STV I have an idea. */
bitch:
    message("LTV\nIllegal addr.", 3);
    return;
}

/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Transposed to Vector Unit (LTV)       *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.29                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* Note about LTV on the Nintendo 64 RCP:
 * This algorithm is not the same as the execution procedure illustrated in
 * SGI's patent on vector register file transactions.  STV however is the
 * same as the patented, documented mode of operation.  With LTV it is almost
 * the exact same except that which is a function of the other--the target
 * vector register or the slice of that register, or vice versa--has been
 * mysteriously inverted, probably by request of Nintendo.
 *
 * Also, there is no LTWV "LWV" on the N64 RCP, but there is however a SWV.
 */

void LTV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);

    if (addr & 0x00000000F)
    {
        message("LTV\nCrossed quadword allocation barrier.", 1);
        addr &= 0x00000FF8;
        addr += 0x00000008;
    }
    addr &= 0x00000FF0;
    if (vt & 07)
    {
        message("LTV\nWeird vector target register.", 3);
        // vt &= 030;
        return;
    }
    switch (element)
    {
        case 0x0:
            VR[vt+0][00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][02] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][03] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][04] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][05] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][06] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][07] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0x2:
            VR[vt+0][07] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][00] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][01] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][02] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][03] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][04] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][05] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][06] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0x4:
            VR[vt+0][06] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][07] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][00] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][01] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][02] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][03] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][04] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][05] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0x6:
            VR[vt+0][05] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][06] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][07] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][00] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][01] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][02] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][03] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][04] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0x8:
            VR[vt+0][04] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][05] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][06] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][07] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][00] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][01] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][02] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][03] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0xA:
            VR[vt+0][03] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][04] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][05] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][06] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][07] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][00] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][01] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][02] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0xC:
            VR[vt+0][02] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][03] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][04] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][05] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][06] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][07] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][00] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][01] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        case 0xE:
            VR[vt+0][01] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt+1][02] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt+2][03] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt+3][04] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt+4][05] = *(short *)(RSP.DMEM + addr + (0x8 ^ 02));
            VR[vt+5][06] = *(short *)(RSP.DMEM + addr + (0xA ^ 02));
            VR[vt+6][07] = *(short *)(RSP.DMEM + addr + (0xC ^ 02));
            VR[vt+7][00] = *(short *)(RSP.DMEM + addr + (0xE ^ 02));
            return;
        default:
            message("LTV\nOdd element.", 2); /* MAME RSP warning */
            return;
    }
}

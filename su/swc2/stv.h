/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Transposed from Vector Unit (STV)    *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.29                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void STV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 16);

    if (addr & 0x00000000F)
    {
        message("STV\nCrossed quadword index barrier.", 3);
        // addr &= 0x00000FF8;
        // addr += 0x00000008;
        return;
    }
    addr &= 0x00000FF0;
    if (vt & 07)
    {
        message("STV\nCrossed memory dest DW allocation barrier.", 2);
        vt &= ~07;
    }
    switch (element)
    {
        case 0x0:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+0][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+1][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+2][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+3][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+4][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+5][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+6][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+7][07];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+1][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+2][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+3][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+4][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+5][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+6][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+7][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+0][07];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+2][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+3][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+4][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+5][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+6][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+7][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+0][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+1][07];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+3][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+4][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+5][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+6][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+7][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+0][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+1][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+2][07];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+4][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+5][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+6][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+7][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+0][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+1][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+2][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+3][07];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+5][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+6][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+7][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+0][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+1][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+2][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+3][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+4][07];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+6][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+7][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+0][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+1][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+2][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+3][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+4][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+5][07];
            return;
        case 0xE:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+7][00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+0][01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+1][02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+2][03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+3][04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+4][05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+5][06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+6][07];
            return;
        default: {
            register int e = element/2; /* store only bits 3..1 */
            register int s;

            message("STV\nOdd element.", 1);
            for (s = 0; s < 8; s++)
            {
                int fs = vt | ((s + e) & 07);
/* `vt[s]` is a function of slice `s`:  f(s) = vt(4..3) || [(s+e) mod 8]
 * We already ensured that (vt & 0b111) is false, so we don't need to mask.
 */
                *(short *)(RSP.DMEM + (addr ^ 02)) = VR[fs][s];
                addr += 0x002;
            }
            return;
        }
    }
}

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
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+0].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+1].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+2].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+3].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+4].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+5].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+6].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+7].s[07];
            return;
        case 0x2:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+1].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+2].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+3].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+4].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+5].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+6].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+7].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+0].s[07];
            return;
        case 0x4:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+2].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+3].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+4].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+5].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+6].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+7].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+0].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+1].s[07];
            return;
        case 0x6:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+3].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+4].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+5].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+6].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+7].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+0].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+1].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+2].s[07];
            return;
        case 0x8:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+4].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+5].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+6].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+7].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+0].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+1].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+2].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+3].s[07];
            return;
        case 0xA:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+5].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+6].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+7].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+0].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+1].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+2].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+3].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+4].s[07];
            return;
        case 0xC:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+6].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+7].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+0].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+1].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+2].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+3].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+4].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+5].s[07];
            return;
        case 0xE:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt+7].s[00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt+0].s[01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt+1].s[02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt+2].s[03];
            *(short *)(RSP.DMEM + addr + (0x8 ^ 02)) = VR[vt+3].s[04];
            *(short *)(RSP.DMEM + addr + (0xA ^ 02)) = VR[vt+4].s[05];
            *(short *)(RSP.DMEM + addr + (0xC ^ 02)) = VR[vt+5].s[06];
            *(short *)(RSP.DMEM + addr + (0xE ^ 02)) = VR[vt+6].s[07];
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
                *(short *)(RSP.DMEM + (addr ^ 02)) = VR[fs].s[s];
                addr += 0x002;
            }
            return;
        }
    }
}

/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Quadword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LQV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;

    addr  = SR[base] + (offset << 4);
    addr &= 0x00000FFF;
    b = addr & 0x0000000F;
/* There is a mistake in United States patent no. 5,812,147 by SGI.
 * In multiple other statements, LQV is defined to go all the way to addr|15.
 * This means that if addr&15 is 0, length == 16; addr&15 is 15, length == 1.
 *
 * However, they give an if-else chain for b={0:7} only, which allows a bug
 * exploitable by Resident Evil 2 and, possibly, some Boss Game publications.
 * Conker's Bad Fur Day audio also could have exploited this but covers it.
 */
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (b)
    {
        case 0x0:
            VR[vt][00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt][02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt][03] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt][04] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt][05] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR[vt][06] = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR[vt][07] = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x2:
            VR[vt][00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + 0x004);
            VR[vt][02] = *(short *)(RSP.DMEM + addr + 0x002);
            VR[vt][03] = *(short *)(RSP.DMEM + addr + 0x008);
            VR[vt][04] = *(short *)(RSP.DMEM + addr + 0x006);
            VR[vt][05] = *(short *)(RSP.DMEM + addr + 0x00C);
            VR[vt][06] = *(short *)(RSP.DMEM + addr + 0x00A);
            return;
        case 0x4:
            VR[vt][00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt][02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt][03] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt][04] = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR[vt][05] = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            return;
        case 0x6:
            VR[vt][00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + 0x004);
            VR[vt][02] = *(short *)(RSP.DMEM + addr + 0x002);
            VR[vt][03] = *(short *)(RSP.DMEM + addr + 0x008);
            VR[vt][04] = *(short *)(RSP.DMEM + addr + 0x006);
            return;
        case 0x8: /* Resident Evil 2 cinematics and Boss Game Studios */
            VR[vt][00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt][02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt][03] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            return;
        case 0xA: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR[vt][00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + 0x004);
            VR[vt][02] = *(short *)(RSP.DMEM + addr + 0x002);
            return;
        case 0xC: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR[vt][00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            return;
        case 0xE: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR[vt][00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            return;
        default:
            message("LQV\nOdd addr.", 3);
            return;
    }
bitch:
    message("LQV\nIllegal element.", 3);
    return;
}

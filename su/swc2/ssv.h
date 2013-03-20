/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Shortword from Vector Unit           *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.15                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* To-do:  Even though odd elements aren't exactly legal for SP operations,
 * they must in this case be supported because:
 *     a) The RSP assembler allows the generation of such commands.
 *     b) The RCP features exception overrides for illegal cases.
 *     c) Many N64 applications apply this illegal instruction.
 *
 * The efficient way to update vector registers indexing by ANY element value
 * is to define each vector register in the virtual file as an array of 8
 * 16-bit shortwords, not a dynamic union in C indexing from the right
 * (little endian), so that endian-swapping may be eliminated completely.
 * That is a massive rewrite though and will take time.
 */

void SSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 1);
    addr &= 0x00000FFF;
    if (element & 0x1) /* The element must be aligned, not the address. */
    { /* F3DEX makes use of this typical illegal RCP exception override. */
        element = (unsigned int)(element) >> 1;
        RSP.DMEM[addr ^ 03] = VR[vt][element] & 0x00FF;
        addr += 0x001;
        addr &= 0x00000FFF;
        ++element;
        element &= 07;
        RSP.DMEM[addr ^ 03] = VR[vt][element] >> 8;
        return;
    }
    element = (unsigned int)(element) >> 1;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + (addr + 0x002)) = VR[vt][element];
            return;
        case 01:
            *(short *)(RSP.DMEM + (addr | 0x000)) = VR[vt][element];
            return;
        case 02:
            *(short *)(RSP.DMEM + (addr - 0x002)) = VR[vt][element];
            return;
        case 03:
            RSP.DMEM[addr - 0x003] = (unsigned short)(VR[vt][element]) >> 8;
            RSP.DMEM[(addr + 0x004) & 0xFFF] = VR[vt][element] & 0x00FF;
            return;
    }
}

/* Note about vector registers.
 * RSP vectors are just like standard mathematical vectors, big endian.
 * It is correct to have them as big-endian arrays, with bits in little.
 *
 * I have not yet figured out how to address 128-bit vectors by byte quickly.
 * The legacy of RSP emulation has always used unions to have such
 * constructors predefined, but this inverted the vector indexing endian.
 * There is no necessity for Objective-C or unions to define vectors.
 *
 * lbv, ldv, sbv, ssv, sdv, spv, and `cop2::mfc2` all require byte-indexing
 * for the demands of the standard F3DEX graphics microcodes.
 */

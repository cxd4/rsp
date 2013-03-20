#include "../../vu/vu.h"

void MFC2(int rt, int vd, int element)
{
    if (rt == 0)
    {
        message("MFC2\t$zero, vd", 1);
        SR[rt] = 0x00000000;
        return;
    }
    if ((element & 0x1) != 0x0)
    {
        message("MFC2\nUnaligned element.", 0); /* A few games will try this. */
        element = (unsigned int)(element) >> 1;
        SR[rt]  = (signed char)(VR[vd][element]) << 8;
        element += 0x1;
        element &= 0xF;
        SR[rt] |= (unsigned char)(VR[vd][element] >> 8);
        return;
    }
    element = (unsigned int)(element) >> 1;
    SR[rt] = (signed short)VR[vd][element];
    return;
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

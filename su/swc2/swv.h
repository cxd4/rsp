/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Transposed Wrapped from Vector Unit  *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SWV(int vt, int element, signed offset, int base)
{ /* Dummy implementation only:  Do any games execute this? */
    char debugger[24] = "SWV\t$v00[X], 0x000($00)";
    const char digits[16] = {
        '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
    };
    debugger[006] |= vt / 10;
    debugger[007] |= vt % 10;
    debugger[011]  = digits[element & 0xF];
    debugger[017]  = digits[(offset >> 8) & 0xF];
    debugger[020]  = digits[(offset >> 4) & 0xF];
    debugger[021]  = digits[(offset >> 0) & 0xF];
    debugger[024] |= base / 10;
    debugger[025] |= base % 10;
    message(debugger, 3);
    return;
}

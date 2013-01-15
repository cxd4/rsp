/******************************************************************************\
* Project:  SP SU Emulation Table:  Move Control to Vector Unit (CTC2)         *
* Creator:  R. J. Swedlow                                                      *
* Release:  2013.01.11                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void CTC2(int rt, int vcr, int unused)
{
    unused = 0; /* no element specifier */
    switch (vcr &= 03) /* RCP no-exception override */
    {
        case 00:
            VCF[00] = (unsigned short)SR[rt];
            return;
        case 01:
            VCF[01] = (unsigned short)SR[rt];
            return;
        case 02:
            message("VCE\nMAME RSP does not 8-bit truncate?", 2);
            VCF[02] = (unsigned char)SR[rt];
            return;
        case 03:
            message("CTC2\nInvalid vector control register.", 1);
            return;
    }
}

/******************************************************************************\
* Project:  SP SU Emulation Table:  Move Control from Vector Unit (CFC2)       *
* Creator:  R. J. Swedlow                                                      *
* Release:  2013.01.11                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void CFC2(int rt, int vcr, int unused)
{
    if (rt == 0)
    {
        message("CFC2\t$zero, vcr", 1);
        SR[000] = 0x00000000;
        return;
    }
    unused = 0; /* no element specifier */
    switch (vcr & 03) /* RCP no-exception override */
    {
        case 00:
            SR[rt] = (signed short)VCF[00];
            return;
        case 01:
            SR[rt] = (signed short)VCF[01];
            return;
        case 02:
            message("VCE\nMAME RSP says this should be clipped?", 2);
            SR[rt] = VCF[02];
            return;
        case 03:
            message("CFC2\nInvalid vector control register.", 1);
            return;
    }
}

void SH(int rs, int rt, short imm)
{
    register unsigned int addr;

    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
    switch (addr & 0x003)
    {
        case 00:
        DEFAULT:
            addr ^= 02; /* halfword endian swap */
        case 01:
            *(short *)(RSP.DMEM + addr) = (short)SR[rt];
            return;
        case 02:  goto DEFAULT;
        case 03: {
            if (addr == 0xFFF) /* LOL */
            {
                message("SH\nCrossed DMEM allocation barrier.", 1);
                RSP.DMEM[0xFFF ^ 03] = (unsigned char)(SR[rt] >> 8);
                RSP.DMEM[0x000 ^ 03] = (unsigned char)SR[rt];
                return; /* No, MSVC didn't employ swaps/rotates. :( */
            }
            message("SH\nUntested, unoptimized.", 2);
            *(int *)(RSP.DMEM + addr - 3)
          = _byteswap_ulong(*(int *)(RSP.DMEM + addr - 3));
            *(int *)(RSP.DMEM + addr + 1)
          = _byteswap_ulong(*(int *)(RSP.DMEM + addr + 1));
            *(short *)(RSP.DMEM + addr) = (short)SR[rt];
            *(int *)(RSP.DMEM + addr - 3)
          = _byteswap_ulong(*(int *)(RSP.DMEM + addr - 3));
            *(int *)(RSP.DMEM + addr + 1)
          = _byteswap_ulong(*(int *)(RSP.DMEM + addr + 1));
            return;
        }
    }
}

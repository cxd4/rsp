void SH(int rs, int rt, short imm)
{
    register unsigned int addr;

    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
    if (addr & 0x001)
    {
        RSP.DMEM[addr ^ 03] = (unsigned short)SR[rt] >> 8;
        ++addr;
        addr &= 0x00000FFF;
        RSP.DMEM[addr ^ 03] = (unsigned char)SR[rt];
        return;
    }
    addr ^= 02; /* halfword endian swap */
    *(short *)(RSP.DMEM + addr) = (short)SR[rt];
    return;
}

void SB(int rs, int rt, short imm)
{
    register unsigned int addr;

    addr  = SR[rs] + (signed short)imm;
    addr ^= 03; /* big endian CPU correction */
    addr &= 0xFFF;
    *(RSP.DMEM + addr) = SR[rt] & 0x000000FF;
    return;
}

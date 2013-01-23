void XORI(int rs, int rt, short imm)
{
    if (rt == 0)
    {
        message("XORI\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = SR[rs] ^ (unsigned short)imm;
    return;
}

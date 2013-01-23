void SLTI(int rs, int rt, short imm)
{
    if (rt == 0)
    {
        message("SLTI\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = (signed)SR[rs] < (signed short)imm;
    return;
}

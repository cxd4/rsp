void ADDI(int rs, int rt, short imm)
{
    if (rt == 0)
    {
        message("ADDI\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = SR[rs] + (signed short)imm;
    return;
}

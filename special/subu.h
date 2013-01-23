void SUBU(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("SUBU\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rd] = SR[rs] - SR[rt];
    return;
}

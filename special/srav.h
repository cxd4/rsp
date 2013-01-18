void SRAV(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("SRAV\nTried to overwrite $zero.", 0);
        return;
    }
    SR[rd] = (signed)SR[rt] >> (SR[rs] & 31);
    return;
}

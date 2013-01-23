void SLLV(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("SLLV\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rd] = SR[rt] << (SR[rs] & 31);
    return;
}

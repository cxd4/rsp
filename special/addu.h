void ADDU(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("ADDU\nTried to overwrite $zero.", 0);
        return;
    }
    SR[rd] = SR[rs] + SR[rt];
    return;
}

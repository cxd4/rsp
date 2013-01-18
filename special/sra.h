void SRA(int unused_rs, int rt, int rd, int sa)
{
    unused_rs = 0;
    if (rd == 0)
    {
        message("SRA\nTried to overwrite $zero.", 0);
        return;
    }
    SR[rd] = (signed)SR[rt] >> sa;
    return;
}

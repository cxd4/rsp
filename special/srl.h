void SRL(int unused_rs, int rt, int rd, int sa)
{
    unused_rs = 0;
    if (rd == 0)
    {
        message("SRL\nTried to overwrite $zero.", 0);
        return;
    }
    SR[rd] = (unsigned)SR[rt] >> sa;
    return;
}

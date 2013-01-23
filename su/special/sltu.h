void SLTU(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("SLTU\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rd] = (unsigned)SR[rs] < (unsigned)SR[rt];
    return;
}

/* See the source code for SLT for an alternative algorithm. */

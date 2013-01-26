void ADD(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
     /* message("ADD\nTried to overwrite $zero.", 1); // Rareware gfx ucodes */
        return;
    }
    SR[rd] = SR[rs] + SR[rt];
    return;
}

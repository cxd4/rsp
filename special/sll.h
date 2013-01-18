void SLL(int unused_rs, int rt, int rd, int sa)
{
    unused_rs = 0;
    if (rd == 0) return; /* Most likely, this is NOP, so don't bother. */
    SR[rd] = SR[rt] << sa;
    return;
}

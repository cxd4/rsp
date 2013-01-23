void SLL(int unused_rs, int rt, int rd, int sa)
{
    if (rd == 0)
    {
        if (unused_rs || rt || sa) /* not NOP */
            message("SLL\nTried to overwrite $zero.", 0);
/* Message priority zero to avoid linking this if(), since NOP is so common. */
        return; /* Most likely, this is NOP, so don't bother. */
    }
    unused_rs = 0;
    SR[rd] = SR[rt] << sa;
    return;
}

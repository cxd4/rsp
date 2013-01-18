void SLT(int rs, int rt, int rd, int unused_sa)
{
    unused_sa = 0;
    if (rd == 0)
    {
        message("SLT\nTried to overwrite $zero.", 0);
        return;
    }
    SR[rd] = (signed)SR[rs] < (signed)SR[rt];
    return;
}

/* Alternative algorithm for SLT:
 *     if ((signed)SR[rs] < (signed)SR[rt]) {
 *         if (rd == 0) return;
 *         SR[rd] = 1;
 *     }
 *     SR[rd] = 0; // source should be discarded, not written, even if 0
 * While theoretically halving the checks for register $zero, less natural.
 * Maybe we want to see all cases where a game tries to write to zero.
 * That method is also less maintanable and more complex.  Not really faster.
 * Finally, when writing to MIPS $zero, the source is discarded, not written.
 */

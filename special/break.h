void BREAK(int unused_rs, int unused_rt, int unused_rd, int unused_sa)
{
    unused_rs = 0;
    unused_rt = 0;
    unused_rd = 0;
    unused_sa = 0;
    *RSP.SP_STATUS_REG |= 0x00000003;
/* We set SP_STATUS_BROKE (0010) because this is done if AND ONLY IF:  BREAK.
 * We set SP_STATUS_HALT (0001) incidentally.  (If we break, we also halt.)
 * Executing BREAK is NOT the only way to halt the RSP.  (Mask using MTC0.)
 */
    if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
    { /* This means "interrupt on break" (signal a VR4300 SP interrpt) */
        *RSP.MI_INTR_REG |= 0x00000001;
        RSP.CheckInterrupts();
        return;
    } /* I have never seen this be done yet, so the branch here is unlikely. */
    return;
}

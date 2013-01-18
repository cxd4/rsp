extern static int halt;

void BREAK(int unused_rs, int unused_rt, int unused_rd, int unused_sa)
{
    unused_rs = 0;
    unused_rt = 0;
    unused_rd = 0;
    unused_sa = 0;
    ++halt; /* RSP execution loop is while (halt == 0), so optimized halt != 0. */
    *RSP.SP_STATUS_REG |= 0x00000003;
    if (*RSP.SP_STATUS_REG & 0x00000040)
    {
        *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
        RSP.CheckInterrupts();
        return;
    }
    return;
}

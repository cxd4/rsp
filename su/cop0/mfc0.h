#ifdef SEARCH_INFINITE_LOOPS
void scan_ICACHE_for_cycle_fault(int cr);
/* My colossal attempt at covering up for faults in the host CPU emulator
 * (the main MIPS CPU, like Project64.exe) concerning cycle timing and
 * related inaccuracies.  Days of frustration were spent writing this.
 * I teach the software to teach its self, to intelligently "guess" which
 * CPU-RSP synchronization signal bit (SP_STATUS_SIG[?]) failed to get set.
 *
 * Additionally, I then XOR this bit in/out and assume this responsibility
 * over the main emulator EXE, although doing that update to the SP status
 * register is probably not necessary (especially since zilmar's method gets
 * away with just a simple break exiting out of the hung-up microcode).
 */
#endif

void MFC0(int rt, int rd)
{
    if (rt == 0)
    {
        message("MFC0\t$zero, rd", 1);
        SR[000] = 0x00000000;
        return;
    }
    switch (rd)
    {
        case 0x0:
            SR[rt] = *RSP.SP_MEM_ADDR_REG;
            return;
        case 0x1:
            SR[rt] = *RSP.SP_DRAM_ADDR_REG;
            return;
        case 0x2: /* have not verified / been able to test yet ? */
            message("MFC0\nDMA_READ_LENGTH", 2);
            SR[rt] = *RSP.SP_RD_LEN_REG;
            return;
        case 0x3:
            message("MFC0\nDMA_WRITE_LENGTH", 3);
            return; /* dunno what to do, so error */
        case 0x4:
            SR[rt] = *RSP.SP_STATUS_REG;
#ifdef WAIT_FOR_CPU_HOST
            ++MFC0_count[rt];
            if (MFC0_count[rt] > 07)
                *RSP.SP_STATUS_REG |= 0x00000001; /* Let OS restart the task. */
#endif
            return;
        case 0x5: /* if (*RSP.SP_DMA_FULL_REG != 0x00000000), check the flag? */
            SR[rt] = *RSP.SP_DMA_FULL_REG;
            return;
        case 0x6: /* if (*RSP.SP_DMA_BUSY_REG != 0x00000000), check the flag? */
            SR[rt] = *RSP.SP_DMA_FULL_REG;
            return;
        case 0x7:
            SR[rt] = *RSP.SP_SEMAPHORE_REG;
#ifdef SEMAPHORE_LOCK_CORRECTIONS
            *RSP.SP_SEMAPHORE_REG = 0x00000001;
            *RSP.SP_STATUS_REG |= 0x00000001; /* temporary bit to break CPU */
            return; /* Break the SP task (zilmar). */
#else
            return; /* old method, inaccurate */
#endif
        case 0x8:
            SR[rt] = *RSP.DPC_START_REG;
            return;
        case 0x9:
            SR[rt] = *RSP.DPC_END_REG;
            return;
        case 0xA:
            SR[rt] = *RSP.DPC_CURRENT_REG;
            return;
        case 0xB:
            if (*RSP.DPC_STATUS_REG & 0x00000600) /* end/start valid ? */
            { /* CP0 register locking/unlocking not tested yet. */
                message("MFC0\nCMD_STATUS", 2);
                *RSP.DPC_STATUS_REG &= ~0x00000600;
            }
            SR[rt] = *RSP.DPC_STATUS_REG;
            return;
        case 0xC:
            SR[rt] = *RSP.DPC_CLOCK_REG;
            return;
        case 0xD:
            SR[rt] = *RSP.DPC_BUFBUSY_REG;
            return;
        case 0xE:
            SR[rt] = *RSP.DPC_PIPEBUSY_REG;
            return;
        case 0xF:
            SR[rt] = *RSP.DPC_TMEM_REG;
            return;
    }
}

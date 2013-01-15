/******************************************************************************\
* Project:  SP SU Emulation Table:  Move from System Control Coprocessor (MFC0)*
* Creator:  R. J. Swedlow                                                      *
* Release:  2013.01.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

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
            return;
        case 0x5:
            if (*RSP.SP_DMA_FULL_REG)
                message("MFC0\nDMA_FULL", 3);
            SR[rt] = 0x00000000;
            return;
        case 0x6:
            if (*RSP.SP_DMA_BUSY_REG)
                message("MFC0\nDMA_BUSY", 3);
            SR[rt] = 0x00000000;
            return;
        case 0x7:
            SR[rt] = *RSP.SP_SEMAPHORE_REG;
            *RSP.SP_SEMAPHORE_REG = 0x00000001;
            *RSP.SP_SEMAPHORE_REG = 0x00000000; /* no cupport by CPU? */
            return; /* prevented MTC0 DPC status flags on NUS-CIC-6105 boots */
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
            { /* CP0 register locking/unlocking not added yet. */
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

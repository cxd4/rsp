void SP_DMA_WRITE(void)
{
    register unsigned int length;
    register unsigned int count;
    register unsigned int skip;
    const unsigned char *MSP_CACHE = ((*RSP.SP_MEM_ADDR_REG & 0x1000) == 0x000)
                                   ? RSP.DMEM : RSP.IMEM;

    skip   = *RSP.SP_WR_LEN_REG;
    length  = skip;
    length &= 0x00000FFF;
    skip >>= 12;
    count = (unsigned char)skip;
    ++count;
    skip >>= 8;
    ++length;
    skip  += length;
    while (count)
    {
        unsigned int offC, offD; /* SP cache and dynamic DMA pointers */
        register unsigned int i = 0;

        --count;
        while (i < length)
        {
            offC = (count*length + *RSP.SP_MEM_ADDR_REG + i) & 0x00000FFF;
            offD = (count*skip + *RSP.SP_DRAM_ADDR_REG + i) & 0x00FFFFFF;
            memcpy(RSP.RDRAM + offD, MSP_CACHE + offC, 1);
            i += 0x000001;
        }
    }
    *RSP.SP_DMA_BUSY_REG = 0x00000000;
    *RSP.SP_STATUS_REG &= ~0x00000004; /* SP_STATUS_DMABUSY */
}

void SP_DMA_READ(void)
{
    register unsigned int length;
    register unsigned int count;
    register unsigned int skip;
    unsigned char *MSP_CACHE = ((*RSP.SP_MEM_ADDR_REG & 0x1000) == 0x000)
                             ? RSP.DMEM : RSP.IMEM;

    skip   = *RSP.SP_RD_LEN_REG;
    length  = skip;
    length &= 0x00000FFF;
    skip >>= 12;
    count = (unsigned char)skip;
    ++count;
    skip >>= 8;
    ++length;
    skip  += length;
    while (count)
    {
        unsigned int offC, offD; /* SP cache and dynamic DMA pointers */
        register unsigned int i = 0;

        --count;
        while (i < length)
        {
            offC = (count*length + *RSP.SP_MEM_ADDR_REG + i) & 0x00000FFF;
            offD = (count*skip + *RSP.SP_DRAM_ADDR_REG + i) & 0x00FFFFFF;
            memcpy(MSP_CACHE + offC, RSP.RDRAM + offD, 1);
            i += 0x001;
        }
    }
    *RSP.SP_DMA_BUSY_REG = 0x00000000;
    *RSP.SP_STATUS_REG &= ~0x00000004; /* SP_STATUS_DMABUSY */
}

void MTC0(int rt, int rd)
{
    switch (rd)
    {
        case 0x0:
            *RSP.SP_MEM_ADDR_REG = SR[rt];
            if (SR[rt] & 07)
            { /* All DMA transfers must be 64-bit-aligned. */
                message("MTC0\nDMA_CACHE", 0); /* Boss Game Studios ucodes */
                *RSP.SP_MEM_ADDR_REG &= 0xFFFFFFF8;
            } /* Do NOT worry about the extra bits 0xFFFFE000 until DMA R/W. */
            return;
        case 0x1:
            *RSP.SP_DRAM_ADDR_REG = SR[rt]; /* 24-bit RDRAM pt */
            if (SR[rt] & 07)
            { /* We don't really care about the reserved bits, just & 07. */
                message("MTC0\nDMA_DRAM", 0); /* Factor 5 ucodes do this? */
                *RSP.SP_DRAM_ADDR_REG &= 0xFFFFFFF8;
            } /* If extra bits (SR[rt]&0xFF000000) are used, DMA R/W adapts. */
            return;
        case 0x2:
            *RSP.SP_RD_LEN_REG = SR[rt] | 07;
            SP_DMA_READ();
            return;
        case 0x3:
            *RSP.SP_WR_LEN_REG = SR[rt] | 07;
            SP_DMA_WRITE();
            return;
        case 0x4:
            if (SR[rt] & 0xFE000052)
                message("MTC0\nSP_STATUS", 2); /* New way to break RSP tasks. */
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000001) <<  0);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000002) <<  0);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000004) <<  1);
            *RSP.MI_INTR_REG &= ~((SR[rt] & 0x00000008) >> 3); /* SP_CLR_INTR */
         /* if (SR[rt] & 0x00000010) // Boss Game Studios ucodes
                message("MTC0\nSP_SET_INTR", 3); // too complex, not worth it */
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000020) <<  5);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000040) <<  5);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000080) <<  6);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000100) <<  6);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000200) <<  7);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00000400) <<  7);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00000800) <<  8);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00001000) <<  8);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00002000) <<  9);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00004000) <<  9);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00008000) << 10);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00010000) << 10);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00020000) << 11);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00040000) << 11);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00080000) << 12);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00100000) << 12);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00200000) << 13);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x00400000) << 13);
            *RSP.SP_STATUS_REG &= ~(!!(SR[rt] & 0x00800000) << 14);
            *RSP.SP_STATUS_REG |=  (!!(SR[rt] & 0x01000000) << 14);
            return;
        case 0x5: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nDMA_FULL", 3);
            return;
        case 0x6: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nDMA_BUSY", 3);
            return;
        case 0x7:
            if (SR[rt]) /* semaphore release if and only if set to zero */
                message("MTC0\nSP_RESERVED", 2);
            *RSP.SP_SEMAPHORE_REG = 0x00000000;
            return;
        case 0x8:
            if (*RSP.DPC_BUFBUSY_REG)
            {
                message("MTC0\nCMD_START", 2);
                return; /* lock hazards not implemented */
            }
            *RSP.DPC_START_REG   = SR[rt];
            *RSP.DPC_CURRENT_REG = SR[rt]; /* Dunno for sure about this. */
            *RSP.DPC_END_REG     = SR[rt]; /* NEW, not in PJ64/MAME */
            if (SR[rt] & 07) /* All DMA transfers must be 64-bit-aligned. */
            {
                message("MTC0\nCMD_START", 1);
                *RSP.DPC_START_REG   &= 0xFFFFFFF8;
                *RSP.DPC_CURRENT_REG &= 0xFFFFFFF8;
                *RSP.DPC_END_REG     &= 0xFFFFFFF8;
            }
            return;
        case 0x9:
            if (*RSP.DPC_BUFBUSY_REG)
            {
                message("MTC0\nCMD_END", 2);
                return; /* lock hazards not implemented */
            }
            *RSP.DPC_END_REG = SR[rt];
            if (SR[rt] & 07)
            {
                message("MTC0\nCMD_END", 1);
                *RSP.DPC_END_REG &= 0xFFFFFFF8;
            }
            if (RSP.ProcessRdpList == NULL) return; /* zilmar GFX #1.2 */
            RSP.ProcessRdpList();
            return;
        case 0xA: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_CURRENT", 1);
            return;
        case 0xB:
            if (SR[rt] & 0xFFFFFFC0)
            {
                if (SR[rt] & 0x00000040) {
                    if (*RSP.DPC_TMEM_REG) /* if != 0 then clear it how?? */
                        message("CMD_STATUS\nTMEM_CTR", 2);
                    *RSP.DPC_TMEM_REG = 0x00000000;
                }
                if (SR[rt] & 0x00000080) {
                    if (*RSP.DPC_PIPEBUSY_REG)
                        message("CMD_STATUS\nPIPE_CTR", 2);
                    *RSP.DPC_PIPEBUSY_REG = 0x00000000;
                }
                if (SR[rt] & 0x00000100) {
                    if (*RSP.DPC_BUFBUSY_REG)
                        message("CMD_STATUS\nCOMMAND_CTR", 2);
                    *RSP.DPC_BUFBUSY_REG = 0x00000000;
                }
                if (SR[rt] & 0x00000200) {
                    if (*RSP.DPC_CLOCK_REG)
                        message("CMD_STATUS\nCLOCK_CTR", 2);
                    *RSP.DPC_CLOCK_REG = 0x00000000;
                }
                if (SR[rt] & 0xFFFFFC00) /* Reserved / unused; just ignore. */
                    message("MTC0\nCMD_STATUS", 1);
            }
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000001) << 0);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000002) << 0);
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000004) << 1);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000008) << 1);
            *RSP.DPC_STATUS_REG &= ~(!!(SR[rt] & 0x00000010) << 2);
            *RSP.DPC_STATUS_REG |=  (!!(SR[rt] & 0x00000020) << 2);
            return;
        case 0xC: /* ??? is this read-only or not, hard to tell */
            message("MTC0\nCMD_CLOCK", 2);
            *RSP.DPC_CLOCK_REG = SR[rt];
            return;
        case 0xD: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_BUSY", 1);
            return;
        case 0xE: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_PIPE_BUSY", 1);
            return;
        case 0xF: /* read-only register, cannot directly write using MTC0 */
            message("MTC0\nCMD_TMEM_BUSY", 1);
            return;
    }
}

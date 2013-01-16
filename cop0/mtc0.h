/******************************************************************************\
* Project:  SP SU Emulation Table:  Move to System Control Coprocessor (MTC0)  *
* Creator:  R. J. Swedlow                                                      *
* Release:  2013.01.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#define DMA_CACHE   (*RSP.SP_MEM_ADDR_REG)
#define DMA_DRAM    (*RSP.SP_DRAM_ADDR_REG)

/* defined in systems/n64.c */
#define rdram ((UINT32*)RSP.RDRAM)
//extern UINT32 *rdram;
#define rsp_imem ((UINT32*)RSP.IMEM)
//extern UINT32 *rsp_imem;
#define rsp_dmem ((UINT32*)RSP.DMEM)
//extern UINT32 *rsp_dmem;
//extern void dp_full_sync(void);

static int sp_dma_length;

static void sp_dma(int direction)
{
// новейшая версия от Ville Linde
    int i, j;
    int length;
    int count;
    int skip;
// мой код
    UINT8 *src, *dst;
    INT32 l = sp_dma_length;

    length = ((l & 0xFFF) | 7) + 1;
    skip   = (l >> 20) + length;
    count  = ((l >> 12) & 0xFF) + 1;

    if (direction == 0) // RDRAM -> I/DMEM
    {
// 2 строки от Вилле Линде
// UINT32 src_address = DMA_DRAM & 0xFFFFFF;
// UINT32 dst_address = (DMA_CACHE & 0x1000) ? 0x4001000 : 0x4000000;
// мой код
        src = (UINT8*)&rdram[(DMA_DRAM & 0xFFFFFF) / 4];
        dst = (DMA_CACHE & 0x1000)
            ? (UINT8*)&rsp_imem[(DMA_CACHE & 0xFFF) / 4]
            : (UINT8*)&rsp_dmem[(DMA_CACHE & 0xFFF) / 4];
        // cpuintrf_push_context(0); // потупим
#define BYTE8_XOR_BE(a) ((a)^7) // исправляет JFG, Ocarina of Time
        for (j = 0; j < count; j++)
        {
            for (i = 0; i < length; i++)
            {
                // UINT8 b = program_read_byte_64be(src_address + i + (j*skip));
// program_write_byte_64be(dst_address + ((DMA_CACHE + i + (j*length)) & 0xFFF), b);
                dst[BYTE8_XOR_BE((i + j*length)&0xfff)] = src[BYTE8_XOR_BE(i + j*skip)];
            }
        }
        // cpuintrf_pop_context(); // потупим
        *RSP.SP_DMA_BUSY_REG = 0;
        *RSP.SP_STATUS_REG  &= ~SP_STATUS_DMABUSY;
    }
    else // I/DMEM -> RDRAM
    {
        // 2 строки от Вилле Линде
        // UINT32 dst_address = DMA_DRAM & 0xFFFFFF;
        // UINT32 src_address = (DMA_CACHE & 0x1000) ? 0x4001000 : 0x4000000;
// мой код
        dst = (UINT8*)&rdram[(DMA_DRAM & 0xFFFFFF) / 4];
        src = (DMA_CACHE & 0x1000)
            ? (UINT8*)&rsp_imem[(DMA_CACHE & 0xFFF) / 4]
            : (UINT8*)&rsp_dmem[(DMA_CACHE & 0xFFF) / 4];
        // cpuintrf_push_context(0); // потупим
        for (j = 0; j < count; j++)
        {
            for (i = 0; i < length; i++)
            {
                // UINT8 b = program_read_byte_64be(src_address + ((DMA_CACHE + i + (j*length)) & 0xfff));
                // program_write_byte_64be(dst_address + i + (j*skip), b);
                dst[BYTE8_XOR_BE(i + j*skip)]
              = src[BYTE8_XOR_BE((i + j*length)&0xfff)];
            }
        }
        // cpuintrf_pop_context(); // потупим
        *RSP.SP_DMA_BUSY_REG = 0;
        *RSP.SP_STATUS_REG  &= ~SP_STATUS_DMABUSY;
    }
}

void MTC0(int rt, int rd)
{
/* Not yet implemented:  SP interrupt locking.
 * One or two games need to do this with SP_STATUS, but left it out to see.
 * I forgot the games. :( :) :D
 */
    switch (rd)
    {
        case 0x0:
            *RSP.SP_MEM_ADDR_REG = SR[rt];
            if (SR[rt] & 07)
            { /* All DMA transfers must be 64-bit-aligned. */
                message("MTC0\nDMA_CACHE", 1);
                *RSP.SP_MEM_ADDR_REG &= 0xFFFFFFF8;
            } /* Do NOT worry about the extra bits 0xFFFFE000 until DMA R/W. */
            return;
        case 0x1:
            *RSP.SP_DRAM_ADDR_REG = SR[rt]; /* 24-bit RDRAM pt */
            if (SR[rt] & 07)
            { /* We don't really care about the reserved bits, just & 07. */
                message("MTC0\nDMA_DRAM", 1);
                *RSP.SP_DRAM_ADDR_REG &= 0xFFFFFFF8;
            } /* If extra bits (SR[rt]&0xFF000000) are used, DMA R/W adapts. */
            return;
        case 0x2:
            sp_dma_length = SR[rt] | 07;
            sp_dma(0);
            return;
        case 0x3:
            sp_dma_length = SR[rt] | 07;
            sp_dma(1);
            return;
        case 0x4:
/* To-do:  It is possible to use a switch statement here to massively speed
 * up all of the flags maintenance in place of this massive, complex chain of
 * if()'s, by using a switch on every combination possibility of SR[rt] flags
 * set, but that of course is going to take time to implement.  The real
 * bottleneck behind why games are slow is the RDP and VU computational ops.
 */
            if (SR[rt] & 0x00000001) /* clear halt */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_HALT;
            if (SR[rt] & 0x00000002) /* set halt */
                *RSP.SP_STATUS_REG |= SP_STATUS_HALT;
            if (SR[rt] & 0x00000004) /* clear broke */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_BROKE;
            if (SR[rt] & 0x00000008) /* clear SP interrupt */
                message("MTC0\nSP INTR:CLR", 3);
            if (SR[rt] & 0x00000010) /* set SP interrupt */
                message("MTC0\nSP INTR:SET", 3);
            if (SR[rt] & 0x00000020) /* clear single step */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SSTEP;
            if (SR[rt] & 0x00000040) /* set single step */
                *RSP.SP_STATUS_REG |= SP_STATUS_SSTEP;
            if (SR[rt] & 0x00000080) /* clear interrupt on break */
                message("MTC0\nSP INTR BREAK:CLR", 3);
            if (SR[rt] & 0x00000100) /* set interrupt on break */
                message("MTC0\nSP INTR BREAK:SET", 3);
            if (SR[rt] & 0x00000200) /* clear signal 0 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG0;
            if (SR[rt] & 0x00000400) /* set signal 0 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG0;
            if (SR[rt] & 0x00000800) /* clear signal 1 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG1;
            if (SR[rt] & 0x00001000) /* set signal 1 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG1;
            if (SR[rt] & 0x00002000) /* clear signal 2 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG2;
            if (SR[rt] & 0x00004000) /* set signal 2 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG2;
            if (SR[rt] & 0x00008000) /* clear signal 3 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG3;
            if (SR[rt] & 0x00010000) /* set signal 3 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG3;
            if (SR[rt] & 0x00020000) /* clear signal 4 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG4;
            if (SR[rt] & 0x00040000) /* set signal 4 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG4;
            if (SR[rt] & 0x00080000) /* clear signal 5 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG5;
            if (SR[rt] & 0x00100000) /* set signal 5 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG5;
            if (SR[rt] & 0x00200000) /* clear signal 6 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG6;
            if (SR[rt] & 0x00400000) /* set signal 6 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG6;
            if (SR[rt] & 0x00800000) /* clear signal 7 */
                *RSP.SP_STATUS_REG &= ~SP_STATUS_SIG7;
            if (SR[rt] & 0x01000000) /* set signal 7 */
                *RSP.SP_STATUS_REG |= SP_STATUS_SIG7;
            if (SR[rt] & 0xFE000000) /* reserved/unused, just ignore these */
                message("MTC0\nSP_STATUS", 1);
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
            message("MTC0\nCMD_START", 0);
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
/* To-do:  Here would be a good place for a switch() on mask combinations,
 * instead of this complex chain of if()'s.  However, the technique given
 * here is more readable for the purpose of extracting the information.
 */
            if (SR[rt] & 0x00000001)
                *RSP.DPC_STATUS_REG &= ~DP_STATUS_XBUS_DMA;
            if (SR[rt] & 0x00000002)
                *RSP.DPC_STATUS_REG |= DP_STATUS_XBUS_DMA;
            if (SR[rt] & 0x00000004)
                *RSP.DPC_STATUS_REG &= ~DP_STATUS_FREEZE;
            if (SR[rt] & 0x00000008)
                *RSP.DPC_STATUS_REG |= DP_STATUS_FREEZE;
            if (SR[rt] & 0x00000010)
                *RSP.DPC_STATUS_REG &= ~DP_STATUS_FLUSH;
            if (SR[rt] & 0x00000020)
                *RSP.DPC_STATUS_REG |= DP_STATUS_FLUSH;
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

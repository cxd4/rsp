/******************************************************************************\
* Authors:  Iconoclast                                                         *
* Release:  2013.12.12                                                         *
* License:  CC0 Public Domain Dedication                                       *
*                                                                              *
* To the extent possible under law, the author(s) have dedicated all copyright *
* and related and neighboring rights to this software to the public domain     *
* worldwide. This software is distributed without any warranty.                *
*                                                                              *
* You should have received a copy of the CC0 Public Domain Dedication along    *
* with this software.                                                          *
* If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.             *
\******************************************************************************/
#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "Rsp_#1.1.h"
#include "rsp.h"
#include "bench.h"

EXPORT void CALL CloseDLL(void)
{
    RSP.RDRAM = NULL; /* so DllTest benchmark doesn't think ROM is still open */
    return;
}
static const char DLL_about[] =
    "RSP Interpreter by Iconoclast&&ECHO."\
    "&&ECHO "\
    "Thanks for test RDP:  Jabo, ziggy, angrylion\n"\
    "RSP driver examples:  bpoint, zilmar, Ville Linde\n"\
    "Helpful shenanigans:  mudlord, MarathonMan, Garteal";
EXPORT void CALL DllAbout(HWND hParent)
{
    hParent = NULL;
    message(DLL_about, 3);
    return;
}
EXPORT void CALL DllConfig(HWND hParent)
{
    FILE* stream;
    register int PC;

    hParent = NULL;
    system("sp_cfgui"); /* This launches an EXE by default (if not, BAT/CMD). */
    update_conf(CFG_FILE);
    if (RSP.DMEM == RSP.IMEM || *RSP.SP_PC_REG == 0x00000000)
        return;

    export_SP_memory();
    trace_RSP_registers();
    stream = fopen("rsp_task.txt", "w");
    fprintf(stream, "off   inst             disassembled\n");
    fprintf(stream, "--- -------- --------------------------------\n");
    for (PC = 0; PC < 4096; PC += 4)
    {
        const uint32_t inst = *(uint32_t *)(RSP.IMEM + PC);

        disassemble(inst);
        fprintf(stream, "%03X %08"PRIX32" %s\n", PC, inst, disasm);
    }
    fclose(stream);
    return;
}
EXPORT unsigned int CALL DoRspCycles(unsigned int cycles)
{
    if (*RSP.SP_STATUS_REG & 0x00000003)
    {
        message("SP_STATUS_HALT", 3);
        return 0x00000000;
    }
    switch (*(unsigned int *)(RSP.DMEM + 0xFC0))
    { /* Simulation barrier to redirect processing externally. */
#ifdef EXTERN_COMMAND_LIST_GBI
        case 0x00000001:
            if (CFG_HLE_GFX == 0)
                break;
            if (*(unsigned int *)(RSP.DMEM + 0xFF0) == 0x00000000)
                break; /* Resident Evil 2 */
            if (RSP.ProcessDList == NULL) {/*branch next*/} else
                RSP.ProcessDList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            if (*RSP.DPC_STATUS_REG & 0x00000002) /* DPC_STATUS_FREEZE */
            {
                message("DPC_CLR_FREEZE", 2);
                *RSP.DPC_STATUS_REG &= ~0x00000002;
            }
            return 0;
#endif
#ifdef EXTERN_COMMAND_LIST_ABI
        case 0x00000002: /* OSTask.type == M_AUDTASK */
            if (CFG_HLE_AUD == 0)
                break;
            if (RSP.ProcessAList == 0) {} else
                RSP.ProcessAList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            return 0;
#endif
    }
    run_task();
    return (cycles);
}
EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    PluginInfo -> Version = 0x0101; /* zilmar #1.1 (only standard RSP spec) */
    PluginInfo -> Type = PLUGIN_TYPE_RSP;
strcpy(
    PluginInfo -> Name, DLL_name);
    PluginInfo -> NormalMemory = 0;
    PluginInfo -> MemoryBswaped = 1;
    return;
}

RCPREG* CR[16];
EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, unsigned int *CycleCount)
{
    if (CycleCount != NULL) /* cycle-accuracy not doable with today's hosts */
        *CycleCount = 0x00000000;
    update_conf(CFG_FILE);

    if (Rsp_Info.DMEM == Rsp_Info.IMEM) /* usually dummy RSP data for testing */
        return; /* DMA is not executed just because plugin initiates. */
    while (Rsp_Info.IMEM != Rsp_Info.DMEM + 4096)
        message("Virtual host map noncontiguity.", 3);

    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x04001000 & 0x00000FFF; /* task init bug on Mupen64 */
    CR[0x0] = RSP.SP_MEM_ADDR_REG;
    CR[0x1] = RSP.SP_DRAM_ADDR_REG;
    CR[0x2] = RSP.SP_RD_LEN_REG;
    CR[0x3] = RSP.SP_WR_LEN_REG;
    CR[0x4] = RSP.SP_STATUS_REG;
    CR[0x5] = RSP.SP_DMA_FULL_REG;
    CR[0x6] = RSP.SP_DMA_BUSY_REG;
    CR[0x7] = RSP.SP_SEMAPHORE_REG;
    CR[0x8] = RSP.DPC_START_REG;
    CR[0x9] = RSP.DPC_END_REG;
    CR[0xA] = RSP.DPC_CURRENT_REG;
    CR[0xB] = RSP.DPC_STATUS_REG;
    CR[0xC] = RSP.DPC_CLOCK_REG;
    CR[0xD] = RSP.DPC_BUFBUSY_REG;
    CR[0xE] = RSP.DPC_PIPEBUSY_REG;
    CR[0xF] = RSP.DPC_TMEM_REG;
    return;
}
EXPORT void CALL RomClosed(void)
{
    *RSP.SP_PC_REG = 0x00000000;
    return;
}

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rsp_#1.1.h"
#include "rsp.h"
#include "bench.h"

EXPORT void CALL CloseDLL(void)
{
    RomClosed();
    return;
}
static const char DLL_about[] =
    "RSP Interpreter by Iconoclast&&ECHO."\
    "&&ECHO "\
    "Thanks for test RDP:  Jabo, ziggy, and angrylion\n"\
    "RSP driver examples:  bpoint, zilmar, and Ville Linde\n"\
    "Helpful shenanigans:  MarathonMan, dsx, and mudlord";
EXPORT void CALL DllAbout(HWND hParent)
{
    hParent = NULL;
    message(DLL_about, 3);
    return;
}
EXPORT void CALL DllConfig(HWND hParent)
{
    hParent = NULL;
    system("sp_cfgui"); /* This launches an EXE by default (if not, BAT/CMD). */
    update_conf(CFG_FILE);
    if (CFG_QUEUE_E_DRAM)
        export_DRAM();
    if (CFG_QUEUE_E_DMEM)
        export_data_cache();
    if (CFG_QUEUE_E_IMEM) /* to-do:  Make it also write the disassembly? */
        export_instruction_cache();
    if (CFG_TRACE_RSP_REGISTERS) /* to-do:  Make this counter of delay slots? */
        trace_RSP_registers();
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
EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, unsigned int *CycleCount)
{
    if (CycleCount != NULL) /* cycle-accuracy not doable with today's hosts */
        *CycleCount = 0x00000000;
    update_conf(CFG_FILE);

    RSP.DMEM = Rsp_Info.DMEM;
    RSP.IMEM = Rsp_Info.IMEM;
    if (RSP.DMEM == RSP.IMEM) /* usually dummy RSP data, not to start ROM */
        return; /* DMA is not executed just because plugin initiates. */
    while (RSP.IMEM != RSP.DMEM + 4096)
        message("Virtual host map noncontiguity.", 3);

    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x04001000 & 0x00000FFF; /* task init bug on Mupen64 */
    return;
}
EXPORT void CALL InitiateRSPDebugger(DEBUG_INFO DebugInfo)
{
    DebugInfo.UpdateMemory();
    return;
}
EXPORT void CALL RomClosed(void)
{
    RSP.RDRAM = NULL; /* so DllTest benchmark doesn't think ROM is still open */
    *RSP.SP_PC_REG = 0x00000000;
    return;
}

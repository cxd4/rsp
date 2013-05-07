#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rsp_#1.1.h"
#include "rsp.h"

EXPORT void CALL CloseDLL(void)
{
    return;
}
EXPORT void CALL DllAbout(HWND hParent)
{
    MessageBoxA(hParent, L_ABOUT, L_TITLE, 0x00000040);
    return;
}
#ifdef SP_EXECUTE_LOG
EXPORT void CALL DllConfig(HWND hParent)
{
    trace_RSP_registers();
    export_SP_memory();
    if (output_log == NULL)
    {
        output_log = fopen("simd_log.bin", "ab");
        return;
    }
    fclose(output_log);
    output_log = NULL;
    hParent = NULL;
    return;
}
#endif
EXPORT unsigned int CALL DoRspCycles(unsigned int cycles)
{
    if (*RSP.SP_STATUS_REG & 0x00000003)
    {
        message("SP_STATUS_HALT", 3);
        return 0x00000000;
    }
#if defined(EXTERN_COMMAND_LIST_GBI) || defined(EXTERN_COMMAND_LIST_ABI)
    switch (*(unsigned int *)(RSP.DMEM + 0xFC0))
    { /* Simulation barrier to redirect processing externally. */
#ifdef EXTERN_COMMAND_LIST_GBI
        case 0x00000001:
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
#endif
#if (defined EXTERN_COMMAND_LIST_GBI && defined EXTERN_COMMAND_LIST_ABI)
    {
        const char digits[16] = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
        };
        const unsigned int task = *(unsigned int *)(RSP.DMEM + 0xFC0);
        char task_hex[9] = "";

        task_hex[00] = digits[(task & 0xF0000000) >> 28];
        task_hex[01] = digits[(task & 0x0F000000) >> 24];
        task_hex[02] = digits[(task & 0x00F00000) >> 20];
        task_hex[03] = digits[(task & 0x000F0000) >> 16];
        task_hex[04] = digits[(task & 0x0000F000) >> 12];
        task_hex[05] = digits[(task & 0x00000F00) >>  8];
        task_hex[06] = digits[(task & 0x000000F0) >>  4];
        task_hex[07] = digits[(task & 0x0000000F) >>  0];
        MessageBoxA(NULL, task_hex, "OSTask.type", 0x00000000);
    }
#endif
    run_microcode();
    return (cycles);
}
EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    PluginInfo -> Version = 0x0101; /* zilmar #1.1 (only standard RSP spec) */
    PluginInfo -> Type = PLUGIN_TYPE_RSP;
strcpy(/* Not meant to be a CRT dependency--should optimize to QWORD moves. */
    PluginInfo -> Name, L_NAME);
    PluginInfo -> NormalMemory = 0;
    PluginInfo -> MemoryBswaped = 1;
    return;
}
EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, unsigned int *CycleCount)
{
    if (CycleCount != NULL) /* cycle-accuracy not doable with today's hosts */
        *CycleCount = 0x00000000;
    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x04001000 & 0x00000FFF;
    if (RSP.DMEM == RSP.IMEM) /* usually dummy RSP data, not to start ROM */
        return; /* DMA is not executed just because plugin initiates. */
    else
        while (RSP.IMEM != RSP.DMEM + 4096)
            message("Virtual host map noncontiguity.", 3);
#ifdef SP_EXECUTE_LOG
    output_log = fopen("simd_log.bin", "ab");
#endif
    return;
}
EXPORT void CALL InitiateRSPDebugger(DEBUG_INFO DebugInfo)
{
    DebugInfo.UpdateMemory();
    return;
}
EXPORT void CALL RomClosed(void)
{
    *RSP.SP_PC_REG = 0x00000000;
    return;
}

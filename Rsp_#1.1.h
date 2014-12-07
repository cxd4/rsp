#ifndef __RSP_1_1_H__
#define __RSP_1_1_H__

#include "my_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define PLUGIN_TYPE_RSP             1
#define PLUGIN_TYPE_GFX             2
#define PLUGIN_TYPE_AUDIO           3
#define PLUGIN_TYPE_CONTROLLER      4

#ifndef PLUGIN_API_VERSION
#define PLUGIN_API_VERSION      0x0101
#endif

/*
 * slight changes to zilmar's spec file for portability
 *
 * The raw plugin spec headers by zilmar required WIN32 definitions.
 *
 * Here, the sufficient ANSI approximations are given so that this header
 * will operate more independently.
 */
struct a_struct__ {int unused;};
typedef struct a_struct__* struct_p;
typedef struct {
    i32 left;
    i32 top;
    i32 right;
    i32 bottom;
} winapi_rect;
typedef struct {
    struct_p hdc;
    int fErase;
    winapi_rect rcPaint;
    int fRestore;
    int fIncUpdate;
    u8 rgbReserved[32];
} winapi_paintstruct;

typedef struct {
    u16 Version;        /* Should be set to 0x0101. */
    u16 Type;           /* set to PLUGIN_TYPE_RSP */
    char Name[100];     /* name of the DLL */

    /* If DLL supports memory these memory options then set them to TRUE. */
    int NormalMemory;   /* a normal byte array */
    int MemoryBswaped;  /* a normal byte array in little-endian byte order */
} PLUGIN_INFO;

typedef struct {
    struct_p* hInst;
    int MemoryBswaped;

    u8* RDRAM;
    u8* DMEM;
    u8* IMEM;

    u32* MI_INTR_REG;

    u32* SP_MEM_ADDR_REG;
    u32* SP_DRAM_ADDR_REG;
    u32* SP_RD_LEN_REG;
    u32* SP_WR_LEN_REG;
    u32* SP_STATUS_REG;
    u32* SP_DMA_FULL_REG;
    u32* SP_DMA_BUSY_REG;
    u32* SP_PC_REG; /* This was supposed to be defined AFTER semaphore. */
    u32* SP_SEMAPHORE_REG;
#if 0
    u32* SP_PC_REG; /* CPU-mapped between SP and DP command buffer regs */
#endif
    u32* DPC_START_REG;
    u32* DPC_END_REG;
    u32* DPC_CURRENT_REG;
    u32* DPC_STATUS_REG;
    u32* DPC_CLOCK_REG;
    u32* DPC_BUFBUSY_REG;
    u32* DPC_PIPEBUSY_REG;
    u32* DPC_TMEM_REG;

    void (*CheckInterrupts)(void);
    void (*ProcessDList)(void);
    void (*ProcessAList)(void);
    void (*ProcessRdpList)(void);
    void (*ShowCFB)(void);
} RSP_INFO;

typedef struct {
	/* menu */
	/* Items should have an ID between 5001 and 5100 .*/
	struct_p hRSPMenu;
	void (*ProcessMenuItem)(int ID);

	/* Break Points */
	int UseBPoints;
	char BPPanelName[20];
	void (*Add_BPoint)(void);
	void (*CreateBPPanel)(struct_p hDlg, winapi_rect rcBox);
	void (*HideBPPanel)(void);
	void (*PaintBPPanel)(winapi_paintstruct ps);
	void (*ShowBPPanel)(void);
	void (*RefreshBpoints)(struct_p hList);
	void (*RemoveBpoint)(struct_p hList, int index );
	void (*RemoveAllBpoint)(void);

	/* RSP command window */
	void (*Enter_RSP_Commands_Window)(void);
} RSPDEBUG_INFO;

typedef struct {
    void (*UpdateBreakPoints)(void);
    void (*UpdateMemory)(void);
    void (*UpdateR4300iRegisters)(void);
    void (*Enter_BPoint_Window)(void);
    void (*Enter_R4300i_Commands_Window)(void);
    void (*Enter_R4300i_Register_Window)(void);
    void (*Enter_RSP_Commands_Window)(void);
    void (*Enter_Memory_Window)(void);
} DEBUG_INFO;

#if defined(WIN32)
#define EXPORT      __declspec(dllexport)
#define CALL        __cdecl
#else
#define EXPORT      __attribute__((visibility("default")))
#define CALL
#endif

/******************************************************************
  Function: CloseDLL
  Purpose:  This function is called when the emulator is closing
            down allowing the DLL to de-initialise.
  input:    none
  output:   none
*******************************************************************/ 
EXPORT void CALL CloseDLL(void);

/******************************************************************
  Function: DllAbout
  Purpose:  This function is optional function that is provided
            to give further information about the DLL.
  input:    a handle to the window that calls this function
  output:   none
*******************************************************************/ 
EXPORT void CALL DllAbout(struct_p hParent);

/******************************************************************
  Function: DllConfig
  Purpose:  This function is optional function that is provided
            to allow the user to configure the DLL
  input:    a handle to the window that calls this function
  output:   none
*******************************************************************/
EXPORT void CALL DllConfig(struct_p hParent);

/******************************************************************
  Function: DllTest
  Purpose:  This function is optional function that is provided
            to allow the user to test the DLL
  input:    a handle to the window that calls this function
  output:   none
*******************************************************************/ 
EXPORT void CALL DllTest(struct_p hParent);

/******************************************************************
  Function: DoRspCycles
  Purpose:  This function is to allow the RSP to run in parallel
            with the r4300 switching control back to the r4300 once
            the function ends.
  input:    The number of cycles that is meant to be executed
  output:   The number of cycles that was executed. This value can
            be greater than the number of cycles that the RSP
            should have performed.
            (this value is ignored if the RSP is stopped)
*******************************************************************/ 
EXPORT u32 CALL DoRspCycles(u32 Cycles);

/******************************************************************
  Function: GetDllInfo
  Purpose:  This function allows the emulator to gather information
            about the DLL by filling in the PluginInfo structure.
  input:    a pointer to a PLUGIN_INFO structure that needs to be
            filled by the function. (see def above)
  output:   none
*******************************************************************/ 
EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo);

/******************************************************************
  Function: InitiateRSP
  Purpose:  This function is called when the DLL is started to give
            information from the emulator that the n64 RSP 
            interface needs
  input:    Rsp_Info is passed to this function which is defined
            above.
            CycleCount is the number of cycles between switching
            control between the RSP and r4300i core.
  output:   none
*******************************************************************/ 
EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, u32* CycleCount);

/******************************************************************
  Function: RomClosed
  Purpose:  This function is called when a rom is closed.
  input:    none
  output:   none
*******************************************************************/ 
EXPORT void CALL RomClosed(void);

/*
 * optional in version #1.1 of the plugin spec
 * These symbols do not need exporting for emulators to accept the module.
 */

/******************************************************************
  Function: GetRspDebugInfo
  Purpose:  This function allows the emulator to gather information
            about the debug capabilities of the dll by filling in
			the DebugInfo structure.
  input:    a pointer to a RSPDEBUG_INFO stucture that needs to be
            filled by the function. (see def above)
  output:   none
*******************************************************************/
EXPORT void CALL GetRspDebugInfo(RSPDEBUG_INFO* RSPDebugInfo);

/******************************************************************
  Function: InitiateRSPDebugger
  Purpose:  This function is called when the DLL is started to give
            information from the emulator that the n64 RSP
			interface needs to intergrate the debugger with the
			rest of the emulator.
  input:    DebugInfo is passed to this function which is defined
            above.
  output:   none
*******************************************************************/
EXPORT void CALL InitiateRSPDebugger(DEBUG_INFO DebugInfo);

/*
 * required in version #1.2 of the RSP plugin spec
 *
 * Most of these functions were made to inhibit private plugin distribution
 * from Project64 in its commercial state, and there is no documentation of
 * these in the source to Project64 2.x as of yet.
 */
EXPORT void CALL RomOpen(void);
EXPORT void CALL EnableDebugging(int Enabled);
EXPORT void CALL PluginLoaded(void);

/************ Profiling **************/
#ifndef FALSE
#define FALSE       0
#define TRUE        1
#endif

#define Default_ProfilingOn         FALSE
#define Default_IndvidualBlock      FALSE
#define Default_ShowErrors          FALSE
#define Default_AudioHle            FALSE

#define InterpreterCPU      0
#define RecompilerCPU       1

#if defined(__cplusplus)
}
#endif

#endif

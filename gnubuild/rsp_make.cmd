@ECHO OFF
TITLE MinGW Compiler Suite Invocation
CD ..\..\MINGW\BIN\

ECHO Building RSP interpreter... (LLE gfx, LLE audio)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -o ../rsp/rsp.dll ../../rsp/rsp.c

ECHO Building RSP interpreter... (LLE gfx, HLE audio)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -DEXTERN_COMMAND_LIST_ABI -o ../rsp/rsp_lle.dll ../../rsp/rsp.c

ECHO Building RSP interpreter... (HLE gfx, LLE audio)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -DEXTERN_COMMAND_LIST_GBI -o ../rsp/rsp_mle.dll ../../rsp/rsp.c

ECHO Building RSP interpreter... (HLE gfx, HLE audio)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -DEXTERN_COMMAND_LIST_GBI -DEXTERN_COMMAND_LIST_ABI -o ../rsp/rsp_hle.dll ../../rsp/rsp.c

ECHO Building RSP interpreter... (need Project64 2.x)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -DSEMAPHORE_LOCK_CORRECTIONS -DWAIT_FOR_CPU_HOST -o ../rsp/rsp_pj64.dll ../../rsp/rsp.c

ECHO Building RSP interpreter... (debugging module)
gcc --shared -s -O3 -m3dnow -mmmx -msse -msse2 -DSP_EXECUTE_LOG -DVU_EMULATE_SCALAR_ACCUMULATOR_READ -o ../rsp/rsp_dbg.dll ../../rsp/rsp.c

PAUSE

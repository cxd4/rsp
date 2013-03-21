@ECHO OFF
TITLE MinGW Compiler Suite Invocation
CD ..\..\MINGW\BIN\

ECHO CC1.EXE:  Compiling C source code...
GCC.EXE -S -O3 -m3dnow -mabm -maes -msse2 -o ../rsp/rsp.s ../../rsp/rsp.c
ECHO.

ECHO AS.EXE:  Assembling compiled sources...
AS.EXE --statistics -o ../rsp/rsp.o ../rsp/rsp.s
ECHO.

ECHO LD.EXE:  Linking assembled object file...
GCC.EXE --shared -s -O -o ../rsp/rsp.dll ../rsp/rsp.o
PAUSE

@ECHO OFF
TITLE MinGW Compiler Suite Invocation

set MinGW=C:\MinGW
REM set rsp=%USERPROFILE%\rsp
set rsp=%CD%
set obj=%rsp%\obj

set OBJ_LIST=^
%obj%\module.o ^
%obj%\su.o ^
%obj%\vu\vu.o ^
%obj%\vu\multiply.o ^
%obj%\vu\add.o ^
%obj%\vu\select.o ^
%obj%\vu\logical.o ^
%obj%\vu\divide.o

set FLAGS_ANSI=-O3^
 -DPLUGIN_API_VERSION=0x0101^
 -march=native^
 -mstackrealign^
 -Wall^
 -pedantic
set FLAGS_x86=-O3^
 -masm=intel^
 -DPLUGIN_API_VERSION=0x0101^
 -DARCH_MIN_SSE2^
 -march=native^
 -mstackrealign^
 -Wall^
 -pedantic
set C_FLAGS=%FLAGS_x86%

if not exist obj (
mkdir obj
cd obj
mkdir vu
)
cd %MinGW%\bin

ECHO Compiling C source code...
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\module.asm      %rsp%\module.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\su.asm          %rsp%\su.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\vu.asm       %rsp%\vu\vu.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\multiply.asm %rsp%\vu\multiply.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\add.asm      %rsp%\vu\add.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\select.asm   %rsp%\vu\select.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\logical.asm  %rsp%\vu\logical.c
%MinGW%\bin\gcc.exe -S %C_FLAGS% -o %obj%\vu\divide.asm   %rsp%\vu\divide.c
ECHO.

ECHO Assembling compiled sources...
%MinGW%\bin\as.exe --statistics -o %obj%\module.o %obj%\module.asm
%MinGW%\bin\as.exe --statistics -o %obj%\su.o     %obj%\su.asm
%MinGW%\bin\as.exe --statistics -o %obj%\vu\vu.o  %obj%\vu\vu.asm
%MinGW%\bin\as.exe -o %obj%\vu\multiply.o %obj%\vu\multiply.asm
%MinGW%\bin\as.exe -o %obj%\vu\add.o      %obj%\vu\add.asm
%MinGW%\bin\as.exe -o %obj%\vu\select.o   %obj%\vu\select.asm
%MinGW%\bin\as.exe -o %obj%\vu\logical.o  %obj%\vu\logical.asm
%MinGW%\bin\as.exe -o %obj%\vu\divide.o   %obj%\vu\divide.asm
ECHO.

ECHO Linking assembled object files...
%MinGW%\bin\ld.exe --shared -e _DllMain@12 -o %obj%\rspdebug.dll %OBJ_LIST% %MinGW%\lib\libkernel32.a
%MinGW%\bin\strip.exe -o %obj%/rsp.dll %obj%/rspdebug.dll
PAUSE

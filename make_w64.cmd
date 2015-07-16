@ECHO OFF
TITLE MinGW Compiler Suite Invocation

set version=x86_64-5.1.0-win32-seh-rt_v4-rev0
set MinGW="C:\Program Files\mingw-w64\%version%\mingw64"
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
%obj%\vu\divide.o ^
%MinGW%\x86_64-w64-mingw32\lib\libkernel32.a

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
set C_FLAGS=%FLAGS_X86%

if not exist obj (
mkdir obj
cd obj
mkdir vu
)
cd %MinGW%\bin

ECHO Compiling C source code...
gcc -S %C_FLAGS% -o %obj%\module.asm      %rsp%\module.c
gcc -S %C_FLAGS% -o %obj%\su.asm          %rsp%\su.c
gcc -S %C_FLAGS% -o %obj%\vu\vu.asm       %rsp%\vu\vu.c
gcc -S %C_FLAGS% -o %obj%\vu\multiply.asm %rsp%\vu\multiply.c
gcc -S %C_FLAGS% -o %obj%\vu\add.asm      %rsp%\vu\add.c
gcc -S %C_FLAGS% -o %obj%\vu\select.asm   %rsp%\vu\select.c
gcc -S %C_FLAGS% -o %obj%\vu\logical.asm  %rsp%\vu\logical.c
gcc -S %C_FLAGS% -o %obj%\vu\divide.asm   %rsp%\vu\divide.c
ECHO.

ECHO Assembling compiled sources...
as -o %obj%\module.o      %obj%\module.asm
as -o %obj%\su.o          %obj%\su.asm
as -o %obj%\vu\vu.o       %obj%\vu\vu.asm
as -o %obj%\vu\multiply.o %obj%\vu\multiply.asm
as -o %obj%\vu\add.o      %obj%\vu\add.asm
as -o %obj%\vu\select.o   %obj%\vu\select.asm
as -o %obj%\vu\logical.o  %obj%\vu\logical.asm
as -o %obj%\vu\divide.o   %obj%\vu\divide.asm
ECHO.

ECHO Linking assembled object files...
ld --shared -e DllMain -o %obj%\rspdebug.dll %OBJ_LIST%
strip -o %obj%/rsp.dll %obj%/rspdebug.dll
PAUSE

@ECHO OFF
TITLE MinGW Compiler Suite Invocation

REM If you have MinGW on a different drive letter or installed at a custom path
REM (or just not yet installed at all), this build script may not work out of
REM the box for most Windows users.  Alternatives include MinGW-w32 or trying
REM to execute the Unix shell script "make.sh" from Windows 10+ or Git Bash.

REM The following line is the only one you should ever need to change.
set MinGW=C:\MinGW

set lib=%MinGW%\lib
set bin=%MinGW%\bin
set inc=%MinGW%\include

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
cd /D %bin%

ECHO Compiling C source code...
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\module.asm      %rsp%\module.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\su.asm          %rsp%\su.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\vu.asm       %rsp%\vu\vu.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\multiply.asm %rsp%\vu\multiply.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\add.asm      %rsp%\vu\add.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\select.asm   %rsp%\vu\select.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\logical.asm  %rsp%\vu\logical.c
%bin%\gcc.exe -S %C_FLAGS% -o %obj%\vu\divide.asm   %rsp%\vu\divide.c
ECHO.

ECHO Assembling compiled sources...
%bin%\as.exe --statistics -o %obj%\module.o %obj%\module.asm
%bin%\as.exe --statistics -o %obj%\su.o     %obj%\su.asm
%bin%\as.exe --statistics -o %obj%\vu\vu.o  %obj%\vu\vu.asm
%bin%\as.exe -o %obj%\vu\multiply.o %obj%\vu\multiply.asm
%bin%\as.exe -o %obj%\vu\add.o      %obj%\vu\add.asm
%bin%\as.exe -o %obj%\vu\select.o   %obj%\vu\select.asm
%bin%\as.exe -o %obj%\vu\logical.o  %obj%\vu\logical.asm
%bin%\as.exe -o %obj%\vu\divide.o   %obj%\vu\divide.asm
ECHO.

ECHO Linking assembled object files...
%bin%\ld.exe --shared -e _DllMain@12 -o %obj%\rspdebug.dll -L %lib% %OBJ_LIST% -lmsvcrt
%bin%\strip.exe -o %obj%/rsp.dll %obj%/rspdebug.dll
PAUSE

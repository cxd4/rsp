/******************************************************************************\
* Project:  RSP Emulation Table for MIPS R4000 Register-Immediate Operations   *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.11.30                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#include "bltz.h"
#include "bgez.h"
#include "bltzal.h"
#include "bgezal.h"

extern void BLTZ(int rs, signed offset);
extern void BGEZ(int rs, signed offset);
extern void BLTZAL(int rs, signed offset);
extern void BGEZAL(int rs, signed offset);

void reserved_REGIMM(int rs, signed offset)
{
    offset = rs = 0;
    message("REGIMM\nRESERVED", 3);
    return;
}

static void (*SP_REGIMM[32])(int rs, signed offset) = {
    BLTZ,
    BGEZ,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    BLTZAL,
    BGEZAL,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM,
    reserved_REGIMM
};

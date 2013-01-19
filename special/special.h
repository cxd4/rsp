/******************************************************************************\
* Project:  MSP Emulation Table for Register-Encoded Scalar Operations         *
* Creator:  Iconoclast                                                         *
* Release:  2013.01.18                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* Note that falling under the "SPECIAL" primary operation code is not the
 * only way that an instruction can be R-type.  Usually the only other way
 * is via use of the coprocessor operations (COPz, LWCz, SWCz).
 */

#include "add.h"
#include "addu.h"
#include "and.h"
#include "break.h"
#include "jalr.h"
#include "jr.h"
#include "nor.h"
#include "or.h"
#include "sll.h"
#include "sllv.h"
#include "slt.h"
#include "sltu.h"
#include "sra.h"
#include "srav.h"
#include "srl.h"
#include "srlv.h"
#include "sub.h"
#include "subu.h"
#include "xor.h"

void res_000(int rs, int rt, int rd, int sa)
{
    sa = rd = rt = rs = 0;
    message("SPECIAL\nRESERVED", 3);
    return;
}

static void (*SP_SPECIAL[64])(int, int, int, int) = {
    SLL    ,res_000,SRL    ,SRA    ,SLLV   ,res_000,SRLV   ,SRAV   , /* 000 */
    JR     ,JALR   ,res_000,res_000,res_000,BREAK  ,res_000,res_000, /* 001 */
    res_000,res_000,res_000,res_000,res_000,res_000,res_000,res_000, /* 010 */
    res_000,res_000,res_000,res_000,res_000,res_000,res_000,res_000, /* 011 */
    ADD    ,ADDU   ,SUB    ,SUBU   ,AND    ,OR     ,XOR    ,NOR    , /* 100 */
    res_000,res_000,SLT    ,SLTU   ,res_000,res_000,res_000,res_000, /* 101 */
    res_000,res_000,res_000,res_000,res_000,res_000,res_000,res_000, /* 110 */
    res_000,res_000,res_000,res_000,res_000,res_000,res_000,res_000  /* 111 */
}; /* 000     001     010     011     100     101     110     111 */

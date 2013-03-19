/******************************************************************************\
* Project:  SIMD Virtualization Table:  Store Word from Vector Unit (SWC2)     *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

extern void SBV(int vt, int element, signed int offset, int base);
extern void SDV(int vt, int element, signed int offset, int base);
extern void SFV(int vt, int element, signed int offset, int base);
extern void SHV(int vt, int element, signed int offset, int base);
extern void SLV(int vt, int element, signed int offset, int base);
extern void SPV(int vt, int element, signed int offset, int base);
extern void SQV(int vt, int element, signed int offset, int base);
extern void SRV(int vt, int element, signed int offset, int base);
extern void SSV(int vt, int element, signed int offset, int base);
extern void STV(int vt, int element, signed int offset, int base);
extern void SUV(int vt, int element, signed int offset, int base);
extern void SWV(int vt, int element, signed int offset, int base);

#include "swc2/sbv.h"
#include "swc2/ssv.h"
#include "swc2/slv.h"
#include "swc2/sdv.h"
#include "swc2/sqv.h"
#include "swc2/srv.h"
#include "swc2/spv.h"
#include "swc2/suv.h"
#include "swc2/shv.h"
#include "swc2/sfv.h"
#include "swc2/swv.h"
#include "swc2/stv.h"

void res_072(int vt, int element, signed int offset, int base)
{
    base = offset = element = vt = 0;
    message("SWC2\nRESERVED", 3);
    return;
}

static void (*SP_SWC2[32])(int, int, int, int) = {
    SBV    ,SSV    ,SLV    ,SDV    ,SQV    ,SRV    ,SPV    ,SUV    , /* 00 */
    SHV,    SFV    ,SWV    ,STV,    res_072,res_072,res_072,res_072, /* 01 */
    res_072,res_072,res_072,res_072,res_072,res_072,res_072,res_072, /* 10 */
    res_072,res_072,res_072,res_072,res_072,res_072,res_072,res_072  /* 11 */
}; /* 000     001     010     011     100     101     110     111 */

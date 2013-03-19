/******************************************************************************\
* Project:  SIMD Virtualization Table for Load Word to Vector Unit (LWC2)      *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

extern void LBV(int vt, int element, signed int offset, int base);
extern void LDV(int vt, int element, signed int offset, int base);
extern void LFV(int vt, int element, signed int offset, int base);
extern void LHV(int vt, int element, signed int offset, int base);
extern void LLV(int vt, int element, signed int offset, int base);
extern void LPV(int vt, int element, signed int offset, int base);
extern void LQV(int vt, int element, signed int offset, int base);
extern void LRV(int vt, int element, signed int offset, int base);
extern void LSV(int vt, int element, signed int offset, int base);
extern void LTV(int vt, int element, signed int offset, int base);
extern void LUV(int vt, int element, signed int offset, int base);

#include "lwc2/lbv.h"
#include "lwc2/lsv.h"
#include "lwc2/llv.h"
#include "lwc2/ldv.h"
#include "lwc2/lqv.h"
#include "lwc2/lrv.h"
#include "lwc2/lpv.h"
#include "lwc2/luv.h"
#include "lwc2/lhv.h"
#include "lwc2/lfv.h"
#include "lwc2/ltv.h"

void res_062(int vt, int element, signed int offset, int base)
{
    base = offset = element = vt = 0;
    message("LWC2\nRESERVED", 3);
    return;
}

static void (*SP_LWC2[32])(int, int, int, int) = {
    LBV    ,LSV    ,LLV    ,LDV    ,LQV    ,LRV    ,LPV    ,LUV    , /* 00 */
    LHV,    LFV    ,res_062,LTV,    res_062,res_062,res_062,res_062, /* 01 */
    res_062,res_062,res_062,res_062,res_062,res_062,res_062,res_062, /* 10 */
    res_062,res_062,res_062,res_062,res_062,res_062,res_062,res_062  /* 11 */
}; /* 000     001     010     011     100     101     110     111 */

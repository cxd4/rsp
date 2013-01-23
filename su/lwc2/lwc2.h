/******************************************************************************\
* Project:  SIMD Virtualization Table for Load Word to Vector Unit (LWC2)      *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.26                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#include "lbv.h"
#include "lsv.h"
#include "llv.h"
#include "ldv.h"
#include "lqv.h"
#include "lrv.h"
#include "lpv.h"
#include "luv.h"
#include "lhv.h"
// #include "lfv.h"
#include "ltv.h"

extern void LBV(int vt, int element, signed offset, int base);
extern void LSV(int vt, int element, signed offset, int base);
extern void LLV(int vt, int element, signed offset, int base);
extern void LDV(int vt, int element, signed offset, int base);
extern void LQV(int vt, int element, signed offset, int base);
extern void LRV(int vt, int element, signed offset, int base);
extern void LPV(int vt, int element, signed offset, int base);
extern void LUV(int vt, int element, signed offset, int base);
extern void LHV(int vt, int element, signed offset, int base);
// extern void LFV(int vt, int element, signed offset, int base);
extern void LTV(int vt, int element, signed offset, int base);

void reserved_LWC2(int vt, int element, signed offset, int base)
{
    base = offset = element = vt = 0;
    message("LWC2\nRESERVED", 3);
    return;
}

static void (*SP_LWC2[32])(int vt, int element, int offset, int base) = {
    LBV,
    LSV,
    LLV,
    LDV,
    LQV,
    LRV,
    LPV,
    LUV,
    LHV,
    reserved_LWC2, // LFV,
    reserved_LWC2,
    LTV,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2,
    reserved_LWC2
};

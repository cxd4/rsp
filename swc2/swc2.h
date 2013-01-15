/******************************************************************************\
* Project:  SIMD Virtualization Table for Store Word from Vector Unit (LWC2)   *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

#include "sbv.h"
#include "ssv.h"
#include "slv.h"
#include "sdv.h"
#include "sqv.h"
#include "srv.h" /* "Resident Evil 2" only? */
#include "spv.h"
#include "suv.h"
#include "shv.h" /* "Resident Evil 2" only? */
#include "sfv.h"
// #include "swv.h"
#include "stv.h"

extern void SBV(int vt, int element, signed offset, int base);
extern void SSV(int vt, int element, signed offset, int base);
extern void SLV(int vt, int element, signed offset, int base);
extern void SDV(int vt, int element, signed offset, int base);
extern void SQV(int vt, int element, signed offset, int base);
extern void SRV(int vt, int element, signed offset, int base);
extern void SPV(int vt, int element, signed offset, int base);
extern void SUV(int vt, int element, signed offset, int base);
extern void SHV(int vt, int element, signed offset, int base);
extern void SFV(int vt, int element, signed offset, int base);
// extern void SWV(int vt, int element, signed offset, int base);
extern void STV(int vt, int element, signed offset, int base);

void reserved_SWC2(int vt, int element, signed offset, int base)
{
    base = offset = element = vt = 0;
    message("SWC2\nRESERVED", 3);
    return;
}

static void (*SP_SWC2[32])(int vt, int element, int offset, int base) = {
    SBV,
    SSV,
    SLV,
    SDV,
    SQV,
    SRV, // lol, even if I set this one to SQV RE2 is still stable
    SPV,
    SUV,
    SHV,
    SFV,
    reserved_SWC2, // SWV, // never seen this get used yet
    STV,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2,
    reserved_SWC2
};

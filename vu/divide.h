/******************************************************************************\
* Project:  Instruction Mnemonics for Vector Unit Computational Divides        *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.09                                                         *
* License:  CC0 Public Domain Dedication                                       *
*                                                                              *
* To the extent possible under law, the author(s) have dedicated all copyright *
* and related and neighboring rights to this software to the public domain     *
* worldwide. This software is distributed without any warranty.                *
*                                                                              *
* You should have received a copy of the CC0 Public Domain Dedication along    *
* with this software.                                                          *
* If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.             *
\******************************************************************************/

#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "vu.h"

VECTOR_EXTERN
    VRCP   (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VRCPL  (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VRCPH  (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VMOV   (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VRSQ   (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VRSQL  (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VRSQH  (v16 vd, v16 vs, v16 vt);
VECTOR_EXTERN
    VNOP   (v16 vd, v16 vs, v16 vt);

extern int DivIn;
extern int DivOut;

extern int DPH;

#endif

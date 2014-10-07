/******************************************************************************\
* Authors:  Iconoclast                                                         *
* Release:  2013.11.26                                                         *
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
#include "vu.h"
#include "divrom.h"

VECTOR_OPERATION VRSQH(v16 vd, v16 vs, v16 vt)
{
    const int result = (inst & 0x000007FF) >>  6;
    const int source = (inst & 0x0000FFFF) >> 11;
    const int target = (inst >> 16) & 31;
    const unsigned int element = (inst >> 21) & 0x7;

    vs = vd; /* unused */
    DivIn = VR[target][element] << 16;
#ifdef ARCH_MIN_SSE2
    *(v16 *)VACC_L = vt;
#else
    vector_copy(VACC_L, vt);
#endif
    VR[result][source & 07] = DivOut >> 16;
    DPH = SP_DIV_PRECISION_DOUBLE;
#ifdef ARCH_MIN_SSE2
    vd = *(v16 *)VR[result];
#else
    vector_copy(vd, VR[result]);
#endif
    return (vd);
}

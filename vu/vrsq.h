#include "vu.h"

static void VRSQ(int vd, int de, int vt, int e)
{
    e = vt = de = vd = 0;
    message("VRSQ\nUnimplemented instruction.", 3);
    DPH = 0;
    return;
}

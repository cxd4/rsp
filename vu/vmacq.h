#include "vu.h"

static const void VMACQ(int vd, int vs, int vt, int e)
{
    e = vt = vs = vd = 0;
    message("VMACQ\nUnimplemented instruction.", 3);
    return;
}

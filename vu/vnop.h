#include "vu.h"

static void VNOP(int unused_sa, int unused_rd, int unused_rt, int unused)
{
    unused_sa = unused_rd = unused_rt = unused = 0;
    message("VNOP", 3);
    return;
}

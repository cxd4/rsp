#include "vu.h"

static void VNOP(int unused_sa, int unused_rd, int unused_rt, int unused)
{
    unused = unused_rt = unused_rd = unused_sa = 1;
    message("VNOP", unused);
    return;
}

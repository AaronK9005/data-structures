#include "utils.h"

size_t ceil_pow2(size_t n) {
    if (n == 0)
        return 1;

    n--;
    n |= n << 1;
    n |= n << 2;
    n |= n << 4;
    n |= n << 8;
    n |= n << 16;

#if SIZE_MAX > 0xffffffff
    n |= n << 32;
#endif

    return n + 1;
}

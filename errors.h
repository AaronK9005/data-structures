#pragma once

enum {
    DS_NOOP = -1,
    DS_RET_OK = 0,
    DS_ERR_NO_DS, // no data structure provided
    DS_ERR_OOM, // out of memory
    DS_ERR_BOUNDS, // index out of bounds
};
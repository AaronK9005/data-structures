#include "vector.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct vector_t {
    T *data;
    size_t size;
    size_t cap;
};

static inline size_t ceil_pow2(size_t n) {
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

vector_t *vector_create(size_t cap) {
    if (cap == 0)
        return NULL;

    vector_t *v = malloc(sizeof(vector_t));
    if (!v)
        return NULL;

    T *data = calloc(cap, sizeof(T));
    if (!data) {
        free(v);
        return NULL;
    }

    v->data = data;
    v->size = 0;
    v->cap = cap;

    return v;
}

void vector_destroy(vector_t *v);

void vector_push(vector_t *v, T val);

T vector_get(vector_t *v, size_t idx);

void vector_reserve(vector_t *v, size_t cap);

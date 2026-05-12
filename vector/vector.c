#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "../errors.h"
#include "../utils.h"
#include "vector.h"

struct vector_t {
    T *data;
    size_t size;
    size_t cap;
};

vector_t *vector_grow(vector_t *v) {
    if (v) {
        const int factor = 2;
        T *data = realloc(v->data, v->cap * factor);
        if (!data) return NULL;
        v->data = data;
        v->cap *= factor;
    }
    return v;
}

vector_t *vector_create(size_t cap) {
    if (cap == 0) return NULL;

    cap = ceil_pow2(cap);

    vector_t *v = malloc(sizeof(vector_t));
    if (!v) return NULL;

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

void vector_destroy(vector_t *v) {
    if (!v) return;

    if (v->data) {
        free(v->data);
        v->data = NULL;
    }

    free(v);
}

int vector_push(vector_t *v, T val) {
    if (!v) return DS_ERR_NO_DS;

    if (v->size >= v->cap) {
        if (!vector_grow(v)) return DS_ERR_OOM;
    }

    v->data[v->size++] = val;

    return DS_RET_OK;
}

int vector_get(vector_t *v, size_t idx, T *dest) { return DS_NOOP; }

int vector_reserve(vector_t *v, size_t cap) { return DS_NOOP; }

#pragma once

#include <stddef.h>

typedef int T;
typedef struct vector_t vector_t;

vector_t *vector_create(size_t cap);

void vector_destroy(vector_t *v);

int vector_push(vector_t *v, T val);

int vector_get(vector_t *v, size_t idx, T* dest);

int vector_reserve(vector_t *v, size_t cap);

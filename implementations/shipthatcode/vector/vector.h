#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void  *data;      /* raw block holding cap * elem_size bytes */
    size_t len;       /* number of elements currently stored */
    size_t cap;       /* number of elements that fit before a resize */
    size_t elem_size; /* sizeof one element, in bytes */
} Vector;

Vector vec_create(size_t elem_size, size_t cap);
void   vec_free(Vector *v);
void  *vec_at(const Vector *v, size_t i);
int    vec_reserve(Vector *v, size_t want);
int    vec_push(Vector *v, const void *elem);
int    vec_pop(Vector *v, void *out);

#endif /* VECTOR_H */

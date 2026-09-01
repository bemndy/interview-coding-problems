/*
 * vector.c - a growable, type-agnostic array (like C++ std::vector) in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

/*
 * vec_create - allocate a new vector with room for `cap` elements.
 *
 * @elem_size: size in bytes of a single element (e.g. sizeof(int)). Must be > 0.
 * @cap:       initial capacity in elements. May be 0.
 *
 * Return: a Vector with len == 0. On allocation failure or invalid arguments,
 *         returns a zeroed Vector (data == NULL, cap == 0).
 */
Vector vec_create(size_t elem_size, size_t cap)
{
    Vector v = {0};

    if (elem_size == 0) {
        return v;
    }

    v.elem_size = elem_size;
    v.cap = cap;
    v.data = malloc(elem_size * cap);
    if (v.data == NULL) {
        fprintf(stderr, "malloc failed\n");
        v.cap = 0;
    }

    return v;
}

/*
 * vec_free - release the vector's block and zero it out.
 */
void vec_free(Vector *v)
{
    free(v->data);
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}

/*
 * vec_at - return a pointer to element `i`.
 *
 * Return: pointer to the element, or NULL if i is out of range (i >= len).
 */
void *vec_at(const Vector *v, size_t i)
{
    if (i >= v->len) {
        return NULL;
    }

    return (char*)v->data + (i * v->elem_size);
}

/*
 * vec_reserve - ensure capacity for at least `want` elements.
 *
 * Return: 1 on success, 0 on allocation failure (vector left untouched).
 */
int vec_reserve(Vector *v, size_t want)
{
    if (v->cap == 0) {
        v->cap = 1;
        v->data = malloc(v->cap * v->elem_size);
        if (v->data == NULL) {
            fprintf(stderr, "malloc failed\n");
            v->cap = 0;
            return 0;
        }
    }
    while (want >= v->cap) {
        size_t new_cap = v->cap * 2;
        void *new_data = realloc(v->data, new_cap * v->elem_size);
        if (new_data == NULL) {
            fprintf(stderr, "realloc failed\n");
            return 0;
        }
        v->data = new_data;
        v->cap = new_cap;
    }
    return 1;
}

/*
 * vec_push - append one element, copying elem_size bytes from `elem`.
 *
 * Return: 1 on success, 0 if growth failed.
 */
int vec_push(Vector *v, const void *elem)
{
    if (vec_reserve(v, v->len + 1) == 1) {
        memcpy((char*)v->data + v->len * v->elem_size, elem, v->elem_size);
        v->len++;
    }
    else {
        return 0;
    }
    return 1;
}

/*
 * vec_pop - remove the last element, optionally copying it into `out`.
 *
 * @out: destination for the removed element, or NULL to discard it.
 *
 * Return: 1 on success, 0 if the vector was empty.
 */
int vec_pop(Vector *v, void *out)
{
    if (v->len == 0) { return 0; }

    size_t last_index = v->len - 1;
    if (out != NULL) {
        memcpy(out, (char*)v->data + last_index * v->elem_size, v->elem_size);
    }
    v->len--;

    return 1;
}

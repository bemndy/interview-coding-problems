/*
 * vector.c - a growable, type-agnostic array (like C++ std::vector) in C.
 *
 * Build: cc -Wall -Wextra -g -o vector vector.c
 *
 * Fill in every TODO. The tests in main() should all pass when you're done.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

typedef struct {
    void  *data;      /* raw block holding cap * elem_size bytes */
    size_t len;       /* number of elements currently stored */
    size_t cap;       /* number of elements that fit before a resize */
    size_t elem_size; /* sizeof one element, in bytes */
} Vector;

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
    (void)elem_size;
    (void)cap;

    if (elem_size == 0) {
        return v;
    }

    if (cap < 0) {
        fprintf(stderr, "invalid argument: cap cannot be negative\n");
        return v;
    }
    if (elem_size <= 0) {
        fprintf(stderr, "invalid argument: elem_size must be positive\n");
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
    (void)v;
    free(v->data);
    v->data = NULL;
    v->len = 0;
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
    (void)v; (void)i;

    return (char*)v->data + (i * v->elem_size); 
}

/*
 * vec_reserve - ensure capacity for at least `want` elements.
 *
 * Return: 1 on success, 0 on allocation failure (vector left untouched).
 */
int vec_reserve(Vector *v, size_t want)
{
    (void)v; (void)want;
    return 0;
}

/*
 * vec_push - append one element, copying elem_size bytes from `elem`.
 *
 * Return: 1 on success, 0 if growth failed.
 */
int vec_push(Vector *v, const void *elem)
{
    /* TODO */
    (void)v; (void)elem;
    return 0;
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
    /* TODO */
    (void)v; (void)out;
    return 0;
}

/* ------------------------------------------------------------------ *
 * Tests. Don't edit these -- make them pass.
 * ------------------------------------------------------------------ */

static void test_ints(void)
{
    Vector v = vec_create(sizeof(int), 0);
    assert(v.elem_size == sizeof(int));
    assert(v.len == 0);

    for (int i = 0; i < 100; i++)
        assert(vec_push(&v, &i) == 1);

    assert(v.len == 100);
    assert(v.cap >= 100);

    for (int i = 0; i < 100; i++)
        assert(*(int *)vec_at(&v, (size_t)i) == i);

    assert(vec_at(&v, 100) == NULL);   /* out of range */

    int got = -1;
    assert(vec_pop(&v, &got) == 1);
    assert(got == 99);
    assert(v.len == 99);

    vec_free(&v);
    assert(v.data == NULL && v.len == 0 && v.cap == 0);
    printf("test_ints: ok\n");
}

static void test_structs(void)
{
    /* Proves the vector really is type-agnostic. */
    typedef struct { double x, y; } Point;

    Vector v = vec_create(sizeof(Point), 2);
    Point a = {1.0, 2.0}, b = {3.0, 4.0}, c = {5.0, 6.0};

    assert(vec_push(&v, &a) == 1);
    assert(vec_push(&v, &b) == 1);
    assert(vec_push(&v, &c) == 1);     /* forces a resize */

    Point *p = vec_at(&v, 2);
    assert(p->x == 5.0 && p->y == 6.0);

    p = vec_at(&v, 0);                 /* old data survived the realloc */
    assert(p->x == 1.0 && p->y == 2.0);

    vec_free(&v);
    printf("test_structs: ok\n");
}

static void test_empty_pop(void)
{
    Vector v = vec_create(sizeof(char), 0);
    assert(vec_pop(&v, NULL) == 0);
    vec_free(&v);

    Vector bad = vec_create(0, 10);    /* invalid elem_size */
    assert(bad.data == NULL && bad.cap == 0);

    printf("test_empty_pop: ok\n");
}

int main(void)
{
    test_ints();
    test_structs();
    test_empty_pop();
    printf("all tests passed\n");
    return 0;
}

/*
 * test_vector.c - tests for vector.c. Don't edit these -- make them pass.
 */

#include <stdio.h>
#include <assert.h>
#include "vector.h"

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
    printf("running tests...\n");
    test_ints();
    test_structs();
    test_empty_pop();
    printf("all tests passed\n");
    return 0;
}

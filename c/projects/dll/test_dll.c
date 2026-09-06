/*
 * test_dll.c - tests for dll.c. Don't edit these -- make them pass.
 */

#include <stdio.h>
#include <assert.h>
#include "dll.h"

static void test_push_pop_ends(void)
{
    DLL l = dll_create();
    assert(l.len == 0 && l.head == NULL && l.tail == NULL);

    assert(dll_push_back(&l, 1) == 1);
    assert(dll_push_back(&l, 2) == 1);
    assert(dll_push_front(&l, 0) == 1);
    /* list: 0 1 2 */
    assert(l.len == 3);
    assert(l.head->value == 0);
    assert(l.tail->value == 2);
    assert(l.head->next->value == 1);
    assert(l.tail->prev->value == 1);
    assert(l.head->prev == NULL);
    assert(l.tail->next == NULL);

    int got;
    assert(dll_pop_front(&l, &got) == 1 && got == 0);
    assert(dll_pop_back(&l, &got) == 1 && got == 2);
    assert(l.len == 1);
    assert(l.head == l.tail);
    assert(l.head->value == 1);

    assert(dll_pop_front(&l, &got) == 1 && got == 1);
    assert(l.len == 0 && l.head == NULL && l.tail == NULL);

    assert(dll_pop_front(&l, &got) == 0);
    assert(dll_pop_back(&l, &got) == 0);

    dll_free(&l);
    printf("test_push_pop_ends: ok\n");
}

static void test_at_and_arbitrary_insert_remove(void)
{
    DLL l = dll_create();
    for (int i = 0; i < 5; i++)
        assert(dll_push_back(&l, i));      /* 0 1 2 3 4 */

    for (int i = 0; i < 5; i++)
        assert(dll_at(&l, (size_t)i)->value == i);
    assert(dll_at(&l, 5) == NULL);

    assert(dll_insert_at(&l, 2, 99) == 1);  /* 0 1 99 2 3 4 */
    assert(l.len == 6);
    assert(dll_at(&l, 2)->value == 99);
    assert(dll_at(&l, 1)->next->value == 99);
    assert(dll_at(&l, 3)->prev->value == 99);

    int got;
    assert(dll_remove_at(&l, 2, &got) == 1 && got == 99); /* back to 0 1 2 3 4 */
    assert(l.len == 5);
    for (int i = 0; i < 5; i++)
        assert(dll_at(&l, (size_t)i)->value == i);

    assert(dll_insert_at(&l, 0, -1) == 1); /* -1 0 1 2 3 4 */
    assert(l.head->value == -1);
    assert(l.head->prev == NULL);

    assert(dll_insert_at(&l, l.len, 100) == 1); /* ... 4 100 */
    assert(l.tail->value == 100);
    assert(l.tail->next == NULL);

    assert(dll_insert_at(&l, l.len + 1, 0) == 0); /* out of range */
    assert(dll_remove_at(&l, l.len, &got) == 0);  /* out of range */

    dll_free(&l);
    printf("test_at_and_arbitrary_insert_remove: ok\n");
}

static void test_remove_ends_via_remove_at(void)
{
    DLL l = dll_create();
    for (int i = 0; i < 3; i++)
        assert(dll_push_back(&l, i));  /* 0 1 2 */

    int got;
    assert(dll_remove_at(&l, 0, &got) == 1 && got == 0); /* 1 2 */
    assert(l.head->value == 1 && l.head->prev == NULL);

    assert(dll_remove_at(&l, l.len - 1, &got) == 1 && got == 2); /* 1 */
    assert(l.tail->value == 1 && l.tail->next == NULL);
    assert(l.head == l.tail);

    dll_free(&l);
    printf("test_remove_ends_via_remove_at: ok\n");
}

int main(void)
{
    printf("running tests...\n");
    test_push_pop_ends();
    test_at_and_arbitrary_insert_remove();
    test_remove_ends_via_remove_at();
    printf("all tests passed\n");
    return 0;
}

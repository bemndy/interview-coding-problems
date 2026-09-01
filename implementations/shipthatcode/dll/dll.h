#ifndef DLL_H
#define DLL_H

#include <stddef.h>

/*
 * Doubly linked list of ints. Explicit prev/next pointers, plus a
 * head/tail-tracking list struct so push/pop at either end is O(1).
 */

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t len;
} DLL;

DLL    dll_create(void);
void   dll_free(DLL *list);            /* full traversal cleanup, zero leaks */

int    dll_push_front(DLL *list, int value);
int    dll_push_back(DLL *list, int value);
int    dll_pop_front(DLL *list, int *out);
int    dll_pop_back(DLL *list, int *out);

/* insert `value` so it becomes the element at index `idx` (0 == head). */
int    dll_insert_at(DLL *list, size_t idx, int value);
/* remove the element at index `idx`, optionally copying it into `out`. */
int    dll_remove_at(DLL *list, size_t idx, int *out);

Node  *dll_at(const DLL *list, size_t idx);

#endif /* DLL_H */

/*
 * dll.c - doubly linked list of ints. Fill in the TODOs.
 */

#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

/*
 * dll_create - return an empty list (head == tail == NULL, len == 0).
 */
DLL dll_create(void)
{
    DLL list = {0};
    /* TODO */
    list.head = NULL;
    list.tail = NULL;
    list.len = 0;
    return list;
}

/*
 * dll_free - walk the whole list freeing every node, then reset the
 * list struct to empty. This is the leak-check function -- run under
 * a leak checker (e.g. `leaks`, valgrind) and confirm zero bytes leaked.
 */
void dll_free(DLL *list)
{
    /* TODO: traverse from head, free each node, reset head/tail/len */

    // create pointer to current head
    Node *curr = list->head;

    // transverse pointer until we reach null pointer (tail's next, which would be freed, original head) 
    while (curr != NULL) {
        // prepare values of struct
        curr->value = 0;
        curr->prev = NULL;

        // create pointer to next node, while preparing pointers in struct to be freed 
        Node *next = curr->next;
        curr->next = NULL;

        // free the current pointer
        free(curr);

        // iterate
        curr = curr->next;
    }
}

/*
 * dll_push_front - insert `value` as the new head. O(1).
 * Return: 1 on success, 0 on allocation failure.
 */
int dll_push_front(DLL *list, int value)
{
    /* TODO */

    // allocate the pointer of type Node, the size of the node struct on heap
    Node *new = (Node*)malloc(sizeof(Node));
    if (new == NULL) { return 0; }

    // make current node point to corresponding nodes
    new->value = value;

    if (list->head) {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    } else {
        list->head = new;
    }
    if (!list->tail) {
        list->tail = new;
    } 
    list->len++;

    return 1;
}

/*
 * dll_push_back - insert `value` as the new tail. O(1).
 * Return: 1 on success, 0 on allocation failure.
 */
int dll_push_back(DLL *list, int value)
{
    /* TODO */

    //reversed logic for push back
    Node *new = (Node*)malloc(sizeof(Node));
    if (new == NULL) { return 0; }

    new->value = value;

    if (list->tail) {
        new->prev = list->tail;
        list->tail->next = new;
        list->tail = new;
    } else {
        list->tail = new;
    }

    if (!list->head) {
        list->head = new;
    }
    list->len++;


   return 1;
}

/*
 * dll_pop_front - remove the head, optionally copying its value into `out`.
 * Return: 1 on success, 0 if the list was empty.
 */
int dll_pop_front(DLL *list, int *out)
{
    /* TODO */
    if (list) {
        *out = list->head->value;
    } else { return 0; }

    Node *curr = list->head;

    if (curr->next) {
        curr->next->prev = list->tail;
    }

    list->head = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
    curr->value = 0;
    free(curr);
    list->len--; 

    return 1;
}

/*
 * dll_pop_back - remove the tail, optionally copying its value into `out`.
 * Return: 1 on success, 0 if the list was empty.
 */
int dll_pop_back(DLL *list, int *out)
{
    /* TODO */
    if (list) {
        *out = list->tail->value;
    } else { return 0; }

    Node *curr = list->tail;

    if (curr->prev) {
        curr->prev->next = list->head;
    }

    list->tail = curr->prev;
    curr->prev = NULL;
    curr->next = NULL;
    curr->value = 0;
    free(curr); 
    list->len--; 

    return 1;
}

/*
 * dll_at - return the node at position `idx` (0-indexed from head), or
 * NULL if idx >= len. Feel free to optimize by walking from whichever
 * end is closer.
 */
Node *dll_at(const DLL *list, size_t idx)
{
    /* TODO */
    return NULL;
}

/*
 * dll_insert_at - insert `value` so it lands at index `idx`.
 * idx == 0 behaves like push_front; idx == len behaves like push_back.
 * Return: 1 on success, 0 on invalid idx (> len) or allocation failure.
 */
int dll_insert_at(DLL *list, size_t idx, int value)
{
    /* TODO */
    return 0;
}

/*
 * dll_remove_at - remove the element at index `idx`, optionally copying
 * its value into `out`.
 * Return: 1 on success, 0 on invalid idx (>= len).
 */
int dll_remove_at(DLL *list, size_t idx, int *out)
{
    /* TODO */
    return 0;
}

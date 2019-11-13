#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

void __debug_print(struct list* p) {
    /**
     * __debug_print - print the address / next value / prev value 
     *                 of all pointers in the linked list
     * 
     * p: the list head, can be an arbitrary element in the list
     */
    struct list* q = p;
    do {
        printf("{\n");
        printf("\tCurr Address: %zx\n", (size_t) q);
        printf("\tNext Address: %zx\n", (size_t) q->next);
        printf("\tPrev Address: %zx\n", (size_t) q->prev);
        printf("}\n");
        q = q->next;
    } while (q != p);
}

void __internal_new_list(struct list* head) {
    /**
     * __internal_new_list - initialize a doubly linked list within a structure
     * 
     * head: the first element in the doubly linked list
     */
    head->prev = head;
    head->next = head;
    return;
}

void __internal_insert_list_after(struct list* curr, struct list* insertion) {
    /**
     * __internal_insert_list_after - insert an element after the destiny element
     * 
     * curr     : the list location to be inserted after
     * insertion: the element to insert into the list
     */
    curr->next->prev = insertion;
    insertion->next = curr->next;
    curr->next = insertion;
    insertion->prev = curr;
    return;
}

void __internal_remove_list(struct list* curr, long offset) {
    /**
     * __internal_remove_list - remove an element from the list
     * 
     * curr  : the element to be removed
     * offset: the offset of doubly linked list within the struct
     */
    if (curr->next != curr) { 
        // trim the list only if there exist element
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    // free current pointer
    free((void *)((long) curr - offset));
    return;
}

int __internal_list_size(struct list *head) {
    /**
     * __internal_list_size - fetch the size of the list
     * 
     * head  : an arbitrary list element
     * return: the size of the doubly linked list
     */
    int size = 1;
    struct list* p = head->next;

    while (p != head) {
        p = p->next;
        size++;
    }

    return size;
}

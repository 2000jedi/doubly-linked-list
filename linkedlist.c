#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

void __debug_print(struct list* p) {
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
    head->prev = head;
    head->next = head;
    return;
}

void __internal_insert_list_after(struct list* curr, struct list* insertion) {
    curr->next->prev = insertion;
    insertion->next = curr->next;
    curr->next = insertion;
    insertion->prev = curr;
    return;
}

void __internal_remove_list(struct list* curr, long offset) {
    if (curr->next != curr) { 
        // trim the list only if there exist element
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    // free current pointer
    printf("Freeing Address %zx\n", (size_t)((long) curr));
    free((void *)((long) curr - offset));
    return;
}

int __internal_list_size(struct list* head) {
    int size = 1;
    struct list* p = head->next;

    while (p != head) {
        p = p->next;
        size++;
    }

    return size;
}
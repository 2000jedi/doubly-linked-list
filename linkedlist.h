#pragma once

#include <stddef.h>

#define list_new(x, structure, name) (__internal_new_list(&(x->name)))
#define list_get(x, structure, name) ((structure *)((long)(x) - (long)offsetof(structure, name)))
#define list_insert(curr, next, structure, name) __internal_insert_list_after(&((curr)->name), &((next)->name))
#define list_remove(curr, structure, name) __internal_remove_list(curr, offsetof(structure, name))
#define list_size(curr, struct, name) __internal_list_size(&(curr->name))
#define list_iter(iter, curr, structure, name, code) {\
    struct list *__list_iterator = curr;\
    do {\
        iter = list_get(__list_iterator, structure, name);\
        code\
        __list_iterator = __list_iterator->next;\
    } while (__list_iterator != curr);\
}

struct list {
    struct list *prev, *next;
};

extern void __internal_new_list(struct list* head); 
extern void __internal_insert_list_after(struct list* curr, struct list* insertion);
extern void __internal_remove_list(struct list* curr, long offset);
extern int __internal_list_size(struct list* head);

// extern void __debug_print(struct list* p);

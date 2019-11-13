#pragma once

#include <stddef.h>

#define list_new(curr, structure, name) (__internal_new_list(&(curr->name)))
#define list_get(curr, structure, name) ((structure *)((long)(curr) - (long)offsetof(structure, name)))
#define list_insert(curr, next, structure, name) __internal_insert_list_after(&((curr)->name), &((next)->name))
#define list_remove(curr, structure, name) __internal_remove_list(curr, offsetof(structure, name))
#define list_size(curr, structure, name) __internal_list_size(&(curr->name))
#define list_iter(iter, curr, structure, name, code) {\
    struct list *__list_iterator = curr;\
    do {\
        iter = list_get(__list_iterator, structure, name);\
        code\
        __list_iterator = __list_iterator->next;\
    } while (__list_iterator != curr);\
}

struct list {
    /**
     * struct list - the doubly linked list structure
     * 
     * The doubly linked list forms a closed ring that the 'first' and 'last' element are  
     * connected through pointers.
     * The structure has no defined first element. Every element can be used as a first el-
     * ment and can use it to iterate through the entire list.
     * Note that if there is no element in the doubly linked list, the list itself cease to
     * exist.
     * 
     * To use the list, define a struct list element in the structure that you wish to be  
     * doubly linked, then use macro functions to operate the list.
     */
    struct list *prev, *next; /* the previous and next pointer in the doubly linked list */
};

extern void __internal_new_list(struct list* head); 
extern void __internal_insert_list_after(struct list* curr, struct list* insertion);
extern void __internal_remove_list(struct list* curr, long offset);
extern int __internal_list_size(struct list* head);

// extern void __debug_print(struct list* p);

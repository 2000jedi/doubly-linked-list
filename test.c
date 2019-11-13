#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

struct Integer{
    int c;
    struct list l;
} *int1, *int2, *int3;

int main(int argc, char** argv) {
    int1 = malloc(sizeof(struct Integer));
    printf("Addr of int1: %zx\n", (size_t) int1);
    int1->c = 1;

    int2 = malloc(sizeof(struct Integer));
    printf("Addr of int2: %zx\n", (size_t) int2);
    int2->c = 2;

    int3 = malloc(sizeof(struct Integer));
    printf("Addr of int3: %zx\n", (size_t) int3);
    int3->c = 3;

    list_new(int1, Integer, l);
    list_insert(int1, int2, struct Integer, l);
    list_insert(int2, int3, struct Integer, l);

    printf("Testing Iterator\n");
    int sum = 0;
    struct Integer *iter;
    list_iter(iter, &(int1->l), struct Integer, l, {
        sum += iter->c;
    })
    printf("Sum of Integers: %d\n", sum);
    
    printf("Addr of ptr int1->l.next: %zx\n", (size_t) int1->l.next);
    printf("Address of list_get for int1->l.next: %zx\n", (size_t) list_get(int1->l.next, struct Integer, l));

    printf("Integer in int1->l.next: %d\n", list_get(int1->l.next, struct Integer, l)->c);
    printf("List Size: %d\n", list_size(int1, struct Integer, l));

    printf("Remove int1->l.next\n");
    list_remove(int1->l.next, struct Integer, l);

    printf("Integer in int1->l.next: %d\n", list_get(int1->l.next, struct Integer, l)->c);
    printf("List Size: %d\n", list_size(int1, struct Integer, l));
    printf("Remove int1->l\n");
    list_remove(&(int1->l), struct Integer, l);

    printf("List Size: %d\n", list_size(int3, struct Integer, l));
    printf("Remove int3->l\n");
    list_remove(&(int3->l), struct Integer, l);
    return 0;
}
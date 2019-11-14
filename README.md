# doubly-linked-list
A Doubly Linked List library written in C. It is designed mainly due to lack of generic in C and a feature of this doubly linked list is its easiness to implement. Everything needed is to insert a `struct list` variable inside the struct that is designed to be doubly linked. The implementation is similar to the linked list on the linux kernel, and is now available to use outside kernel programming.

# Methods

* `list_new`: to initialize a list.
* `list_get`: to get the linked struct element given the `struct list`.
* `list_insert`: to insert a new element after the current element.
* `list_remove`: to remove the current element from the list and recycle its memory.
* `list_size`: to get the number of elements in the linked list.
* `list_iter`: to loop through every element in the list.

# To-Do's

1. Implement a `list_swap` method that can swap list elements. This allows the doubly linked list to be used by multiple threads / processes without using semaphore to lock its read / write.
2. Use doubly-linked-list to implement a stack and a queue.

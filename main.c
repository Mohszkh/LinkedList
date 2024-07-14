#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


int main(int argc, char const *argv[])
{
    /* Entry point of the program is here. */
    // Creates a linked list with 1 node that stores the number 1
    struct node *MyLinkedList = create_ll(1);
    // Recursively adds numbers from 2 to 100 to the linked list
    for (size_t i = 2; i <= 100; i++){
        append_node(MyLinkedList, i);
    }
    // Prints the linked list
    print_ll(MyLinkedList);
    // Removes the last node from the linked list, and frees the memory allocated to it
    remove_last(MyLinkedList);
    print_ll(MyLinkedList);
    // Destroys the linked list and frees all the memory that was allocated to it, Thus making MyLinkedList a dangling pointer.
    // MyLinkedList shouldn't be used unless it is reassigned to a new memory location, undefined behaviour will ensue if it is used.
    destroy_ll(MyLinkedList);
    // Pauses the program so that the terminal doesn't close immediately after startup
    getchar();

    return 0;
}
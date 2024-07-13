#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define DATA_TYPE int
#define FORMAT_SPECIFIER_FUNC(x) #x
#define FORMAT_SPECIFIER FORMAT_SPECIFIER_FUNC(%d)

struct node {
    DATA_TYPE data;
    struct node *next;
};

/*Creates and initializes a linked list with the data it was given*/
struct node *create_ll(DATA_TYPE data){
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}
/*  Given a pointer to the first node in a linked list and some data, It appends a node onto the linked list with the data it was provided with.
*   Returns true if the node was appended successfully and false if an error occured.
*/
bool append_node(struct node * first_node , DATA_TYPE data){
    struct node *current_node;
    current_node = first_node;
    while(true){
        if ((current_node->next) == NULL){
            // reached the final node in the linked list.
            // thus we will allocate memory for another node and set the next pointer of this node to point to the another node.
            struct node *new_node;
            new_node = malloc(sizeof(struct node));
            if (new_node == NULL){return false;}
            current_node->next = new_node;
            // Initialize the new node.
            new_node->data = data;
            new_node->next = NULL;
            return true;
        } else{
            current_node = (current_node->next);
        }
    }
}

/*  Given a pointer to the first node in a linked list. It recursively goes over the list and deletes all the nodes, freeing all the memory which was allocated to the linked list in the process
    returns true if the operation was successful and false if something went wrong.
*/
bool destroy_ll(struct node * first_node){
    struct node * current_node;
    current_node = first_node;
    while (true){
        if ((current_node->next) == NULL){
            // The final node in the list has been reached.
            // Delete the node and exit the while loop.
            free(current_node);
            return true;
        } else {
            // temporarily store the next element inside the current_node before freeing the memory and accessing the next node.
            struct node * future_node;
            future_node = (current_node->next);
            free(current_node);
            current_node = future_node;
        }
    }
}

/*  Given a pointer to the first node in a linked list, print_ll() prints the values stored in the linked list in an array form.*/
void print_ll(struct node * first_node){
    struct node * current_node;
    current_node = first_node;
    while (true){
        if((current_node->next) == NULL){
            // The end of the list has been reached
            printf(FORMAT_SPECIFIER " ]", (current_node->data));
            return;
        } else if (current_node == first_node){
            printf("[ " FORMAT_SPECIFIER " , ", (current_node->data));
            current_node = (current_node->next);
        } else{
            printf(FORMAT_SPECIFIER " , ", (current_node->data));
            current_node = (current_node->next);
        }
    }
}
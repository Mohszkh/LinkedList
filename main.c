#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


int main(int argc, char const *argv[])
{
    struct node *first_node = create_ll(10);
    append_node(first_node, 11);
    append_node(first_node, 15125);
    print_ll(first_node);
    destroy_ll(first_node);

    return 0;
}
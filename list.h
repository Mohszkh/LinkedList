#ifndef LIST_H
#define LIST_H
#define DATA_TYPE int
#define FORMAT_SPECIFIER_FUNC(x) #x
#define FORMAT_SPECIFIER FORMAT_SPECIFIER_FUNC(%d)

struct node *create_ll(DATA_TYPE data);
bool append_node(struct node * first_node , DATA_TYPE data);
bool destroy_ll(struct node * first_node);
void print_ll(struct node * first_node);
#endif
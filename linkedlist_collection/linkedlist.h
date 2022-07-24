#include <stdbool.h>

typedef struct node Node;
typedef struct linkedlist LinkedList;

LinkedList *new_linked_list();
bool insert_tail_linked_list(LinkedList *ll, int item);
bool insert_head_linked_list(LinkedList *ll, int item);
void free_linked_list(LinkedList *ll);
void print_linked_list(LinkedList *ll);
int length_linked_list(LinkedList *ll);
bool insert_into_Linked_list_at(LinkedList *ll, int item, int index);
int get_item_linked_list_at_index(LinkedList *ll, int index);
bool remove_item_linked_list_at_index(LinkedList *ll, int index);

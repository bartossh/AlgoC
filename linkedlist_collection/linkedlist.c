#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *previous;
    struct node *next;
} Node;

typedef struct linkedlist
{
    int length;
    Node *head;
    Node *tail;
} LinkedList;

/*
 * Function: new_linked_list
 * --------------------
 * Creates instance of LinkedList and returns pointer to that instance
 *
 * returns: pointer to LinkedList instance
 */
LinkedList *new_linked_list()
{
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
    return ll;
}

/*
 * Function: insert_tail_linked_list
 * --------------------
 * Inserts pointer to item on the tail of linked list
 * ll: pointer to LinkedList
 * item: pointer to item to be inserted
 *
 * returns: true if success or false otherwise
 */
bool insert_tail_linked_list(LinkedList *ll, int item)
{
    if (ll == NULL)
    {
        return false;
    }

    ll->length++;

    Node *n = malloc(sizeof(Node));

    if (ll->tail == NULL)
    {
        n->next = NULL;
        n->previous = NULL;
        n->value = item;
        ll->head = n;
        ll->tail = n;
        return true;
    }

    ll->tail->next = n;
    n->next = NULL;
    n->previous = ll->tail;
    n->value = item;
    ll->tail = n;

    return true;
}

/*
 * Function: insert_head_linked_list
 * --------------------
 * Inserts pointer to item on the head of linked list
 * ll: pointer to LinkedList
 * item: pointer to item to be inserted
 *
 * returns: true if success or false otherwise
 */
bool insert_head_linked_list(LinkedList *ll, int item)
{
    if (ll == NULL)
    {
        return false;
    }

    ll->length++;

    Node *n = malloc(sizeof(Node));

    if (ll->head == NULL)
    {
        n->next = NULL;
        n->previous = NULL;
        n->value = item;
        ll->head = n;
        ll->tail = n;
        return true;
    }

    ll->head->previous = n;
    n->next = ll->head;
    n->previous = NULL;
    n->value = item;
    ll->head = n;

    return true;
}

void free_node_of_linked_list(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    free_node_of_linked_list(n->next);
    free(n);
}

/*
 * Function: free_linked_list
 * --------------------
 * Frees memory used by LinkedList
 * ll: pointer to LinkedList
 *
 * returns: void
 */
void free_linked_list(LinkedList *ll)
{
    if (ll == NULL)
    {
        return;
    }

    if (ll->head == NULL || ll->tail == NULL)
    {
        free(ll);
        return;
    }
    free_node_of_linked_list(ll->head);
    free(ll);
}

void print_node_of_linked_list(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    printf("-> %i ", n->value);
    print_node_of_linked_list(n->next);
}

/*
 * Function: print_linked_list
 * --------------------
 * Prints linked list to stdout
 * ll: pointer to LinkedList
 *
 * returns: void
 */
void print_linked_list(LinkedList *ll)
{
    if (ll == NULL || ll->length == 0)
    {
        return;
    }
    printf("HEAD | ");
    print_node_of_linked_list(ll->head);
    printf("| TAIL\n");
}

/*
 * Function: length_linked_list
 * --------------------
 * Returns linked list length
 * ll: pointer to LinkedList
 *
 * returns: int representing linked list length, -1 if LinkedList is NULL
 */
int length_linked_list(LinkedList *ll)
{
    if (ll == NULL)
    {
        return -1;
    }
    return ll->length;
}

/*
 * Function: insert_into_Linked_list_at
 * --------------------
 * Returns true if insertion done withe success
 * ll: pointer to LinkedList
 * item: pointer to item to be inserted
 *
 * returns: true if success or false otherwise
 */
bool insert_into_Linked_list_at(LinkedList *ll, int item, int index)
{
    if (ll == NULL)
    {
        return false;
    }

    if (index > ll->length)
    {
        return false;
    }

    Node *n = malloc(sizeof(Node));
    n->value = item;

    if (index == 0)
    {
        insert_head_linked_list(ll, item);
        return true;
    }
    if (index == ll->length)
    {
        insert_tail_linked_list(ll, item);
        return true;
    }

    ll->length++;

    Node *next = ll->head;

    for (int i = 1; i < index; i++)
    {
        if (next == NULL)
        {
            return false;
        }
        next = next->next;
    }

    Node *temp = next->next;
    next->next = n;
    n->previous = next;
    n->next = temp;

    return true;
}

int linked_list_loop_forward(LinkedList *ll, Node *n, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (n == NULL)
        {
            return INT_MIN;
        }
        n = n->next;
    }

    return n->value;
}

int linked_list_loop_backward(LinkedList *ll, Node *n, int index)
{
    for (int i = ll->length - index - 2; i >= 0; i--)
    {
        if (n == NULL)
        {
            return INT_MIN;
        }
        n = n->previous;
    }

    return n->value;
}

/*
 * Function: get_item_linked_list_at_index
 * --------------------
 * Returns item at index
 * ll: pointer to LinkedList
 * index: int less then LinkedList length at which add a new item
 *
 * returns: int that is an item at provided index or if not found INT_MIN
 */
int get_item_linked_list_at_index(LinkedList *ll, int index)
{
    if (ll == NULL || index >= ll->length)
    {
        return INT_MIN;
    }

    if (ll->head == NULL || ll->tail == NULL)
    {
        return INT_MIN;
    }

    Node *n = ll->head;

    if (index == 0)
    {
        return n->value;
    }
    if (index == ll->length - 1)
    {
        return ll->tail->value;
    }

    if (index < ll->length / 2)
    {
        return linked_list_loop_forward(ll, n, index);
    }
    return linked_list_loop_backward(ll, ll->tail, index);
}

void remove_and_free_node(Node *n)
{
    if (n->previous != NULL)
    {

        n->previous->next = n->next;
    }

    if (n->next != NULL)
    {

        n->next->previous = n->previous;
    }

    free(n);
}

bool remove_from_the_head(LinkedList *ll, Node *n, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (n == NULL)
        {
            return false;
        }
        n = n->next;
    }

    remove_and_free_node(n);

    return true;
}

bool remove_from_the_tail(LinkedList *ll, Node *n, int index)
{
    for (int i = ll->length - index - 2; i >= 0; i--)
    {
        if (n == NULL)
        {
            return false;
        }
        n = n->previous;
    }

    remove_and_free_node(n);

    return true;
}

/*
 * Function: remove_item_linked_list_at_index
 * --------------------
 * Returns true if success or false otherwise
 * ll: pointer to LinkedList
 * index: int less then LinkedList length at which item needs to be removed
 *
 * returns: bool value representing success of the operation
 */
bool remove_item_linked_list_at_index(LinkedList *ll, int index)
{
    if (ll == NULL || index > ll->length)
    {
        return false;
    }

    if (ll->head == NULL || ll->tail == NULL)
    {
        return false;
    }

    if (ll->length == 1)
    {
        free_node_of_linked_list(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        ll->length = 0;
        return true;
    }

    if (index == 0)
    {
        Node *tmp = ll->head->next;
        remove_and_free_node(ll->head);
        ll->head = tmp;
        ll->length--;
        return true;
    }

    if (index == ll->length - 1)
    {
        Node *tmp = ll->tail->previous;
        remove_and_free_node(ll->tail);
        ll->tail = tmp;
        ll->length--;
        return true;
    }

    if (index < ll->length / 2)
    {
        Node *n = ll->head;

        if (remove_from_the_head(ll, n, index))
        {
            ll->length--;
            return true;
        }
        return false;
    }

    Node *n = ll->tail;

    if (remove_from_the_tail(ll, n, index))
    {
        ll->length--;
        return true;
    }
    return false;
}
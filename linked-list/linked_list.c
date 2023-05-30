#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};


struct list *list_create(void)
{
    struct list *ls = calloc(sizeof(struct list), 1);
    ls->first = NULL;
    ls->last = NULL;
    return ls;
}


size_t list_count(const struct list *list)
{
    if (list->first == NULL || list->last == NULL)
    {
        return 0;
    }

    struct list_node *n = list->first->next;
    size_t count = 1;
    while (n != list->first)
    {
        n = n->next;
        count++;
    }

    return count;
}


void list_push(struct list *list, ll_data_t item_data)
{
    struct list_node *n = malloc(sizeof(struct list_node));
    n->data = item_data;

    if (list->first == NULL || list->last == NULL)
    {
        list->first = n;
        list->last = n;
        n->next = n;
        n->prev = n;
        return;
    }

    n->prev = list->last;
    n->next = list->first;
    list->last->next = n;
    list->first->prev = n;
    list->last = n;
}


ll_data_t list_pop(struct list *list)
{
    if (list->last == NULL)
    {
        ll_data_t d = 0;
        return d;
    }
    if (list->first == list->last)
    {
        
        ll_data_t d = list->first->data;
        free(list->first);
        list->last = NULL;
        list->first = NULL;
        return d;
    }

    struct list_node *n = list->last;
    ll_data_t data = n->data;
   
    list->first->prev = n->prev;
    n->prev->next = list->first;
    list->last = n->prev;

    free(n);
    return data;
}


void list_unshift(struct list *list, ll_data_t item_data)
{

    struct list_node *n = malloc(sizeof(struct list_node));
    n->data = item_data;

    if (list->first == NULL || list->last == NULL)
    {
        list->first = n;
        list->last = n;
        n->next = n;
        n->prev = n;
        return;
    }

    n->prev = list->last;
    n->next = list->first;
    list->last->next = n;
    list->first->prev = n;
    list->first= n;
}


ll_data_t list_shift(struct list *list)
{
    
    if (list->last == NULL)
    {
        ll_data_t d = 0;
        return d;
    }
    
    if (list->first == list->last)
    {
        
        ll_data_t d = list->first->data;
        free(list->first);
        list->last = NULL;
        list->first = NULL;
        return d;
    }

    struct list_node *n = list->first;
    ll_data_t data = n->data;

    list->first = n->next;
    list->last->next = n->next;
    list->first->prev = list->last;


    free(n);
    return data;
}


void list_delete(struct list *list, ll_data_t data)
{
    if (list->first == NULL || list->last == NULL)
    {
        return;
    }

    if (list->first == list->last)
    {
        if (list->first->data == data)
        {
            free(list->first);
            list->first = NULL;
            list->last = NULL;
        }

        return;
    }

    
    if (list->first->data == data)
    {
        list_shift(list); 
        return;
    }


    if (list->last->data == data)
    {
        list_pop(list);
        return;
    }

    struct list_node *n = list->first;
    while (n != list->last) {
        if (n->data == data)
        {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            free(n);
            return;
        }
        n = n->next;
    }
}


void list_destroy(struct list *list)
{
    if (list->first == NULL || list->last == NULL)
    {
        free(list);
        return;
    }

    if (list->first == list->last)
    {
        free(list->first);
        free(list);
        return;
    }

    struct list_node *n = list->first;
    while (n != list->last)
    {
        n = n->next;
        free(n->prev);
    }
    free(list->last);
    free(list);
}

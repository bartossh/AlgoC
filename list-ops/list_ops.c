#include "list_ops.h"
#include <stdlib.h>

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
    if (list == NULL)
    {
        exit(1);
    }
    list->length = length;
    for (size_t i = 0; i < length; i++)
    {
        list->elements[i] = elements[i];
    }
    return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
    if (list1->length + list2->length == 0)
    {
        return new_list(0, NULL);
    }
    list_t *list = malloc(sizeof(list_t) + (list1->length + list2->length) * sizeof(list_element_t));
    if (list == NULL)
    {
        exit(1);
    }

    list->length = list1->length + list2->length;
    for (size_t i = 0; i < list1->length; i++)
    {
        list->elements[i] = list1->elements[i];
    }
    for (size_t i = 0; i < list2->length; i++)
    {
        list->elements[i + list1->length] = list2->elements[i];
    }

    return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    list_t *filtered_list = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (filtered_list == NULL)
    {
        exit(1);
    }

    size_t new_length = 0;

    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]))
        {
            filtered_list->elements[new_length] = list->elements[i];
            new_length++;
        }
    }

    filtered_list->length = new_length;

    return filtered_list;
}

size_t length_list(list_t *list)
{
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t *mapped_list = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (mapped_list == NULL)
    {
        exit(1);
    }

    mapped_list->length = list->length;

    for (size_t i = 0; i < list->length; i++)
    {
        mapped_list->elements[i] = map(list->elements[i]);
    }

    return mapped_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t))
{
    list_element_t result = initial;
    for (size_t i = 0; i < list->length; i++)
    {
        result = foldl(result, list->elements[i]);
    }
    return result;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t))
{
    list_element_t result = initial;
    for (size_t i = list->length; i > 0; i--)
    {
        result = foldr(list->elements[i - 1], result);
    }
    return result;
}

list_t *reverse_list(list_t *list)
{
    list_t *reversed_list = malloc(sizeof(list_t) * list->length * sizeof(list_element_t));

    reversed_list->length = list->length;

    for (size_t i = list->length; i > 0; i--)
    {
        reversed_list->elements[list->length - i] = list->elements[i - 1];
    }

    return reversed_list;
}

void delete_list(list_t *list)
{
    free(list);
}

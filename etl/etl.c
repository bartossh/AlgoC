#include "etl.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int comp(const void * elem1, const void * elem2) 
{
    new_map *orderA = (new_map *)elem1;
    new_map *orderB = (new_map *)elem2;
  
    return (orderA->key - orderB->key);
}

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
    size_t letters = 0;
    for (size_t i = 0; i < input_len; i++)
    {
        letters += strlen(input[i].keys);
    }
    if (*output == NULL)
    {
        (*output) = malloc(sizeof(new_map)*letters);
    }

    size_t next = 0;
    for (size_t i = 0; i < input_len; i++)
    {
        size_t len = strlen(input[i].keys);
        for (size_t j = 0; j < len; j++)
        {
            char l = tolower(input[i].keys[j]);
            new_map nm = {l, input[i].value};
            (*output)[next++] = nm;
        }
    }

    qsort(*output, next, sizeof(*output), comp);

    return next;
}

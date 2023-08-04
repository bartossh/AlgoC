#include "sum_of_multiples.h"
#include <stdlib.h> 

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{

    size_t result = 0;
    int *multip = calloc(limit, sizeof(int));
    if (multip == NULL)
    {
        exit(1);
    }

    for (size_t i = 0; i < number_of_factors; i++)
    {
        if (factors[i] == 0) 
        {
            continue;
        }
        
        for (size_t base = factors[i]; base < limit; base += factors[i])
        {
            multip[base] = base;
        }
    }
    for (size_t i = 0; i < limit; i++)
    {
        if (multip[i] > 0)
        {
            result += multip[i];
        }
    }
    free(multip);
    multip = NULL;

    return result;
}

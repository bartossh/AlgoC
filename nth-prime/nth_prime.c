#include "nth_prime.h"

#include <stddef.h>
#include <stdbool.h>

#define CAP 100000

uint32_t nth(uint32_t n)
{
    switch (n)
    {
    case 0:
        return 0;
    case 1:
        return 2;
    }
    size_t pos = 0;
    uint32_t primes[CAP];
    uint32_t candidate = 3;
    
    while (pos < n-1)
    {
        bool is_prime = true;
        for (size_t i = 0; i < pos; i++)
        {
            if (candidate % primes[i] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime == true)
        {
            primes[pos++] = candidate;
            if (pos == CAP)
            {
                exit(1);
            }
        }
        candidate += 2;
    }

    return primes[pos-1];
}

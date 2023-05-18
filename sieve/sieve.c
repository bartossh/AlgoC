#include "sieve.h"
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{

    if (limit < 2)
    {
        return 0;
    }

    uint32_t prime_count = 0;
    uint32_t *sieve = calloc(limit + 1, sizeof(uint32_t));

    for (uint32_t i = 2; i < limit + 1; i++)
    {
        if (sieve[i] == 0)
        {
            primes[prime_count++] = i;
            for (uint32_t j = i + i; j < limit + 1; j += i)
            {
                sieve[j] = 1;
            }
        }
        if (prime_count == max_primes)
        {
            break;
        }
    }

    return prime_count;
}

#include "prime_factors.h"
#include <stdbool.h>

bool is_prime(uint64_t n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (uint64_t i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int next_prime(uint64_t n)
{

    if (n <= 1)
        return 2;

    int prime = n;
    bool found = false;

    while (!found)
    {
        prime++;

        if (is_prime(prime))
            found = true;
    }

    return prime;
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    if (n == 1)
    {
        return 0;
    }

    uint64_t next = 0;
    uint64_t prime = 2;

    while (next < MAXFACTORS)
    {
        if (is_prime(n))
        {
            factors[next++] = n;
            break;
        }

        if (n % prime == 0)
        {
            n = n / prime;
            factors[next++] = prime;
            continue;
        }

        prime = next_prime(prime);
    }

    return next;
}

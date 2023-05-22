#ifndef PRIME_FACTORS_H
#define PRIME_FACTORS_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAXFACTORS 10

bool is_prime(uint64_t n);
int next_prime(uint64_t n);
size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]);

#endif

#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdlib.h>

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef struct triplet_t
{
    uint16_t a;
    uint16_t b;
    uint16_t c;
} triplet_t;

typedef struct triplets_t
{
    triplet_t *triplets;
    size_t count;
} triplets_t;

triplets_t *triplets_with_sum(uint16_t sum);
triplet_t *next_triplet(uint16_t c, uint16_t sum);
void free_triplets(triplets_t *triplets);

#endif

#include "pythagorean_triplet.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void free_triplets(triplets_t *triplets)
{
    free(triplets);
}

triplet_t *next_triplet(uint16_t c, uint16_t sum)
{
    uint32_t cc = c * c;
    uint16_t b = c - 1;
    while (b >= 4)
    {
        uint32_t bb = b * b;
        uint16_t a = sqrt(cc - bb);
        uint32_t aa = a * a;
        if (a + b + c == sum && aa + bb == cc)
        {
            triplet_t *triplet = malloc(sizeof(triplet_t));
            triplet->a = a;
            triplet->b = b;
            triplet->c = c;
            return triplet;
        }
        b--;
    }

    return NULL;
}

triplets_t *triplets_with_sum(uint16_t sum)
{
    triplet_t *triplets = malloc(sizeof(triplet_t));
    size_t capacity = 1;
    size_t count = 0;
    uint16_t temp_c = sum / 2;

    while (temp_c >= 5)
    {
        triplet_t *triplet = next_triplet(temp_c--, sum);
        if (triplet == NULL)
        {
            continue;
        }
        if (count == capacity)
        {
            capacity++;
            triplets = realloc(triplets, sizeof(triplet_t) * capacity);
        }
        triplets[count++] = *triplet;
    }

    triplets_t *tr = malloc(sizeof(triplets_t));
    tr->triplets = triplets;
    tr->count = count;

    return tr;
}

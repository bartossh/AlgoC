#include "nucleotide_count.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// A:0 C:0 G:0 T:0"

char *count(const char *dna_strand)
{
    char *result = malloc(sizeof(char) * 20);

    uint32_t A = 0;
    uint32_t C = 0;
    uint32_t G = 0;
    uint32_t T = 0;

    for (int i = 0; dna_strand[i] != '\0'; i++)
    {
        switch (dna_strand[i])
        {
        case 'A':
            A++;
            continue;
        case 'C':
            C++;
            continue;
        case 'G':
            G++;
            continue;
        case 'T':
            T++;
            continue;
        default:
            result[0] = '\0';
            return result;
        }
    }
    snprintf(result, 20, "A:%d C:%d G:%d T:%d", A, C, G, T);
    return result;
}

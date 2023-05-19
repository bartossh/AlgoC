#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna)
{
    size_t len = strlen(dna);
    char *rna = calloc(sizeof(char), (len + 1));
    for (size_t i = 0; i < len; i++)
    {
        switch (dna[i])
        {
        case 'G':
            rna[i] = 'C';
            continue;
        case 'C':
            rna[i] = 'G';
            continue;
        case 'T':
            rna[i] = 'A';
            continue;
        case 'A':
            rna[i] = 'U';
            continue;
        }
    }

    return rna;
}

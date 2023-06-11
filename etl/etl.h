#ifndef ETL_H
#define ETL_H

#include <stddef.h>

typedef struct legacy_map {
   int value;
   const char *keys;
} legacy_map;

typedef struct new_map {
   char key;
   int value;
} new_map;

int comp(const void * elem1, const void * elem2);

int convert(const legacy_map *input, const size_t input_len, new_map **output);

#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 500000

typedef struct b_tree_map {
  int unhashed_key;
  int value;
  struct dataitem *next;
} dataitem;

int pseudo_hash_function(int key) { return (int)(key % HASH_SIZE); }

/*
 * Function: make_table
 * --------------------
 * Allocates table of pointer to dataitem struct
 *
 * returns: freshly allocated table of pointers to dataitem struct
 */
dataitem **make_table() {
  dataitem **table = calloc(HASH_SIZE, sizeof(dataitem *));
  return table;
}

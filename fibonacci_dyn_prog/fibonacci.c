#include "../hash_table_collection/table.h"
#include <stdio.h>

int recursive_fib(struct dataitem **store, int n) {
  if (n <= 2) {
    return 1;
  }
  int *v = get_from_table(n, store);
  if (v != NULL) {
    return *v;
  }
  int nv = 1;
  int before = 1;
  for (int i = 2; i < n; i++) {
    nv = nv + before;
    before = nv - before;
  }
  insert_to_table(n, nv, store);
  return nv;
}

/*
 * Function: solve_nth_fibonacci
 * --------------------
 * Solves fibonacci sequence finding n'th value
 * n: position of value in fibonacci sequence to look for
 *
 * returns: n'th value of fibonacci sequence
 */
int solve_nth_fibonacci(int n) {
  struct dataitem **store = make_table();
  int v = recursive_fib(store, n);
  free_table(store);
  return v;
}

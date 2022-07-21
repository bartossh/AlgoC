#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

/*
 * Function: solve_max_sub_array
 * --------------------
 * Find the sub array which has the largest sum, and returns its sum
 * arr: arr of integers
 * len: arr length
 *
 * returns: largest sum of found sub array
 */
int solve_max_sub_array(int *arr, int len) {
  if (len == 0) {
    return 0;
  }

  int *mem = malloc(sizeof(arr[0]) * len);
  mem[0] = arr[0];
  int res = mem[0];

  for (int i = 1; i < len; i++) {
    if (mem[i - 1] > 0) {
      mem[i] = mem[i - 1] + arr[i];
    } else {
      mem[i] = arr[i];
    }
    res = max(res, mem[i]);
  }

  return res;
}

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void update_e_e(int *a, int *oa, int qu) {
  int tmp = *a;
  *a = *oa - qu * tmp;
  *oa = tmp;
}

/*
 * Function:  solve_extedned_euclidean
 * --------------------
 * soleves extedned euclidean extension to the Euclidean algorithm,
 * and computes, in addition to the greatest common divisor (gcd) of integers a
 * and b, also the coefficients of Bézout's identity, which are integers x and y
 * such that x: integer one to search gcd y: integer two to search gdc
 *
 *  returns: abc array of a, b and coefficient
 */
int *solve_extedned_euclidean(int x, int y) {
  int oldR = x;
  int r = y;
  int oldS = 1;
  int cS = 0;
  int oldT = 0;
  int cT = 1;

  while (r != 0) {
    int qu = oldR / r;
    update_e_e(&r, &oldR, qu);
    update_e_e(&cS, &oldS, qu);
    update_e_e(&cT, &oldT, qu);
  }
  int *arr = malloc(3 * sizeof(int));
  arr[0] = oldR;
  arr[1] = oldS;
  arr[2] = oldT;
  return arr;
}

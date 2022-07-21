#include "../munit/munit.h"
#include "./maxsubarray.h"
#include <stdbool.h>
#include <stdio.h>

bool test_sequence() {
  int testArr[3][5] = {
      {0, 1, 0, 5, 8}, {-3, -1, -8, -2, -9}, {-4, 3, -2, 5, -8}};
  int results[3] = {14, -1, 6};
  for (int i = 0; i < 3; i++) {
    int res = solve_max_sub_array(testArr[i], sizeof(testArr[i]) / sizeof(int));
    if (res != results[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  bool ts0 = test_sequence();
  munit_assert_true(ts0);
}
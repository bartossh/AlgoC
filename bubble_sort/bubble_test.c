#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include <stdbool.h>
#include <stdio.h>

extern void sort_bubble(int *arr, int len);

/*
 * Function:  main
 * --------------------
 * runs tests for bubble sort_bubble package
 *
 *  returns: int
 */
int main() {
  bool ts0 = test_simple(&sort_bubble);
  munit_assert_true(ts0);

  bool ts1 = test_mixed(&sort_bubble);
  munit_assert_true(ts1);

  bool ts2 = test_long(&sort_bubble);
  munit_assert_true(ts2);

  bool t3 = test_dynamic_alloc(&sort_bubble);
  munit_assert_true(t3);

  bench_1_000_000(&sort_bubble);
  bench_1_000_000_dynamic(&sort_bubble);

  return 0;
}

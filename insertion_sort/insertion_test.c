#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include <stdbool.h>
#include <stdio.h>

extern void sort_insertion(int *arr, int len);

/*
 * Function:  main
 * --------------------
 * runs tests for insertion sort_insertion package
 *
 *  returns: int
 */
int main() {
  bool ts0 = test_simple(&sort_insertion);
  munit_assert_true(ts0);

  bool ts1 = test_mixed(&sort_insertion);
  munit_assert_true(ts1);

  bool ts2 = test_long(&sort_insertion);
  munit_assert_true(ts2);

  bool t3 = test_dynamic_alloc(&sort_insertion);
  munit_assert_true(t3);

  bench_1_000_000(&sort_insertion);
  bench_1_000_000_dynamic(&sort_insertion);

  return 0;
}

#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include <stdbool.h>
#include <stdio.h>
#include "./bartosz.h"

bool test_remove_empty_allocs() {

  typedef struct testCase {
  int given[14];
  int expected[7];
  } TestCase;

  TestCase cases[6] = {
    {
      {1,2,3,0,0,0,4,5,6,0,0,0,7,0},
      {1,2,3,4,5,6,7},
    },
    {
      {1,2,3,0,0,4,5,6,7,0,0,0,0,0},
      {1,2,3,4,5,6,7},
    },
    {
      {1,0,0,0,0,0,2,3,0,0,4,5,6,7},
      {1,2,3,4,5,6,7},
    },
    {
      {0,0,0,0,0,1,2,3,0,0,4,5,6,7},
      {1,2,3,4,5,6,7},
    },
    {
      {1,2,3,0,0,0,0,0,0,0,4,5,6,7},
      {1,2,3,4,5,6,7},
    },
    {
      {1,0,0,0,0,0,0,2,3,0,4,5,6,7},
      {1,2,3,4,5,6,7},
    },
  };

  for (int j = 0; j < 6; j++) {
    ReallocatedArr result = remove_empty_allocs(cases[j].given, 14);
  if (result.len != 7) {
    return false;
  }
    for (int i = 0; i < 7; i++) {
      if (result.arr[i] !=  cases[j].expected[i]) {
        return false;
      }
    }
  }
  

  return true;
}

/*
 * Function:  main
 * --------------------
 * runs tests for bubble sort_bubble package
 *
 *  returns: int
 */
int main() {

  bool ts = test_remove_empty_allocs();
  munit_assert_true(ts);

  // bool ts0 = test_simple(&sort_bartosz);
  // munit_assert_true(ts0);

  // bool ts1 = test_mixed(&sort_bartosz);
  // munit_assert_true(ts1);

  // bool ts2 = test_long(&sort_bartosz);
  // munit_assert_true(ts2);

  // bool t3 = test_dynamic_alloc(&sort_bartosz);
  // munit_assert_true(t3);

  // bench_1_000_000(&sort_bartosz);
  // bench_1_000_000_dynamic(&sort_bartosz);

  return 0;
}

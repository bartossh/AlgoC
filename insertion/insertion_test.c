#include <stdio.h>
#include <stdbool.h>
#include "../munit/munit.h"
#include "../test_helpers/test.h"

extern void sort(int* arr, int len);

/*
 * Function:  main
 * --------------------
 * runs tests for bubble sort package
 *
 *  returns: int
 */
int main() {
   bool ts0 = test_simple(&sort);
   munit_assert_true(ts0);
   
   bool ts1 = test_simple(&sort);
   munit_assert_true(ts1);
   
   bool ts2 = test_long(&sort);
   munit_assert_true(ts2);

   bool t3 = test_dynamic_alloc(&sort);
   munit_assert_true(t3);
   
   bench_1_000_000(&sort);
   bench_1_000_000_dynamic(&sort);
   
   return 0;
}


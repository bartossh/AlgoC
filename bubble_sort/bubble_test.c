#include <stdio.h>
#include <stdbool.h>
#include "../munit/munit.h"
#include "../test_helpers/test.h"

extern void sort(int* arr, int len);

int main() {
   bool ts0 = test_simple(&sort);
   munit_assert_true(ts0);
   
   bool ts1 = test_simple(&sort);
   munit_assert_true(ts1);
   
   bool ts2 = test_long(&sort);
   munit_assert_true(ts2);
   
   bench_1_000_000(&sort);
   
   return 0;
}


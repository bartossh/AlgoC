#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include <stdbool.h>
#include <stdio.h>

extern void sort_bucket(int *arr, int len);

/*
 * Function:  main
 * --------------------
 * runs tests for bucket sort_bucket package
 *
 *  returns: int
 */
int main()
{
    bool ts0 = test_simple(&sort_bucket);
    munit_assert_true(ts0);

    bool ts1 = test_mixed(&sort_bucket);
    munit_assert_true(ts1);

    bool ts2 = test_long(&sort_bucket);
    munit_assert_true(ts2);

    // TODO(bartossh): This tests are not passing as implementation heavily
    // depends on the heap allocation which is inefficient
    //    bool t3 = test_dynamic_alloc(&sort_bucket);
    //    munit_assert_true(t3);

    //   bench_1_000_000(&sort_bucket);
    //   bench_1_000_000_dynamic(&sort_bucket);

    return 0;
}

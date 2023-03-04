#include "../munit/munit.h"
#include <stdbool.h>
#include <stdio.h>
#include "./bartosz.h"
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>

#define LEN_SHORT 11
#define LEN_LONG 31
#define LEN_EXTREME 10000000

bool test_remove_empty_allocs()
{

    typedef struct testCase
    {
        int given[14];
        int expected[7];
    } TestCase;

    TestCase cases[6] = {
        {
            {1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 0},
            {1, 2, 3, 4, 5, 6, 7},
        },
        {
            {1, 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 0, 0, 0},
            {1, 2, 3, 4, 5, 6, 7},
        },
        {
            {1, 0, 0, 0, 0, 0, 2, 3, 0, 0, 4, 5, 6, 7},
            {1, 2, 3, 4, 5, 6, 7},
        },
        {
            {0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 4, 5, 6, 7},
            {1, 2, 3, 4, 5, 6, 7},
        },
        {
            {1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 7},
            {1, 2, 3, 4, 5, 6, 7},
        },
        {
            {1, 0, 0, 0, 0, 0, 0, 2, 3, 0, 4, 5, 6, 7},
            {1, 2, 3, 4, 5, 6, 7},
        },
    };

    for (int j = 0; j < 6; j++)
    {
        ReallocatedArr result = remove_empty_allocs(cases[j].given, 14);
        if (result.len != 7)
        {
            return false;
        }
        for (int i = 0; i < 7; i++)
        {
            if (result.arr[i] != cases[j].expected[i])
            {
                return false;
            }
        }
    }

    return true;
}

/*
 * Function:  rand_range
 * --------------------
 * generates random int in given range
 * min_num: int specifying bottom border of random number
 * max_num: int specifying top border of random number
 *
 *  returns: int, a random number within bottom and top borders
 */
int range_rand(int min_num, int max_num)
{
    if (min_num >= max_num)
    {
        fprintf(stderr, "min_num is greater or equal than max_num!\n");
    }
    srand(time(NULL));
    return min_num + (rand() % (max_num - min_num));
}

/*
 * Function:  get_time
 * --------------------
 * produces current UNIX time in seconds
 *
 *  returns: double, current UNIX time in seconds
 */
double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec * 1e-6;
}

/*
 * Function:  test_simple_bartosz
 * --------------------
 * runs simple sorting test for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_simple_bartosz(ReallocatedArr (*sort)(int *, int))
{
    printf("Testing Simple \n");
    int testArr[LEN_SHORT] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    ReallocatedArr res = sort(testArr, LEN_SHORT);
    bool result = true;

    for (int i = 0; i < LEN_SHORT; i++)
    {
        if (i < LEN_SHORT - 1 && res.arr[i] > res.arr[i + 1])
            result = false;
    }

    printf("Test passed: %s \n", result ? "true" : "false");
    printf("---\n\n");

    return true;
}

/*
 * Function:  test_mixed_bartosz
 * --------------------
 * runs sorting test on mixed array for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_mixed_bartosz(ReallocatedArr (*sort)(int *, int))
{
    printf("Testing Mixed \n");
    int testArr[LEN_SHORT] = {9, 10, 8, 7, 5, 4, 3, 6, 2, 1, 11};

    ReallocatedArr res = sort(testArr, LEN_SHORT);
    bool result = true;

    for (int i = 0; i < LEN_SHORT; i++)
    {
        if (i < LEN_SHORT - 1 && res.arr[i] > res.arr[i + 1])
            result = false;
    }

    printf("Test passed: %s \n", result ? "true" : "false");
    printf("---\n\n");

    return result;
}

/*
 * Function:  test_long_bartosz
 * --------------------
 * runs sorting test with long array for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_long_bartosz(ReallocatedArr (*sort)(int *, int))
{
    printf("Testing Long \n");
    int testArr[LEN_LONG] = {31, 30, 29, 9, 10, 20, 8, 7, 5, 4, 3,
                             6, 2, 1, 11, 21, 12, 22, 13, 23, 14, 24,
                             15, 25, 16, 26, 17, 27, 18, 28, 19};

    ReallocatedArr res = sort(testArr, LEN_LONG);
    bool result = true;

    for (int i = 0; i < LEN_LONG; i++)
    {
        if (i < LEN_LONG - 1 && res.arr[i] > res.arr[i + 1])
            result = false;
    }

    printf("Test passed: %s \n", result ? "true" : "false");
    printf("---\n\n");

    return result;
}

/*
 * Function:  test_dynamic_alloc_bartosz
 * --------------------
 * runs sorting test with random length dynamic allocated array for provided
 * sorting function sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_dynamic_alloc_bartosz(ReallocatedArr (*sort)(int *, int))
{
    int len = range_rand(LEN_LONG, LEN_EXTREME);
    printf("Testing dynamically allocated array of length %i \n", len);
    int *testArr = malloc(len * sizeof(int));

    for (int i = len; i > 0; i--)
    {
        testArr[i] = i;
    }

    ReallocatedArr res = sort(testArr, len);
    bool result = true;

    for (int i = 0; i < len; i++)
    {
        if (i < len - 2 && res.arr[i] > res.arr[i + 1])
        {
            result = false;
        }
    }

    printf("Test passed: %s \n", result ? "true" : "false");
    printf("---\n\n");

    return result;
}

/*
 * Function:  bench_1_000_000_bartosz
 * --------------------
 * performs benchmark of provided sorting algorithm
 * sort: pointer to sorting function
 *
 *  returns: void,
 */
void bench_1_000_000_bartosz(ReallocatedArr (*sort)(int *, int))
{
    printf("Benchmark %i \n", LEN_EXTREME);
    int testArr[LEN_EXTREME];

    for (int i = LEN_EXTREME; i > 0; i--)
    {
        testArr[i] = i;
    }

    double t0 = get_time();
    sort(testArr, LEN_EXTREME);
    double t1 = get_time();

    printf("Test took: %f sec\n", t1 - t0);
    printf("---\n\n");
}

/*
 * Function:  main
 * --------------------
 * runs tests for bubble sort_bubble package
 *
 *  returns: int
 */
int main()
{

    bool ts = test_remove_empty_allocs();
    munit_assert_true(ts);

    bool ts0 = test_simple_bartosz(&sort_bartosz);
    munit_assert_true(ts0);

    bool ts1 = test_mixed_bartosz(&sort_bartosz);
    munit_assert_true(ts1);

    bool ts2 = test_long_bartosz(&sort_bartosz);
    munit_assert_true(ts2);

    bool t3 = test_dynamic_alloc_bartosz(&sort_bartosz);
    munit_assert_true(t3);

    bench_1_000_000_bartosz(&sort_bartosz);

    return 0;
}

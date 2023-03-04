#include "../munit/munit.h"
#include "./circular.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define LENGTH 20
#define LARGE_LENGTH 2000

bool test_basic()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    circular_int *c = new_circular_int(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        circular_int_set(c, data[i]);
        circular_int_next(c);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = circular_int_get(c);
        circular_int_next(c);
        if (data[i] != j)
        {
            return false;
        }
    }
    circular_int_prev(c);

    for (int i = LENGTH - 1; i >= 0; i--)
    {
        int j = circular_int_get(c);
        circular_int_prev(c);
        if (data[i] != j)
        {
            return false;
        }
    }

    return true;
}

bool test_huge()
{
    circular_int *c = new_circular_int(LARGE_LENGTH);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        circular_int_set(c, i);
        circular_int_next(c);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = circular_int_get(c);
        circular_int_next(c);
        if (i != j)
        {
            return false;
        }
    }
    circular_int_prev(c);

    for (int i = LARGE_LENGTH - 1; i >= 0; i--)
    {
        int j = circular_int_get(c);
        circular_int_prev(c);
        if (i != j)
        {
            return false;
        }
    }

    return true;
}

bool test_circle()
{
    circular_int *c = new_circular_int(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        circular_int_set(c, i);
        circular_int_next(c);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = circular_int_get(c);
        circular_int_next(c);
        if ((i - j) % 10 != 0)
        {
            return false;
        }
    }
    circular_int_prev(c);

    for (int i = LARGE_LENGTH - 1; i >= 0; i--)
    {
        int j = circular_int_get(c);
        circular_int_prev(c);
        if ((i - j) % 10 != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    bool ts0 = test_basic();
    munit_assert_true(ts0);

    bool ts1 = test_huge();
    munit_assert_true(ts1);

    bool ts2 = test_circle();
    munit_assert_true(ts2);

    struct timeval stop, start;

    gettimeofday(&start, NULL);
    test_basic();
    gettimeofday(&stop, NULL);
    printf("test_basic took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    test_huge();
    gettimeofday(&stop, NULL);
    printf("test_huge took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    test_circle();
    gettimeofday(&stop, NULL);
    printf("test_circle took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}

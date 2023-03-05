#include "../munit/munit.h"
#include "./fifo.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define LENGTH 20
#define LARGE_LENGTH 2000

bool test_basic_full_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = fifo_pull_alloc(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_small_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = fifo_pull_alloc(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_complex_small_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
        int j = fifo_pull_alloc(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_large_full_capacity()
{
    fifo_int *c = new_fifo_int(LARGE_LENGTH);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        fifo_push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = fifo_pull_alloc(c);
        if (j != i)
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_large_small_capacity()
{
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        fifo_push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = fifo_pull_alloc(c);
        if (j != i)
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_full_capacity_iter()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = fifo_pull_iter(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_small_capacity_iter()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = fifo_pull_iter(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_complex_small_capacity_iter()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        fifo_push(c, data[i]);
        int j = fifo_pull_iter(c);
        if (j != data[i])
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_large_full_capacity_iter()
{
    fifo_int *c = new_fifo_int(LARGE_LENGTH);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        fifo_push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = fifo_pull_iter(c);
        if (j != i)
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

bool test_basic_large_small_capacity_iter()
{
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        fifo_push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = fifo_pull_iter(c);
        if (j != i)
        {
            fifo_free(c);
            free(c);
            return false;
        }
    }
    fifo_free(c);
    free(c);
    return true;
}

int main()
{
    bool ts0 = test_basic_full_capacity();
    munit_assert_true(ts0);

    bool ts1 = test_basic_small_capacity();
    munit_assert_true(ts1);

    bool ts3 = test_complex_small_capacity();
    munit_assert_true(ts3);

    bool ts4 = test_basic_large_full_capacity();
    munit_assert_true(ts4);

    bool ts5 = test_basic_large_small_capacity();
    munit_assert_true(ts5);

    bool ts0f = test_basic_full_capacity_iter();
    munit_assert_true(ts0);

    bool ts1f = test_basic_small_capacity_iter();
    munit_assert_true(ts1f);

    bool ts3f = test_complex_small_capacity_iter();
    munit_assert_true(ts3f);

    bool ts4f = test_basic_large_full_capacity_iter();
    munit_assert_true(ts4f);

    bool ts5f = test_basic_large_small_capacity_iter();
    munit_assert_true(ts5f);

    struct timeval stop, start;

    long int sum = 0;
    const long int tries = 1000;

    for (int i = 0; i < tries; i++)
    {
        gettimeofday(&start, NULL);
        test_basic_large_full_capacity();
        gettimeofday(&stop, NULL);
        sum = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
    }
    printf("test_basic_large_full_capacity took %lu us\n", sum / tries);

    for (int i = 0; i < tries; i++)
    {
        gettimeofday(&start, NULL);
        test_basic_large_full_capacity_iter();
        gettimeofday(&stop, NULL);
        sum = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
    }
    printf("test_basic_large_full_capacity_iter took %lu us\n", sum / tries);

    for (int i = 0; i < tries; i++)
    {
        gettimeofday(&start, NULL);
        test_basic_large_small_capacity();
        gettimeofday(&stop, NULL);
        sum = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
    }
    printf("test_basic_large_small_capacity took %lu us\n", sum / tries);

    sum = 0;
    for (int i = 0; i < tries; i++)
    {
        gettimeofday(&start, NULL);
        test_basic_large_small_capacity_iter();
        gettimeofday(&stop, NULL);
        sum = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
    }
    printf("test_basic_large_small_capacity_iter took %lu us\n", sum / tries);
}

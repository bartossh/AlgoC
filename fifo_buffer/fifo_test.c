#include "../munit/munit.h"
#include "./fifo.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 20
#define LARGE_LENGTH 2000

bool test_basic_full_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = pull(c);
        if (j != data[i])
        {
            return false;
        }
    }
    return true;
}

bool test_basic_small_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        push(c, data[i]);
    }

    for (int i = 0; i < LENGTH; i++)
    {
        int j = pull(c);
        if (j != data[i])
        {
            return false;
        }
    }
    return true;
}

bool test_complex_small_capacity()
{
    int data[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LENGTH; i++)
    {
        push(c, data[i]);
        int j = pull(c);
        if (j != data[i])
        {
            return false;
        }
    }
    return true;
}

bool test_basic_large_full_capacity()
{
    fifo_int *c = new_fifo_int(LARGE_LENGTH);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = pull(c);
        if (j != i)
        {
            return false;
        }
    }
    return true;
}

bool test_basic_large_small_capacity()
{
    fifo_int *c = new_fifo_int(10);

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        push(c, i);
    }

    for (int i = 0; i < LARGE_LENGTH; i++)
    {
        int j = pull(c);
        if (j != i)
        {
            return false;
        }
    }
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
}

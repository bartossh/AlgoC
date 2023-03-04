#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include "./fibonacci.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_sequence()
{
    int arr[16][2] = {{1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 5}, {6, 8}, {7, 13}, {8, 21}, {9, 34}, {10, 55}, {15, 610}, {20, 6765}, {25, 75025}, {30, 832040}, {35, 9227465}, {40, 102334155}};

    int arrLength = sizeof arr / sizeof arr[0];

    for (int i = 0; i < arrLength; i++)
    {
        int v = solve_nth_fibonacci(arr[i][0]);
        if (v != arr[i][1])
        {
            return false;
        }
    }
    return true;
}

void benchmark_fibonacci()
{
    int loop = 100;
    double t0 = get_time();
    for (int i = 0; i < loop; i++)
    {
        int v = solve_nth_fibonacci(40);
    }
    double t1 = get_time();
    printf("Calculating %i times fibonacci value took: %f sec\n", loop, t0 - t1);
}

int main()
{
    bool ts0 = test_sequence();
    munit_assert_true(ts0);

    benchmark_fibonacci();
}

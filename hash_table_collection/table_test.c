#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include "./table.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool test_table_no_conflicts()
{
    int cases[10] = {500000, 12, 10000, 1267, 1,
                     99990, 288888, 22222, 456789, 155342};
    struct dataitem **table = make_table();

    for (int i = 0; i < 10; i++)
    {
        insert_to_table(cases[i], i * 10, table);
    }

    for (int i = 0; i < 10; i++)
    {
        int *value = get_from_table(cases[i], table);

        if (value == NULL)
        {
            return false;
        }
        printf("%i == %i %s\n", *value, i * 10,
               *value == i * 10 ? "true" : "false");

        if (*value != i * 10)
        {
            return false;
        }
    }

    free_table(table);
    return true;
}

bool test_table_conflicts()
{
    int cases[10] = {500000, 0, 1000000, 20, 10000000,
                     2000000, 3000000, 4000000, 5500000, 5000000};
    struct dataitem **table = make_table();

    for (int i = 0; i < 10; i++)
    {
        insert_to_table(cases[i], i * 10, table);
    }

    for (int i = 0; i < 10; i++)
    {
        int *value = get_from_table(cases[i], table);

        if (value == NULL)
        {
            return false;
        }

        printf("%i == %i %s\n", *value, i * 10,
               *value == i * 10 ? "true" : "false");

        if (*value != i * 10)
        {
            return false;
        }
    }

    free_table(table);
    return true;
}

int mix(int i) { return i * 10 / 3 * 2; }

bool test_table_big()
{
    const int iterations = 500000;
    struct dataitem **table = make_table();

    for (int i = 0; i < iterations; i++)
    {
        insert_to_table(mix(i), mix(i), table);
    }

    for (int i = 0; i < iterations; i++)
    {
        int *value = get_from_table(mix(i), table);

        if (i % (iterations / 100) == 0)
        {
            printf("%i == %i %s\n", *value, mix(i),
                   *value == mix(i) ? "true" : "false");
        }

        if (value == NULL)
        {
            return false;
        }

        if (*value != mix(i))
        {
            return false;
        }
    }

    free_table(table);
    return true;
}

bool test_table_mega_big()
{
    const int iterations = INT_MAX / 1000;
    struct dataitem **table = make_table();

    for (int i = 0; i < iterations; i += 1)
    {
        insert_to_table(i, i, table);
    }

    for (int i = 0; i < iterations; i += 1)
    {
        int *value = get_from_table(i, table);

        if (value == NULL)
        {
            return false;
        }

        if (*value != i)
        {
            return false;
        }
    }

    free_table(table);
    return true;
}

int main()
{
    bool ts0 = test_table_no_conflicts();
    munit_assert_true(ts0);

    bool ts1 = test_table_conflicts();
    munit_assert_true(ts1);

    bool ts2 = test_table_big();
    munit_assert_true(ts2);

    double t0 = get_time();
    bool ts3 = test_table_mega_big();
    double t1 = get_time();
    munit_assert_true(ts3);
    printf("Test of: %i inputs and reads from table took: %f seconds\n",
           INT_MAX / 1000, t1 - t0);

    return 0;
}

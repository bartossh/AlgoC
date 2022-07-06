#include <stdio.h>
#include <stdbool.h>
#include "./solver.h"
#include "../munit/munit.h"

bool test_table_no_conflicts() {
    int cases[10] = {500000, 12, 10000, 1267, 1, 99990, 288888, 22222, 456789, 155342};
    struct dataitem** table = make_table();

    for (int i = 0; i < 10; i++) {
       insert_to_table(cases[i], i*10, table);
    }

    for (int i = 0; i < 10; i++) {
       int* value = get_from_table(cases[i], table);

       if (value == NULL) {
           return false;
       }
       printf("%i == %i %s\n",*value, i*10, *value == i*10 ? "true" : "false");

       if (*value != i*10) {
            return false;
       }
    }

    free_table(table);
    return true;
}

bool test_table_conflicts() {
    int cases[10] = {500000, 0, 1000000, 20, 10000000, 2000000, 3000000, 4000000, 5500000, 5000000};
    struct dataitem** table = make_table();

    for (int i = 0; i < 10; i++) {
       insert_to_table(cases[i], i*10, table);
    }

    for (int i = 0; i < 10; i++) {
       int* value = get_from_table(cases[i], table);

       if (value == NULL) {
           return false;
       }

       printf("%i == %i %s\n",*value, i*10, *value == i*10 ? "true" : "false");

       if (*value != i*10) {
            return false;
       }
    }

    free_table(table);
    return true;
}

int mix(int i) {
    return i*10/3*2;
}

bool test_table_big() {
    const int iterations = 500000;
    struct dataitem** table = make_table();

    for (int i = 0; i < iterations; i++) {
       insert_to_table(mix(i), mix(i), table);
    }

    for (int i = 0; i < iterations; i++) {
       int* value = get_from_table(mix(i), table);

    if (i % (iterations/100) == 0) {
        printf("%i == %i %s\n",*value, mix(i), *value == mix(i) ? "true" : "false");
    }

       if (value == NULL) {
           return false;
       }


       if (*value != mix(i)) {
            return false;
       }
    }

    free_table(table);
    return true;
}

int main() {
    bool ts0 = test_table_no_conflicts();
    munit_assert_true(ts0);
 
    bool ts1 = test_table_conflicts();
    munit_assert_true(ts1);

    bool ts2 = test_table_big();
    munit_assert_true(ts2);
    
    return 0;
}


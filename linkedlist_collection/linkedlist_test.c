#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include "./linkedlist.h"
#include <stdbool.h>
#include <stdio.h>

#define BenchInsertsNum 100000

bool test_linked_list_with_print()
{

    LinkedList *ll = new_linked_list();

    int nt[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int nh[10] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 0};
    for (int i = 0; i < sizeof(nt) / sizeof(int); i++)
    {
        insert_tail_linked_list(ll, nt[i]);
    }
    for (int i = 0; i < sizeof(nh) / sizeof(int); i++)
    {
        insert_head_linked_list(ll, nh[i]);
    }

    print_linked_list(ll);
    int len = length_linked_list(ll);
    if (len != 20)
    {
        return false;
    }
    free_linked_list(ll);
    ll = NULL;
    print_linked_list(ll);

    return true;
}

bool test_linked_list_insert_large()
{
    LinkedList *ll = new_linked_list();

    int elementsNum = 10000;

    for (int i = elementsNum - 1; i >= 0; i--)
    {
        insert_head_linked_list(ll, i);
    }
    for (int i = elementsNum; i < elementsNum * 2; i++)
    {
        insert_tail_linked_list(ll, i);
    }

    int len = length_linked_list(ll);
    if (len == elementsNum * 2 - 1)
    {
        return false;
    }

    // print_linked_list(ll);
    free_linked_list(ll);
    ll = NULL;

    return true;
}

bool test_linked_list_with_insert_at()
{

    LinkedList *ll = new_linked_list();

    int nt[2] = {55, 66};
    int nh[3] = {33, 22, 11};
    for (int i = 0; i < sizeof(nt) / sizeof(int); i++)
    {
        insert_tail_linked_list(ll, nt[i]);
    }
    for (int i = 0; i < sizeof(nh) / sizeof(int); i++)
    {
        insert_head_linked_list(ll, nh[i]);
    }

    bool ok = insert_into_Linked_list_at(ll, 44, 3);
    if (!ok)
    {
        return false;
    }
    ok = insert_into_Linked_list_at(ll, 77, 6);
    if (!ok)
    {
        return false;
    }
    ok = insert_into_Linked_list_at(ll, 0, 0);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);
    int len = length_linked_list(ll);
    if (len != 8)
    {
        return false;
    }

    free_linked_list(ll);
    ll = NULL;
    print_linked_list(ll);

    return true;
}

bool test_linked_list_get_at_index()
{

    LinkedList *ll = new_linked_list();

    int nt[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int nh[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (int i = 0; i < sizeof(nt) / sizeof(int); i++)
    {
        insert_tail_linked_list(ll, nt[i]);
    }
    for (int i = 0; i < sizeof(nh) / sizeof(int); i++)
    {
        insert_head_linked_list(ll, nh[i]);
    }

    print_linked_list(ll);
    int len = length_linked_list(ll);
    if (len != 20)
    {
        return false;
    }

    for (int i = 0; i < 20; i++)
    {
        int value = get_item_linked_list_at_index(ll, i);
        if (value != i)
        {
            return false;
        }
    }

    free_linked_list(ll);
    ll = NULL;
    print_linked_list(ll);

    return true;
}

void test_insane_linked_list()
{
    LinkedList *ll = new_linked_list();

    for (int i = 0; i < BenchInsertsNum; i++)
    {
        insert_tail_linked_list(ll, i);
    }

    get_item_linked_list_at_index(ll, 0);                   // first
    get_item_linked_list_at_index(ll, BenchInsertsNum - 1); // last
    get_item_linked_list_at_index(ll, BenchInsertsNum / 2); // middle
    get_item_linked_list_at_index(ll, BenchInsertsNum - 2); // iterate to last

    free_linked_list(ll);
    ll = NULL;
}

bool test_remove_node_at()
{

    LinkedList *ll = new_linked_list();

    int nt[3] = {44, 55, 66};
    int nh[3] = {33, 22, 11};
    for (int i = 0; i < sizeof(nt) / sizeof(int); i++)
    {
        insert_tail_linked_list(ll, nt[i]);
    }
    for (int i = 0; i < sizeof(nh) / sizeof(int); i++)
    {
        insert_head_linked_list(ll, nh[i]);
    }

    print_linked_list(ll);

    bool ok = remove_item_linked_list_at_index(ll, 4);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    int value4 = get_item_linked_list_at_index(ll, 4);
    if (value4 == 55)
    {
        return false;
    }

    ok = remove_item_linked_list_at_index(ll, 0);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    ok = remove_item_linked_list_at_index(ll, 3);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    ok = remove_item_linked_list_at_index(ll, 2);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    ok = remove_item_linked_list_at_index(ll, 0);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    ok = remove_item_linked_list_at_index(ll, 0);
    if (!ok)
    {
        return false;
    }

    print_linked_list(ll);

    free_linked_list(ll);
    ll = NULL;
    print_linked_list(ll);

    return true;
}

int main()
{
    bool ts = test_linked_list_with_print();
    munit_assert_true(ts);

    ts = test_linked_list_insert_large();
    munit_assert_true(ts);

    ts = test_linked_list_with_insert_at();
    munit_assert_true(ts);

    ts = test_linked_list_get_at_index();
    munit_assert_true(ts);

    double t0 = get_time();
    test_insane_linked_list();
    double t1 = get_time();
    printf("Test of: %i inputs and reads from table took: %f seconds\n",
           BenchInsertsNum, t1 - t0);

    ts = test_remove_node_at();
    munit_assert_true(ts);

    return 0;
}

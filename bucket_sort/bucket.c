#include "../insertion_sort/insertion.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int capacity, len;
    int *arr;
} Buckets;

bool append_to_bucket(Buckets *bck, int value)
{
    if (bck->len == bck->capacity)
    {
        return false;
    }
    bck->arr[bck->len] = value;
    bck->len++;
    return true;
}

void free_bucket(Buckets *bck) { free(bck->arr); }

Buckets *new_bucket(int capacity)
{
    Buckets *bucket = malloc(sizeof(Buckets));
    bucket->arr = calloc(capacity, sizeof(int));
    bucket->capacity = capacity;
    bucket->len = 0;
    return bucket;
}

/*
 * Function:  sort_bucket
 * --------------------
 * sorts array of integers using bucket sort algorithm
 * which depends on insertion sort algorithm
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
void sort_bucket(int *arr, int len)
{
    int capacityX, capacityY;
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    capacityX = len + 1;
    capacityY = len / max + 1;

    Buckets **buckets =
        calloc(len, sizeof(Buckets *)); // FIXME:(bartossh): the heap allocation
                                        // is inefficient for performances

    for (int i = 0; i < capacityX; i++)
    { // initialize Buckets for each value
        buckets[i] = new_bucket(capacityY);
    }

    for (int i = 0; i < len; i++)
    {
        append_to_bucket(buckets[len * arr[i] / max], arr[i]);
    }

    for (int i = 0; i < capacityX; i++)
    {
        sort_insertion(buckets[i]->arr, buckets[i]->len);
    }

    int z = 0;
    for (int i = 0; i < len + 1; i++)
    {
        if (buckets[i]->len > 0)
        {
            Buckets *bucket = buckets[i];
            for (int j = 0; j < bucket->len; j++)
            {
                arr[z] = buckets[i]->arr[j];
                free_bucket(bucket);
                z++;
            }
        }
    }

    free(buckets);
}

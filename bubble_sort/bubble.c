#include <stdbool.h>
#include <stdio.h>

/*
 * Function:  sort_bubble
 * --------------------
 * sorts array of integers by brute force, implements bubble sort algorithm
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
void sort_bubble(int *arr, int len)
{
    bool sorted = false;
    int n = len - 1;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = false;
            }
        }
        n--;
    }
}

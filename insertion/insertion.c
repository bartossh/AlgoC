#include <stdio.h>
#include <stdbool.h>

/*
 * Function:  sort
 * --------------------
 * sorts array of integers by insertion sort algorithm
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
void sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int cur = arr[i];
        int j = i -1;
        int tmp; 
        while (arr[j] > cur) {
            tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            if (j == 0) {
                break;
            }
            j--;
        }
    }
}


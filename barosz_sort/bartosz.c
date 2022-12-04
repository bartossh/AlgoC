#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Function:  sort_bartosz
 * --------------------
 * sorts array of integers by allocating copy of given array,
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
void sort_bartosz(int *arr, int len) {
  
}

typedef struct reallocatedArr {
    int *arr;
    int len;
} ReallocatedArr;

ReallocatedArr remove_empty_allocs(int *arr, int len) {
    int i = 0;
    int f = 0;
    bool was_empty = false;
    while (true) {
        if (i == len) {
            break;
        }

        int v = arr[i];
        if (v == 0 && !was_empty) {
            f = i;
            was_empty = true;
            i++;
            continue;
        }

        if (v != 0 && was_empty) {
            was_empty = false;
            len -= f-i;
            int *temp = malloc(len*sizeof(int));
            memcpy(temp, arr, f*sizeof(int));
            memcpy(temp[f], arr[i], (len-f) * sizeof(int));
            free(arr);
            arr = temp;
            i++;
            i -= i - f;
            continue;
        }
        if (i== len -1 && was_empty) {
            int *temp = malloc(f*sizeof(int));
            memcpy(temp, arr, f*sizeof(int));
            free(arr);
            arr = temp;
            break;
        }
    }
    ReallocatedArr result;
    result.arr = arr;
    result.len = len;
    return result;
}

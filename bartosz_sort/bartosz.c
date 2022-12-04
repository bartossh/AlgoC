#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./bartosz.h"

/*
 * Function:  sort_bartosz
 * --------------------
 * sorts array of integers by allocating copy of given array,
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
ReallocatedArr sort_bartosz(int *arr, int len) {
  int *temp = calloc(len, sizeof(int));
  int len_t = len;
  for (int i = 0; i < len; i++) {
    int v = arr[i];
    if (v > len_t) {
        temp = realloc(temp, sizeof(*temp)+(v-len)*sizeof(int));
        len_t = v;
    }
    if (v == 0) {
        continue;
    }

    temp[v-1] = v;
  }
  ReallocatedArr res;
  if (len == len_t) {
    arr = temp;
    res.arr = arr;
    res.len = len;
    return res;
  }
  return remove_empty_allocs(temp, len_t);
}

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
            if (i == len - 1) {
                continue;    
            }
            i++;
            continue;
        }

        if (v != 0 && was_empty) {
            was_empty = false;
            len -= i-f;
            int *temp = malloc(len*sizeof(int));
            memcpy(temp, arr, f*sizeof(int));
            memcpy(&temp[f], &arr[i], (len) * sizeof(int));
            arr = temp;
            i = f;
            continue;
        }
        if (i == len - 1 && was_empty) {
            int *temp = malloc(f*sizeof(int));
            memcpy(temp, arr, f*sizeof(int));
            arr = temp;
            len = f;
            break;
        }
        i++;
    }
    ReallocatedArr result;
    result.arr = arr;
    result.len = len;
    return result;
}

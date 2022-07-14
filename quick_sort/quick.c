#include <stdbool.h>
#include <stdio.h>

/*
 * Function:  sort_quick
 * --------------------
 * sorts array of integers using quick sort algorithm
 *  arr: pointer to array to be sorted
 *  len: length of an array
 *
 *  returns: void
 */
void sort_quick(int *arr, int len) {
  bool sorted = false;
  int n = len - 1;
  while (!sorted) {
    sorted = true;
    for (int i = 0; i < n; i++) {
      if (arr[i] > arr[i + 1]) {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        sorted = false;
      }
    }
    n--;
  }
}

int partition(int *arr, int l, int h) {
  int pivot = h;
  int i = l - 1;
  int j = h;

  int tmp;
  while (true) {
    i++;

    while (arr[i] < arr[pivot]) {
      i++;
    }

    while (j >= 0 && arr[j] > arr[pivot]) {
      j--;
    }

    if (i >= j) {
      break;
    }

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
  tmp = arr[i];
  arr[i] = arr[pivot];
  arr[pivot] = tmp;
  return i;
}

void _sort(int *arr, int l, int h) {
  if (l < h) {
    int p = partition(arr, l, h);
    _sort(arr, l, p - 1);
    _sort(arr, p + 1, h);
  }
}

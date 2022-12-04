typedef struct reallocatedArr {
    int *arr;
    int len;
} ReallocatedArr;


extern void sort_bartosz(int *arr, int len);
ReallocatedArr remove_empty_allocs(int *arr, int len);


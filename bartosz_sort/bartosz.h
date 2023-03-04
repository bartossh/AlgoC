typedef struct reallocatedArr
{
    int *arr;
    int len;
} ReallocatedArr;

ReallocatedArr sort_bartosz(int *arr, int len);
ReallocatedArr remove_empty_allocs(int *arr, int len);

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int arr1[7] = {1,2,3,0,0,4,5};
    int *arr2 = malloc(5*sizeof(int));
    memcpy(arr2, arr1, 3*sizeof(int));
    memcpy(&arr2[3], &arr1[5], 2*sizeof(int));
    for (int i = 0; i < 5; i ++){
        printf("value %i \n", arr2[i]);
    }
    return 0;
}

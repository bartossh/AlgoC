#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"

bool test_simple(void (*sort)(int*, int) ) {
    printf("Testing Simple \n");
    int testArr[LEN_SHORT] = {10,9,8,7,6,5,4,3,2,1,0};
    printf("Before\n");

    for (int i = 0; i < LEN_SHORT; i++) {
        printf("%i, ", testArr[i]);
    }
    sort(testArr, LEN_SHORT);

    printf("\n");
    printf("After\n");
    bool result = true;

    for (int i = 0; i < LEN_SHORT; i++) {
        printf("%i, ", testArr[i]);
        if (i < LEN_SHORT-1 && testArr[i] > testArr[i+1] ) result = false;
    }

    printf("\n");
    printf("Test passed: %s \n", result?"true":"false");
    printf("---\n\n");
    return result;
}


bool test_mixed(void (*sort)(int*, int))  {
    printf("Testing Mixed \n");
    int testArr[LEN_SHORT] = {9,10,8,7,5,0,4,3,6,2,1};
    printf("Before\n");

    for (int i = 0; i < LEN_SHORT; i++) {
        printf("%i, ", testArr[i]);
    }

    sort(testArr, LEN_SHORT);

    printf("\n");
    printf("After\n");
    bool result = true;

    for (int i = 0; i < LEN_SHORT; i++) {
        printf("%i, ", testArr[i]);
        if (i < LEN_SHORT-1 && testArr[i] > testArr[i+1] ) result = false;
    }

    printf("\n");
    printf("Test passed: %s \n", result?"true":"false");
    printf("---\n\n");
    return result;
}

bool test_long(void (*sort)(int*, int))  {
    printf("Testing Long \n");
    int testArr[LEN_LONG] = {30,29,9,10,20,8,7,5,0,4,3,6,2,1,11,21,12,22,13,23,14,24,15,25,16,26,17,27,18,28,19};
    printf("Before\n");

    for (int i = 0; i < LEN_LONG; i++) {
        printf("%i, ", testArr[i]);
    }

    sort(testArr, LEN_LONG);
    
    printf("\n");
    printf("After\n");
    bool result = true;
    
    for (int i = 0; i < LEN_LONG; i++) {
        printf("%i, ", testArr[i]);
        if (i < LEN_LONG-1 && testArr[i] > testArr[i+1] ) result = false;
    }
    
    printf("\n");
    printf("Test passed: %s \n", result?"true":"false");
    printf("---\n\n");
    return result;
}

double get_time() {
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

void bench_1_000_000(void (*sort)(int*, int) ) {
    printf("Benchmark %i \n", LEN_EXTRIME);
    int testArr[LEN_EXTRIME];
    
    for (int i = LEN_EXTRIME-1; i >= 0; i--) {
        testArr[i] = i;
    }
    
    double t0 = get_time(); 
    sort(testArr, LEN_EXTRIME);
    double t1 = get_time();
    
    printf("Test took: %f \n", t1-t0);
    printf("---\n\n");
}


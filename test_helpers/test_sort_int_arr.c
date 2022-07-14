#include "test.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>

/*
 * Function:  test_simple
 * --------------------
 * runs simple sorting test for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_simple(void (*sort)(int *, int)) {
  printf("Testing Simple \n");
  int testArr[LEN_SHORT] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
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
    if (i < LEN_SHORT - 1 && testArr[i] > testArr[i + 1])
      result = false;
  }

  printf("\n");
  printf("Test passed: %s \n", result ? "true" : "false");
  printf("---\n\n");

  return result;
}

/*
 * Function:  test_mixed
 * --------------------
 * runs sorting test on mixed array for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_mixed(void (*sort)(int *, int)) {
  printf("Testing Mixed \n");
  int testArr[LEN_SHORT] = {9, 10, 8, 7, 5, 0, 4, 3, 6, 2, 1};
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
    if (i < LEN_SHORT - 1 && testArr[i] > testArr[i + 1])
      result = false;
  }

  printf("\n");
  printf("Test passed: %s \n", result ? "true" : "false");
  printf("---\n\n");

  return result;
}

/*
 * Function:  test_long
 * --------------------
 * runs sorting test with long array for provided sorting function
 * sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_long(void (*sort)(int *, int)) {
  printf("Testing Long \n");
  int testArr[LEN_LONG] = {30, 29, 9,  10, 20, 8,  7,  5,  0,  4,  3,
                           6,  2,  1,  11, 21, 12, 22, 13, 23, 14, 24,
                           15, 25, 16, 26, 17, 27, 18, 28, 19};
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
    if (i < LEN_LONG - 1 && testArr[i] > testArr[i + 1])
      result = false;
  }

  printf("\n");
  printf("Test passed: %s \n", result ? "true" : "false");
  printf("---\n\n");

  return result;
}

/*
 * Function:  rand_range
 * --------------------
 * generates random int in given range
 * min_num: int specifying bottom border of random number
 * max_num: int specifying top border of random number
 *
 *  returns: int, a random number within bottom and top borders
 */
int range_rand(int min_num, int max_num) {
  if (min_num >= max_num) {
    fprintf(stderr, "min_num is greater or equal than max_num!\n");
  }
  srand(time(NULL));
  return min_num + (rand() % (max_num - min_num));
}

/*
 * Function:  test_dynamic_alloc
 * --------------------
 * runs sorting test with random length dynamic allocated array for provided
 * sorting function sort: pointer to sorting function
 *
 *  returns: bool, true if test passed with success or false otherwise
 */
bool test_dynamic_alloc(void (*sort)(int *, int)) {
  int len = range_rand(LEN_LONG, LEN_EXTRIME);
  printf("Testing dynamically allocated array of length %i \n", len);
  int *testArr = malloc(len * sizeof(int));

  for (int i = len - 1; i >= 0; i--) {
    testArr[i] = i;
  }

  sort(testArr, len);

  bool result = true;
  for (int i = 0; i < len; i++) {
    if (i < len - 1 && testArr[i] > testArr[i + 1])
      result = false;
  }

  free(testArr);

  printf("\n");
  printf("Test passed: %s \n", result ? "true" : "false");
  printf("---\n\n");

  return result;
}

/*
 * Function:  get_time
 * --------------------
 * produces current UNIX time in seconds
 *
 *  returns: double, current UNIX time in seconds
 */
double get_time() {
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec * 1e-6;
}

/*
 * Function:  bench_1_000_000
 * --------------------
 * performs benchmark of provided sorting algorithm
 * sort: pointer to sorting function
 *
 *  returns: void,
 */
void bench_1_000_000(void (*sort)(int *, int)) {
  printf("Benchmark %i \n", LEN_EXTRIME);
  int testArr[LEN_EXTRIME];

  for (int i = LEN_EXTRIME - 1; i >= 0; i--) {
    testArr[i] = i;
  }

  double t0 = get_time();
  sort(testArr, LEN_EXTRIME);
  double t1 = get_time();

  printf("Test took: %f sec\n", t1 - t0);
  printf("---\n\n");
}

/*
 * Function:  bench_1_000_000_dynamic
 * --------------------
 * performs benchmark of provided sorting algorithm on dynamically allocated
 * array sort: pointer to sorting function
 *
 *  returns: void,
 */
void bench_1_000_000_dynamic(void (*sort)(int *, int)) {
  printf("Benchmark %i dynamically allocated\n", LEN_EXTRIME);
  int *testArr = malloc(LEN_EXTRIME * sizeof(int));

  for (int i = LEN_EXTRIME - 1; i >= 0; i--) {
    testArr[i] = i;
  }

  double t0 = get_time();
  sort(testArr, LEN_EXTRIME);
  double t1 = get_time();
  free(testArr);
  printf("Test took: %f sec\n", t1 - t0);
  printf("---\n\n");
}

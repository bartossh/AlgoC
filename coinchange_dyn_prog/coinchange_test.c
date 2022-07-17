#include "../munit/munit.h"
#include "../test_helpers/test.h"
#include "./coinchange.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_coinchange() {
  typedef struct testcase {
    int *coins;
    int amount;
    int value;
  } testcase;

  struct testcase cases[3];

  int a[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
  cases[0].coins = a;
  cases[0].amount = 1203;
  cases[0].value = 5;

  cases[1].coins = a;
  cases[1].amount = 1234;
  cases[1].value = 7;

  cases[2].coins = a;
  cases[2].amount = 5555;
  cases[2].value = 13;

  int arrLength = sizeof cases / sizeof cases[0];

  for (int i = 0; i < arrLength; i++) {
    int v = solve_coin_change(cases[i].coins, 9, cases[i].amount);
    if (v != cases[i].value) {
      return false;
    }
  }
  return true;
}

void benchmark_coinchange() {
  int loop = 100;
  double t0 = get_time();
  for (int i = 0; i < loop; i++) {
    int arr[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    solve_coin_change(arr, 9, 5555);
  }
  double t1 = get_time();
  printf("Calculating %i times fibonacci value took: %f sec\n", loop, t0 - t1);
}

int main() {
  bool ts0 = test_coinchange();
  munit_assert_true(ts0);

  benchmark_coinchange();
}

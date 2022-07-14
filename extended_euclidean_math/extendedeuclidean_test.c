#include "../munit/munit.h"
#include "./extendedeuclidean.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct TestCase {
  int data[2];
  int solution[3];
} TestCase;

bool testsimple() {

  TestCase casse[] = {
      {{101, 13}, {1, 4, -31}}, {{123, 19}, {1, -2, 13}},
      {{25, 36}, {1, 13, -9}},  {{69, 54}, {3, -7, 9}},
      {{55, 79}, {1, 23, -16}}, {{33, 44}, {11, -1, 1}},
      {{50, 70}, {10, 3, -2}},
  };

  int length = sizeof(casse) / sizeof(TestCase);

  for (int i = 0; i < length; i++) {
    int *arr = solve_extedned_euclidean(casse[i].data[0], casse[i].data[1]);
    if (arr[0] != casse[i].solution[0] || arr[1] != casse[i].solution[1] ||
        arr[2] != casse[i].solution[2]) {
      return false;
    }
  }

  return true;
}

int main() {
  bool ts0 = testsimple();
  munit_assert_true(ts0);

  return 0;
}
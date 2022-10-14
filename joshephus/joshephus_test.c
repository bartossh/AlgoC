#include "../munit/munit.h"
#include <stdbool.h>
#include <stdio.h>

extern int joshephus_solver(int num);

/*
 * Function:  main
 * --------------------
 * runs tests for bucket sort_quick package
 *
 *  returns: int
 */
int main() {
  unsigned int ts0 = joshephus_solver(41);
  unsigned int exp0 = 19;
  munit_assert_true(ts0 == exp0);

  unsigned int ts1 = joshephus_solver(1);
  unsigned int exp1 = 1;
  munit_assert_true(ts1 == exp1);

  unsigned int ts2 = joshephus_solver(2);
  unsigned int exp2 = 1;
  munit_assert_true(ts2 == exp2);

  unsigned int ts3 = joshephus_solver(14);
  unsigned int exp3 = 1;
  munit_assert_true(ts2 == exp3);

  unsigned int ts4 = joshephus_solver(7);
  unsigned int exp4 = 1;
  munit_assert_true(ts2 == exp4);

  unsigned int ts5 = joshephus_solver(8);
  unsigned int exp5 = 1;
  munit_assert_true(ts2 == exp5);

  return 0;
}

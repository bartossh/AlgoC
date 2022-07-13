#include "../munit/munit.h"
#include "./tries.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 256

bool test_basic() {
  struct Node *root = triecreate();
  if (root == NULL) {
    return false;
  }
  trieinsert(&root, "wojewoda");
  trieinsert(&root, "zapal");
  trieinsert(&root, "zapalniczka");
  trieinsert(&root, "woda");
  trieinsert(&root, "zapalnik");
  trieinsert(&root, "wodowanie");
  trieinsert(&root, "zapalki");
  trieinsert(&root, "zapalczywy");
  bool found = triefind(&root, "zapalczywy");

  printtrie(root);
  return found;
}

bool test_rand() {

  int r = rand() % (MAX + 1);

  return true;
}

int main() {
  bool ts0 = test_basic();
  munit_assert_true(ts0);
}

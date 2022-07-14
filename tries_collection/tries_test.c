#include "../munit/munit.h"
#include "./tries.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define LOOP 100000
#define ALPHABET_LENGTH 25

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

  trieprint(root);
  return found;
}

bool test_rand() {

  struct Node *root = triecreate();

  char alphabet[ALPHABET_LENGTH] = "abcdefghijklmnoprstuwqxyz";

  for (int i = 0; i < LOOP; i++) {
    int length = rand() % MAX;
    char *word = malloc(length * sizeof(char));
    for (int j = 0; j < length; j++) {
      int r = rand() % (ALPHABET_LENGTH);
      char letter = alphabet[r];
      word[j] = letter;
    }
    trieinsert(&root, word);
    if (!triefind(&root, word)) {
      return false;
    }
  }

  trieprint(root);

  return true;
}

int main() {
  bool ts0 = test_basic();
  munit_assert_true(ts0);

  bool ts1 = test_rand();
  munit_assert_true(ts1);
}

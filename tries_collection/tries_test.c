#include "../munit/munit.h"
#include "./tries.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define LOOP 100000
#define ALPHABET_LENGTH 25

bool test_basic()
{
    struct Node *root = trie_create();
    if (root == NULL)
    {
        return false;
    }
    trie_insert(&root, "wojewoda");
    trie_insert(&root, "zapal");
    trie_insert(&root, "zapalniczka");
    trie_insert(&root, "woda");
    trie_insert(&root, "zapalnik");
    trie_insert(&root, "wodowanie");
    trie_insert(&root, "zapalki");
    trie_insert(&root, "zapalczywy");
    bool found = trie_find(&root, "zapalczywy");

    trie_print(root);
    return found;
}

bool test_rand()
{

    struct Node *root = trie_create();

    char alphabet[ALPHABET_LENGTH] = "abcdefghijklmnoprstuwqxyz";

    for (int i = 0; i < LOOP; i++)
    {
        int length = rand() % MAX;
        char *word = malloc(length * sizeof(char));
        for (int j = 0; j < length; j++)
        {
            int r = rand() % (ALPHABET_LENGTH);
            char letter = alphabet[r];
            word[j] = letter;
        }
        trie_insert(&root, word);
        if (!trie_find(&root, word))
        {
            return false;
        }
    }

    trie_print(root);

    return true;
}

bool test_delete()
{
    struct Node *root = trie_create();
    if (root == NULL)
    {
        return false;
    }
    trie_insert(&root, "wojewoda");
    trie_insert(&root, "zapal");
    trie_insert(&root, "zapalniczka");
    trie_insert(&root, "woda");
    trie_insert(&root, "zapalnik");
    trie_insert(&root, "wodowanie");
    trie_insert(&root, "zapalki");
    trie_insert(&root, "zapalczywy");

    bool removed = trie_delete(&root, "zapalniczka");
    if (removed == false)
    {
        return false;
    }
    bool found = trie_find(&root, "zapalniczka");
    if (found == true)
    {
        return false;
    }
    found = trie_find(&root, "zapalnic");
    if (found == true)
    {
        return false;
    }
    found = trie_find(&root, "zapalnik");

    trie_print(root);
    return found;
}

int main()
{
    bool ts0 = test_basic();
    munit_assert_true(ts0);

    bool ts1 = test_rand();
    munit_assert_true(ts1);

    bool ts2 = test_delete();
    munit_assert_true(ts2);
}

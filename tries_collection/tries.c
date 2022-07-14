#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 256 // ASCII

typedef struct Node {
  struct Node *children[NUM_CHARS];
  bool terminal;
} Node;

/*
 * Function: trieinsert
 * --------------------
 * Inserts string of chars to the trei
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if string of chars inserted or false otherwise
 */
Node *triecreate() {
  Node *newnode = malloc(sizeof(*newnode));
  for (int i = 0; i < NUM_CHARS; i++) {
    newnode->children[i] = NULL;
  }
  newnode->terminal = false;
  return newnode;
}

/*
 * Function: trieinsert
 * --------------------
 * Inserts string of chars to the trei
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if new string of chars inserted or false otherwise
 */
bool trieinsert(Node **root, char *signedtext) {
  if (*root == NULL) {
    *root = triecreate();
  }
  unsigned char *text = (unsigned char *)signedtext;
  Node *tmp = *root;
  int length = strlen(signedtext);

  for (int i = 0; i < length; i++) {
    if (tmp->children[text[i]] == NULL) {
      tmp->children[text[i]] = triecreate();
    }
    tmp = tmp->children[text[i]];
  }

  if (tmp->terminal) {
    return false;
  }
  tmp->terminal = true;
  return true;
}

void printrec(Node *node, unsigned char *prefix, int length) {
  unsigned char newprefix[length + 2];
  memcpy(newprefix, prefix, length);
  newprefix[length + 1] = 0;

  if (node->terminal) {
    printf("WORD: %s\n", prefix);
  }

  for (int i = 0; i < NUM_CHARS; i++) {
    if (node->children[i] != NULL) {
      newprefix[length] = i;
      printrec(node->children[i], newprefix, length + 1);
    }
  }
}

/*
 * Function: printtrie
 * --------------------
 * Prints all stored strings of chars in to the stdout
 *
 * root: pointer to the trie tree
 *
 * returns: void
 */
void trieprint(Node *root) {
  if (root == NULL) {
    printf("TRIE <EMPTY>\n");
    return;
  }
  printrec(root, NULL, 0);
}

/*
 * Function: triefind
 * --------------------
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if string of chars exists, false otherwise
 */
bool triefind(Node **root, char *signedtext) {
  if (*root == NULL) {
    *root = triecreate();
  }
  unsigned char *text = (unsigned char *)signedtext;
  Node *tmp = *root;
  int length = strlen(signedtext);

  for (int i = 0; i < length; i++) {
    if (tmp->children[text[i]] == NULL) {
      return false;
    }
    tmp = tmp->children[text[i]];
  }

  if (tmp->terminal) {
    return true;
  }
  return false;
}

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
 * Function: trie_insert
 * --------------------
 * Inserts string of chars to the trei
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if string of chars inserted or false otherwise
 */
Node *trie_create() {
  Node *newnode = malloc(sizeof(*newnode));
  for (int i = 0; i < NUM_CHARS; i++) {
    newnode->children[i] = NULL;
  }
  newnode->terminal = false;
  return newnode;
}

/*
 * Function: trie_insert
 * --------------------
 * Inserts string of chars to the trei
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if new string of chars inserted or false otherwise
 */
bool trie_insert(Node **root, char *signedtext) {
  if (*root == NULL) {
    *root = trie_create();
  }
  unsigned char *text = (unsigned char *)signedtext;
  Node *tmp = *root;
  int length = strlen(signedtext);

  for (int i = 0; i < length; i++) {
    if (tmp->children[text[i]] == NULL) {
      tmp->children[text[i]] = trie_create();
    }
    tmp = tmp->children[text[i]];
  }

  if (tmp->terminal) {
    return false;
  }
  tmp->terminal = true;
  return true;
}

void print_rec(Node *node, unsigned char *prefix, int length) {
  unsigned char newprefix[length + 2];
  memcpy(newprefix, prefix, length);
  newprefix[length + 1] = 0;

  if (node->terminal) {
    printf("WORD: %s\n", prefix);
  }

  for (int i = 0; i < NUM_CHARS; i++) {
    if (node->children[i] != NULL) {
      newprefix[length] = i;
      print_rec(node->children[i], newprefix, length + 1);
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
void trie_print(Node *root) {
  if (root == NULL) {
    printf("TRIE <EMPTY>\n");
    return;
  }
  print_rec(root, NULL, 0);
}

/*
 * Function: trie_find
 * --------------------
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if string of chars exists, false otherwise
 */
bool trie_find(Node **root, char *signedtext) {
  if (*root == NULL) {
    *root = trie_create();
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

bool trie_free_empty(Node **root) {
  if (root == NULL) {
    return false;
  }


  bool found_terminal = false;
  for (int i = 0; i < NUM_CHARS; i++) {
    if ((*root)->children[i] != NULL) {
      bool term = trie_free_empty(&(*root)->children[i]);
      if (term == true) {
        found_terminal = true;
        continue;
      }
      free((*root)->children[i]);
      (*root)->children[i] = NULL;
    }
  }

  if (found_terminal == true) {
    return true;
  }

  if ((*root)->terminal == true) {
    return true;
  }


  return false;
}

/*
 * Function: trie_delete
 * --------------------
 *
 * root: pointer to the trie tree
 * signedtext: pointer to the signed string of chars
 *
 * returns: true if string of chars was successfully deleted, false otherwise (string may not exist)
 */
bool trie_delete(Node **root, char *signedtext) {
   if (*root == NULL) {
    *root = trie_create();
  }

  unsigned char *text = (unsigned char *)signedtext;
  Node *tmp = *root;
  int len = strlen(signedtext);

  for (int i = 0; i < len; i++) {
    if (tmp->children[text[i]] == NULL) {
      return false;
    }
    tmp = tmp->children[text[i]];
  }

  if (tmp->terminal == false) {
    return false;
  }

  tmp->terminal = false;
  trie_free_empty(root);
  return true;
}

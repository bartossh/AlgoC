#include <stdbool.h>

struct Node;

struct Node *trie_create();
bool trie_insert(struct Node **root, char *signedtext);
void trie_print(struct Node *root);
bool trie_find(struct Node **root, char *signedtext);
bool trie_delete(struct Node **root, char *signedtext);

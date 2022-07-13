#include <stdbool.h>

struct Node;

struct Node *triecreate();
bool trieinsert(struct Node **root, char *signedtext);
void printtrie(struct Node *root);
bool triefind(struct Node **root, char *signedtext);

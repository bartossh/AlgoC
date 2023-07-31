#include "binary_search_tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static node_t *tree_create_node(int data)
{
    node_t *node = malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

static void tree_traverse_append(node_t **root, int data)
{
    if ((*root) == NULL)
    {
        (*root) = tree_create_node(data);
        return;
    }
    node_t *current = *root;
    while (true)
    {
        if (current->data == data)
        {
            node_t *inter = tree_create_node(data); 
            inter->left = current->left;
            current->left = inter;
            return;
        }

        if (current->data > data)
        {
            if (current->left == NULL)
            {
                current->left = tree_create_node(data);
                break;
            }
            current = current->left;
            continue;
        }

        if (current->data < data)
        {
            if (current->right == NULL)
            {
                current->right = tree_create_node(data);
                break;
            }
            current = current->right;
            continue;
        }
    }
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    node_t *node = NULL;
    for (size_t i = 0; i < tree_data_len; i++)
    {
        tree_traverse_append(&node, tree_data[i]);
    }
    return node;
}

typedef struct {
    int *array;
    int cap;
    int len;

} slice_t;

static slice_t *slice_append(slice_t *s, int data)
{
    if (s == NULL)
    {
        int cap = 10;
        s = malloc(sizeof(slice_t));
        s->array = malloc(sizeof(int)*10);
        if (s->array == NULL)
        {
            exit(1);
        }
        s->cap = cap;
        s->len = 0;
    }
    if (s->len == s->cap)
    {
        s->cap *= 2;
        s->array = realloc(s->array, sizeof(int)*s->cap);
        if (s->array == NULL)
        {
            exit(1);
        }
    }
    s->array[s->len++] = data;
    return s;
}

static void slice_free(slice_t *s)
{
    free(s->array);
    free(s);
    s = NULL;
}

void free_tree(node_t *tree)
{
    if (tree == NULL)
    {
        return;
    }    

    if (tree->left != NULL)
    {
        free_tree(tree->left);
    }

    if (tree->right != NULL)
    {
        free_tree(tree->right);
    }

    free(tree);
    tree = NULL;
}

static slice_t *append_traverse_in_order_append_to_slice(node_t *next, slice_t *s)
{

    if (next == NULL)
    {
        return s;
    }

    if (next->left != NULL)
    {
        s = append_traverse_in_order_append_to_slice(next->left, s);
    }

    s = slice_append(s, next->data);

    if (next->right != NULL)
    {
        s = append_traverse_in_order_append_to_slice(next->right, s);
    }

    return s;
}

int *sorted_data(node_t *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    slice_t *s = append_traverse_in_order_append_to_slice(tree, NULL);

    int *result = malloc(sizeof(int)*s->len);
    void *p = memcpy(result, s->array, s->len*sizeof(int));
    if (p == NULL)
    {
        exit(1);
    }
    slice_free(s);
    return result;
}

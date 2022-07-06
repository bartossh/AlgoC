#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HASH_SIZE 500000

typedef struct dataitem {
    int unhashed_key;
    int value;
    struct dataitem* next;
} dataitem;

int pseudo_hash_function(int key) {
    return (int)(key % HASH_SIZE);
}

/*
 * Function: make_table
 * --------------------
 * Allocates table of pointer to dataitem struct
 *
 * returns: freshly allocated table of pointers to dataitem struct
 */
dataitem** make_table() {
    dataitem** table = calloc(HASH_SIZE, sizeof(dataitem*));
    return table;
}

/*
 * Function: insert_to_table
 * --------------------
 * Inserts value for given key to the table
 *
 * key: key at which we will keep the value
 * value: value we want to store
 * table: pointer to the table
 *
 * returns: void
 */
void insert_to_table(int key, int value, dataitem** table) {
    int hash_key = pseudo_hash_function(key);
    dataitem* item = table[hash_key];
    if (item == NULL) {
        dataitem* dt = malloc(sizeof(dataitem*));
        dt->value = value;
        dt->unhashed_key = key;
        dt->next = NULL;
        table[hash_key] = dt;
        return;
    }

    dataitem* bfr = item;
    item = item->next;
    while (item != NULL) {
        bfr = item;
        item = item->next;
    }

    dataitem* newItem = malloc(sizeof(dataitem*));
    newItem->value = value;
    newItem->unhashed_key = key;
    newItem->next = NULL;
    bfr->next = newItem;
}

void free_recursive(dataitem* item) {
    if (item->next != NULL) {
        free_recursive(item->next);
    }
    free(item);
}

/*
 * Function: free_table
 * --------------------
 * Frees the memory allocated in the heap by the table
 *
 * table: pointer to the table
 *
 * returns: void
 */
void free_table(dataitem** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        dataitem* item = table[i];

        if (item == NULL) {
            continue;
        }

        if (item->next != NULL) {
            free_recursive(item->next);
        }

        free(item);
    }

    free(table);
}

/*
 * Function: get_from_table
 * --------------------
 * Gets value stored at provided key
 *
 * key: key at which value is stored
 * table: pointer to the table
 *
 * returns: pointer to value stored at given key or NULL
 */
int* get_from_table(int key, dataitem** table) {
    int hash_key = pseudo_hash_function(key);
    dataitem* item = table[hash_key];

    if (item == NULL) {
        return NULL;
    }

    if (item->unhashed_key == key) {
        int* p = &item->value;
        return p;
    }

    dataitem* next = item->next;
    while (next != NULL) {
        if (next->unhashed_key == key) {
            int* p = &next->value;
            return p;
        }
        next = next->next; 
    }

    return NULL;
}

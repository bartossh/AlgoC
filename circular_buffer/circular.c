#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Typedef: circular_int
 * --------------------
 * Structure holding circular buffer functionality.
 *
 */
typedef struct circular_int
{
    int *buf;
    int pos;
    int size;
} circular_int;

/*
 * Function: new_circular_int
 * --------------------
 * Creates a pointer to new circular_int buffer.
 * size: size of circular_int buffer
 *
 * returns: pointer to circular_int
 */
circular_int *new_circular_int(int size)
{
    if (size == 0)
        exit(1);
    int *buf = calloc(sizeof(int), size);
    circular_int *c = malloc(sizeof(circular_int));
    c->buf = buf;
    c->pos = 0;
    c->size = size;
    return c;
}

/*
 * Function: circular_int_set
 * --------------------
 * Sets value at given position.
 * v: value to set
 *
 * returns: position
 */
int circular_int_set(circular_int *c, int v)
{
    c->buf[c->pos] = v;
    return c->pos;
}

/*
 * Function: circular_int_next
 * --------------------
 * Set iterator to the next position in the buffer.
 *
 * returns: position
 */
int circular_int_next(circular_int *c)
{
    c->pos++;
    if (c->pos == c->size)
    {
        c->pos = 0;
    }
    return c->pos;
}

/*
 * Function: circular_int_prev
 * --------------------
 * Set iterator to the previous position in the buffer.
 *
 * returns: position
 */
int circular_int_prev(circular_int *c)
{
    c->pos--;
    if (c->pos == -1)
    {
        c->pos = c->size - 1;
    }
    return c->pos;
}

/*
 * Function: circular_int_get
 * --------------------
 * Gets the value at given position.
 *
 * returns: value at given position
 */
int circular_int_get(circular_int *c)
{
    return c->buf[c->pos];
}

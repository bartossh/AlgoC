#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Typedef: fifo_int
 * --------------------
 * Structure holding fifo buffer functionality.
 *
 */
typedef struct fifo_int
{
    int *buf;
    int cap;
    int len;
} fifo_int;

/*
 * Function: new_fifo_int
 * --------------------
 * Creates a pointer to new fifo_int buffer.
 * cap: capacity of fifo buffer
 *
 * returns: pointer to fifo_int
 */
fifo_int *new_fifo_int(int cap)
{
    if (cap < 0)
        exit(1);
    int *buf = calloc(sizeof(int), cap);
    fifo_int *c = malloc(sizeof(fifo_int));
    c->len = 0;
    c->cap = cap;
    c->buf = buf;
    return c;
}

/*
 * Function: push
 * --------------------
 * Pushes value to the buffer
 * Doubles the capacity if capacity is reached.
 * c: fifo_int
 * v: value to append
 *
 * returns: void
 */
void push(fifo_int *c, int v)
{
    if (c->buf == NULL)
    {
        c->buf = malloc(sizeof(int));
    }
    if (c->len == c->cap)
    {
        c->cap += c->cap;
        int *buf = (int *)realloc(c->buf, c->cap * sizeof(int));
        if (buf == NULL)
            exit(1);
        c->buf = buf;
    }
    c->buf[c->len] = v;
    c->len++;
}

/*
 * Function: pull
 * --------------------
 * Pulls value from the fifo buffer
 * c: fifo_int
 *
 * returns: int
 */
int pull(fifo_int *c)
{
    int *buf;
    if (c->len == 0 || c->buf == NULL)
    {
        exit(1);
    }

    int v = c->buf[0];

    switch (c->len)
    {
    case 1:
        c->buf = NULL;
        c->len--;
        break;
    default:
        buf = (int *)malloc((c->cap) * sizeof(int));
        if (buf == NULL)
            exit(1);
        memcpy(buf, c->buf + 1, c->cap * sizeof(int));
        c->buf = buf;
        c->len--;
    }

    return v;
}

/*
 * Function: pull_f
 * --------------------
 * Pulls value from the fifo buffer fast
 * c: fifo_int
 *
 * returns: int
 */
int pull_f(fifo_int *c)
{
    int *buf;
    if (c->len == 0 || c->buf == NULL)
    {
        exit(1);
    }

    int v = c->buf[0];

    for (int i = 0; i < c->len - 1; i++)
    {
        c->buf[i] = c->buf[i + 1];
    }

    c->len--;
    return v;
}
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
 * Function: fifo_push
 * --------------------
 * Pushes value to the buffer
 * Doubles the capacity if capacity is reached.
 * c: fifo_int
 * v: value to append
 *
 * returns: void
 */
void fifo_push(fifo_int *c, int v)
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
 * Function: fifo_pull_alloc
 * --------------------
 * Pulls value from the fifo buffer
 * c: fifo_int
 *
 * returns: int value kept in the buffer in fifo order
 */
int fifo_pull_alloc(fifo_int *c)
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
 * Function: fifo_pull_iter
 * --------------------
 * Pulls value from the fifo buffer with interation
 * c: fifo_int
 *
 * returns: int value kept in the buffer in fifo order
 */
int fifo_pull_iter(fifo_int *c)
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

/*
 * Function: fifo_free
 * --------------------
 * Frees memory hold by the fifo_int
 * c: fifo_int
 *
 * returns: void
 */
void fifo_free(fifo_int *c)
{
    free(c->buf);
    c->buf = NULL;
}

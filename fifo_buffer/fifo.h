typedef struct fifo_int fifo_int;
fifo_int *new_fifo_int(int cap);
void fifo_push(fifo_int *c, int v);
int fifo_pull_alloc(fifo_int *c);
int fifo_pull_iter(fifo_int *c);
void fifo_free(fifo_int *c);

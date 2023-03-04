typedef struct fifo_int fifo_int;
fifo_int *new_fifo_int(int cap);
void push(fifo_int *c, int v);
int pull(fifo_int *c);
int pull_f(fifo_int *c);

typedef struct circular_int circular_int;
circular_int *new_circular_int(int size);
int circular_int_set(circular_int *c, int v);
int circular_int_get(circular_int *c);
int circular_int_next(circular_int *c);
int circular_int_prev(circular_int *c);

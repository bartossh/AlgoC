#include <stdbool.h>

double get_time();
void bench_1_000_000(void (*sort)(int *, int));
void bench_1_000_000_dynamic(void (*sort)(int *, int));
bool test_long(void (*sort)(int *, int));
bool test_simple(void (*sort)(int *, int));
bool test_mixed(void (*sort)(int *, int));
bool test_dynamic_alloc(void (*sort)(int *, int));

#define LEN_SHORT 11
#define LEN_LONG 31
#define LEN_EXTRIME 10000000

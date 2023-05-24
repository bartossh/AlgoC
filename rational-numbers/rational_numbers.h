#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stdlib.h>

typedef struct
{
    int numerator;
    int denominator;
} rational_t;

int biggest_common_divisor(int a, int b);
rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r1);
rational_t exp_rational(rational_t r, short n);
float exp_real(unsigned short x, rational_t r);
rational_t reduce(rational_t r1);

#endif

#include "rational_numbers.h"
#include <math.h>

int biggest_common_divisor(int a, int b)
{
    int divisor = a < b ? a : b;
    if (divisor == 0)
    {
        return 1;
    }

    while (divisor > 1)
    {
        if (a % divisor == 0 && b % divisor == 0)
        {
            break;
        }
        divisor--;
    }

    return divisor;
}

rational_t reduce(rational_t r)
{
    rational_t nr = {r.numerator, r.denominator};

    if (nr.numerator == 0)
    {
        nr.denominator = 1;
        return nr;
    }

    int div = biggest_common_divisor(abs(nr.numerator), abs(nr.denominator));

    while (div > 1)
    {
        nr.numerator /= div;
        nr.denominator /= div;
        div = biggest_common_divisor(abs(nr.numerator), abs(nr.denominator));
    }
    if ((nr.numerator > 0 && nr.denominator < 0) || (nr.numerator < 0 && nr.denominator < 0))
    {

        nr.numerator = -nr.numerator;
        nr.denominator = -nr.denominator;
    }

    return nr;
}

rational_t add(rational_t r1, rational_t r2)
{
    rational_t rational;
    rational.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    rational.denominator = r1.denominator * r2.denominator;
    return reduce(rational);
}

rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t rational;
    rational.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    rational.denominator = r1.denominator * r2.denominator;
    return reduce(rational);
}

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t rational;
    rational.numerator = r1.numerator * r2.numerator;
    rational.denominator = r1.denominator * r2.denominator;
    return reduce(rational);
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t rational;
    rational.numerator = r1.numerator * r2.denominator;
    rational.denominator = r1.denominator * r2.numerator;
    return reduce(rational);
}

rational_t absolute(rational_t r1)
{
    rational_t rational;
    rational.numerator = abs(r1.numerator);
    rational.denominator = abs(r1.denominator);
    return reduce(rational);
}

rational_t exp_rational(rational_t r, short n)
{
    rational_t rational;
    if (n > 0)
    {
        rational.numerator = (int)pow((double)r.numerator, (double)n);
        rational.denominator = (int)pow((double)r.denominator, (double)n);
    }
    else
    {
        rational.numerator = (int)pow((double)r.denominator, (double)abs(n));
        rational.denominator = (int)pow((double)r.numerator, (double)abs(n));
    }

    return reduce(rational);
}

float exp_real(unsigned short x, rational_t r)
{
    return (float)pow((double)x, ((double)r.numerator / (double)r.denominator));
}

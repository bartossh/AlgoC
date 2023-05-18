#include "collatz_conjecture.h"
#include <limits.h>

int steps(int start)
{
    if (start <= 0)
    {
        return ERROR_VALUE;
    }

    if (start >= INT_MAX / 2 + 1)
    {
        return ERROR_VALUE;
    }

    if (start == 1)
    {
        return 0;
    }

    int counter = 0;
    while (start > 1)
    {
        if (start % 2 == 0)
        {
            start = start / 2;
            counter++;
            continue;
        }
        start = 3 * start + 1;
        counter++;
    }

    return counter;
}

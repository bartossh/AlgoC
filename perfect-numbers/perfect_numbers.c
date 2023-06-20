#include "perfect_numbers.h"

kind classify_number(int num)
{

    if (num <= 0)
    {
        return ERROR;
    }

    int sum  = 0;
    int candidate = num/2;

    while (candidate > 0)
    {
        if (num % candidate == 0)
        {
            sum += candidate;
        }
        candidate--;
    }

    if (sum > num)
    {
        return ABUNDANT_NUMBER;
    }

    if (sum < num)
    {
        return DEFICIENT_NUMBER;
    }

    return PERFECT_NUMBER; 

}

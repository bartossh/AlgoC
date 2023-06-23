#include "luhn.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool luhn(const char *num)
{
    int len = strlen(num);
    
    size_t count = 0;
    size_t sum = 0;
    
    for (int i = len-1; i >= 0; i--)
    {
        if (num[i] == ' ')
        {
            continue;
        }
        if (!isdigit(num[i]))
        {
            return false;
        }
 
        size_t n = num[i] - 48;
        if (++count % 2 == 0)
        {
            n = n * 2;
            if (n > 9)
            {
                n = n - 9;
            }
        }

        sum += n;
    }

    if (count < 2)
    {
        return false;
    }

    return sum % 10 == 0;
}

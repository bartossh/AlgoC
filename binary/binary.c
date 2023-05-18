#include "binary.h"

int convert(const char *input)
{
    int result = 0;
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '1')
        {
            result = result * 2 + 1;
        }
        else if (input[i] == '0')
        {
            result = result * 2;
        }
        else
        {
            return INVALID;
        }
        i++;
    }
    return result;
}

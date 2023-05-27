#include "phone_number.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char *phone_number_clean(const char *input)
{
    char *numbers = malloc(sizeof(char)* 13);
    int next = 0;
    int len = strlen(input);
    for (int i = 0; i < len && next < 12; i++)
    {
        if (isdigit(input[i]))
        {
            numbers[next++] = input[i];
        }
    }
    numbers[next] = '\0';
    
    int numLen = strlen(numbers);
    bool f1 = numLen == 11 && (numbers[0] != '1' || numbers[1] < '2' || numbers[4] < '2');
    bool f2 = numLen > 11 || numLen < 10;
    bool f3 = numLen == 10 && (numbers[0] < '2' || numbers[3] < '2');

    char *result = malloc(sizeof(char)*11);
    
    if (f1 || f2 || f3)
    {
        for (int i = 0; i < 10; i++)
        {
            result[i] = '0';
        }
        result[10] = '\0';

        return result;
    }
    
    int n = 0;
    for (int i = numLen - 10; i < numLen; i++)
    {
        result[n++] = numbers[i];
    }
    result[10] = '\0';

    return result;
}

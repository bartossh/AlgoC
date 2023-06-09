#include "roman_numerals.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const uint32_t nums[7] = {1000, 500, 100, 50, 10, 5, 1};
const char roman[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

const char *patterns[] = {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};
const char *replace[] = {"CM", "CD", "XC", "XL", "IX", "IV"};

char *replace_with(char str[], const char substr[], const char replace[])
{

    int i = 0, j = 0, flag = 0, start = 0;

    while (str[i] != '\0')
        {
                if (str[i] == substr[j]) 
                {
                        if (!flag)
                                start = i;
                        j++;
                        if (substr[j] == '\0')
                                break;
                        flag = 1;
                } 
                else 
                {
                        flag = start = j = 0;
                }
                i++;
        }
    if (substr[j] == '\0' && flag)
    {
        char *output = malloc(sizeof(char)* strlen(str));

        for (i = 0; i < start; i++)
        {
            output[i] = str[i];
        }

        for (j = 0; j < (int)strlen(replace); j++) 
        {
                output[i] = replace[j];
                i++;
        }
        for (j = start + (int)strlen(substr); j < (int)strlen(str); j++)
        {
                output[i] = str[j];
                i++;
        }
        output[i] = '\0';

        return output;
    }
    

    return str;
}

char *to_roman_numeral(uint32_t number)
{

    char result[100];
    size_t idx = 0; 
    size_t n = 0;
    
    while (n < 7)
    {
        if (n == 6 && number > 0)
        {
            result[idx++] = roman[n];
            number -= 1;
            continue;
        }
        if (number / nums[n] > 0)
        {
            result[idx++] = roman[n];
            number -= nums[n];
            continue;
        }
        n++;
    }

    char *res = malloc(sizeof(char)*idx+1);
    
    for (size_t i = 0; i < idx; i++)
    {
        res[i] = result[i];
    }

    res[idx] = '\0';

    for (int i = 0; i < 6; i++)
    {
        res = replace_with(res, patterns[i], replace[i]);
    }

    return res;
}

#include "matching_brackets.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

const char a = '(';
const char b = '[';
const char c = '{';
const char a_o = ')';
const char b_o = ']';
const char c_o = '}';

bool is_bracket(char v)
{
    return v == a || v == b || v == c || v == a_o || v == b_o || v == c_o;
}

bool is_paired(const char *input)
{
    size_t len = strlen(input);
    char *last_to_close = calloc(sizeof(char), len+1);
    last_to_close[len] = '\0';
    size_t idx = 0;

    for (size_t i = 0; i < len; i++)
    {
        char v = input[i];
        
        if (!is_bracket(v))
        {
            continue;
        }

        if (v == a)
        {
            last_to_close[idx++] = a_o;
            continue;
        }
        if (v == b)
        {
            last_to_close[idx++] = b_o;
            continue;
        }
        if (v == c)
        {
            last_to_close[idx++] = c_o;
            continue;
        }

        if (idx > 0 && v != last_to_close[idx-1])
        {
            free(last_to_close);
            return false;
        }

        if (v == a_o && idx > 0)
        {
            last_to_close[idx--] = '*';
            continue;
        }
        if (v == b_o && idx > 0)
        {
            last_to_close[idx--] = '*';
            continue;
        }
        if (v == c_o && idx > 0)
        {
            last_to_close[idx--] = '*';
            continue;
        }

        free(last_to_close);
        return false;
    }
    
    free(last_to_close);
    return idx == 0;
}

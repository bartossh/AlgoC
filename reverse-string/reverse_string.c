#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value)
{

    size_t len = strlen(value);
    char *rev = malloc(sizeof(char) * len+1);
    rev[len] = '\0';

    size_t i = 0;
    size_t j = len-1;

    while(i < len)
    {
        rev[i++] = value[j--];
    }

    return rev;
}

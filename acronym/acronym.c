#include "acronym.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{
    if (phrase == NULL)
    {
        return NULL;
    }

    size_t len = strlen(phrase);
    if (len == 0)
    {
        return NULL;
    }

    char *acronym = calloc(sizeof(char), len);
    if (acronym == NULL)
    {
        return NULL;
    }

    size_t next = 0;
    int was_space = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (phrase[i] == ' ' ||
            phrase[i] == '-' ||
            phrase[i] == '_')
        {
            was_space = 1;
            continue;
        }

        if ((was_space || i == 0) && isalpha(phrase[i]))
        {
            acronym[next++] = toupper(phrase[i]);
            was_space = 0;
        }
    }

    return acronym;
}

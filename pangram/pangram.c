#include "pangram.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const size_t LETTERS_NUM = 26;

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
    {
        return false;
    }

    if (strlen(sentence) < LETTERS_NUM)
    {
        return false;
    }

    int letters[26];

    for (size_t i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }

    size_t counter = 0;

    for (size_t i = 0; i < strlen(sentence); i++)
    {
        char l = tolower(sentence[i]);
        if (l >= 'a' && l <= 'z')
        {
            int position = l - 'a';
            if (letters[position] == 0)
            {
                counter++;
            }
            letters[position] = 1;
        }
    }

    return counter == LETTERS_NUM;
}

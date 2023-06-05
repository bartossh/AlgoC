#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *encode(char *text, size_t rails)
{
    if (rails == 1)
    {
        return text;
    }

    size_t len = strlen(text);
    char rail[rails][len];

    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            rail[i][j] = '*';
        }
    }

    bool dir_down = false;
    size_t row = 0, col = 0;

    for (size_t i = 0; i < len; i ++)
    {
        if (row == 0 || row == rails - 1)
        {
            dir_down = !dir_down;
        }

        rail[row][col++] = text[i];

        if (dir_down)
        {
            row++;
        } else {
            row--;
        }
    }


    char * result = malloc(sizeof(char)*(len+1));
    size_t next = 0;
    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (rail[i][j] != '*')
            {
                result[next++] = rail[i][j];
            }
        }
    }
    result[len] = '\0';
    
    return result;
}


char *decode(char *ciphertext, size_t rails)
{
    if (rails == 1)
    {
        return ciphertext;
    }
    
    size_t len = strlen(ciphertext);
    char rail[rails][len];

    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            rail[i][j] = '*';
        }
    }

    bool dir_down = false;
    size_t row = 0, col = 0;

    for (size_t i = 0; i < len; i ++)
    {
        if (row == 0 || row == rails - 1)
        {
            dir_down = !dir_down;
        }

        rail[row][col++] = '?';

        if (dir_down)
        {
            row++;
        } else {
            row--;
        }
    }

    size_t idx = 0;

    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (rail[i][j] == '?' &&  idx < len)
            {
                rail[i][j] = ciphertext[idx++];
            }
        }
    }


    char * result = malloc(sizeof(char)*(len+1));
    size_t next = 0;
    row = 0, col = 0;
    for (size_t i=0; i< len; i++)
    {
        if (row == 0)
        {
            dir_down = true;
        }
        if (row == rails-1)
        {
            dir_down = false;
        }
 
        if (rail[row][col] != '*')
        {
            result[next++] = rail[row][col++]; 
        }
 
        if (dir_down)
        {
            row++;
        } else {
            row--;
        }
    }

    result[len] = '\0';
    
    return result;
}

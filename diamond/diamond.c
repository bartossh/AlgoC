#include "diamond.h"
#include <stdlib.h>
#include <string.h>

void set(char *original, int len, int pos, char l)
{    
    for (int i = 0; i < len; i++)
    {
        if (i == pos || i == (len - 1 - pos)) 
        {
            original[i] = l;
            continue;
        }
        original[i] = ' ';
    }
    original[len] = '\0';
}

char **make_diamond(const char letter)
{
    if (letter < 'A' || letter > 'Z') {
        return NULL;
    }
    
    if (letter == 'A')
    {
        char *line = malloc(sizeof(char)*2);
        line[0] = 'A';
        line[1] = '\0';
        char **result = malloc(sizeof(char*));
        result[0] = line;
        return result;
    }


    char **result = malloc(sizeof(char*)* (2*(letter- 'A') + 1)); 
    int next = 0;
    char l = 'A';
    int l_size = 2*(letter - 'A') + 1;
    int pos = letter - 'A';

    while (l <= letter)
    {
        char *line = malloc(sizeof(char*)*l_size+1);
        set(line, l_size, pos, l);
        l++;
        pos--;
        result[next++] = line;
    }

    int previus = next - 2;
    while(previus >= 0)
    {
        result[next++] = result[previus--];
    }

    return result;
}

void free_diamond(char **diamond)
{
    if (diamond == NULL)
    {
        return;
    }
    free(diamond);
    diamond = NULL;
}

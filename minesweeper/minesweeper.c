#include "minesweeper.h"
#include <stdlib.h>
#include <string.h>

void count_and_mark(char **annotation, int i, int j, int rows, int len)
{
    for (int x = i - 1; x <= i + 1; x++)
    {
        for (int y = j - 1; y <= j + 1; y++)
        {
            if (x >= 0 && y >= 0 && x < rows && y < len && annotation[x][y] != '*')
            {
                if (annotation[x][y] == ' ')
                {
                    annotation[x][y] = '1';
                } 
                else
                {
                    annotation[x][y]++;
                }
            }
        }
    }
}

char **annotate(const char **minefield, const size_t rows)
{
    if (minefield == NULL)
    {
        return NULL;
    }

    size_t len = strlen(minefield[0]);
    char **annotation = malloc(sizeof(char*) * rows);
    for (size_t i = 0; i < rows; i++)
    {
        char *line = malloc(sizeof(char) * len+1);
        for (size_t j = 0; j < len; j++)
        {
            line[j] = minefield[i][j];
        }
        line[len] = '\0';
        annotation[i] = line;
    } 

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (minefield[i][j] == '*')
            {
                count_and_mark(annotation, (int)i, (int)j, (int)rows, (int)len);
            }
        }
    }
 
    return annotation;
}


void free_annotation(char **annotation)
{
    if (annotation == NULL)
    {
        return;
    }
    free(annotation);
}

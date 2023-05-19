#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
    if (rows > 255)
    {
        return NULL;
    }

    size_t alloc_rows = rows;
    if (rows == 0)
    {
        alloc_rows = 1;
    }

    uint8_t **triangle = malloc(sizeof(uint8_t *) * alloc_rows);
    if (rows == 1 || rows == 0)
    {
        triangle[0] = malloc(sizeof(uint8_t));
        triangle[0][0] = rows;
        return triangle;
    }

    for (size_t i = 0; i < rows; i++)
    {
        triangle[i] = malloc(sizeof(uint8_t) * (rows));
        triangle[i][0] = 1;

        if (i == 0)
        {
            for (size_t j = 1; j < rows; j++)
            {
                triangle[i][j] = 0;
            }
            continue;
        }

        for (size_t j = 0; j < rows; j++)
        {
            if (j == 0)
            {
                triangle[i][j] = 1;
                continue;
            }
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

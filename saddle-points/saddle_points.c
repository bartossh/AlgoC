#include "saddle_points.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool is_biggest_in_row(int rows, int columns, int r, int c, unsigned char matrix[rows][columns])
{
    for (int i = 0; i < columns; i++)
    {
        if (i == c)
        {
            continue;
        }
        if (matrix[r][c] < matrix[r][i])
        {
            return false;
        }
    }
    return true;
}

bool is_smallest_in_column(int rows, int columns, int r, int c, unsigned char matrix[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        if (i == r)
        {
            continue;
        }
        if (matrix[r][c] > matrix[i][c])
        {
            return false;
        }
    }

    return true;
}


saddle_points_t *saddle_points(int rows, int columns, unsigned char matrix[rows][columns])
{
    saddle_points_t *points = malloc(sizeof(saddle_points_t));
    points->points = malloc(sizeof(saddle_point_t));
    points->count = 0;
    int capacity = 1;
    
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (!is_biggest_in_row(rows, columns, r, c, matrix) || !is_smallest_in_column(rows, columns, r, c, matrix))
            {
                continue;   
            }
            if (points->count == capacity)
            {
                capacity++;
                points->points = realloc(points->points, sizeof(saddle_points_t)*capacity);
            }
            saddle_point_t point = {r+1, c+1};
            points->points[points->count++] = point; 
        }
    }

    return points;

}

void free_saddle_points(saddle_points_t *actual)
{
    free(actual);
}

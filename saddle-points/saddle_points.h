#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdbool.h>

typedef struct saddle_point_t
{
    int row;
    int column;
} saddle_point_t;

typedef struct saddle_points_t
{
    int count;
    saddle_point_t *points;
} saddle_points_t;

bool is_biggest_in_row(int rows, int columns, int r, int c, unsigned char matrix[rows][columns]);
bool is_smallest_in_column(int rows, int columns, int r, int c, unsigned char matrix[rows][columns]);
saddle_points_t *saddle_points(int row, int column, unsigned char matrix[row][column]);
void free_saddle_points(saddle_points_t *actual);

#endif

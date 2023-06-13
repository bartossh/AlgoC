#ifndef TRIANGLE_H
#include <stdbool.h>

#define TRIANGLE_H

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

bool is_zero(triangle_t sides);
bool is_triangle(triangle_t sides);
bool is_scalene(triangle_t);
bool is_isosceles(triangle_t);
bool is_equilateral(triangle_t);

#endif

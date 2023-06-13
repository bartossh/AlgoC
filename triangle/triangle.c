#include "triangle.h"
#include <stdbool.h>


bool is_zero(triangle_t sides)
{
    return (sides.a == 0) || (sides.b == 0) || (sides.c == 0);
}

bool is_triangle(triangle_t sides)
{
    return !is_zero(sides) && (sides.a + sides.b >= sides.c) && (sides.b + sides.c >= sides.a) && (sides.a + sides.c >= sides.b);
}
bool is_scalene(triangle_t sides) 

{
   return is_triangle(sides) && (sides.a != sides.b) && (sides.b != sides.c) && (sides.c != sides.a); 
}


bool is_equilateral(triangle_t sides)
{
    return is_triangle(sides) && (sides.a == sides.b) && (sides.b == sides.c); 
}

bool is_isosceles(triangle_t sides)
{
    return is_triangle(sides) && (is_equilateral(sides) || !is_scalene(sides));
}


#include "darts.h"
#include <math.h>

const double OUTER = 10.0F;
const double MIDDLE = 5.0F;
const double INNER = 1.0F;

uint8_t
score(coordinate_t landing_position)
{
    double dist = sqrt(landing_position.x * landing_position.x + landing_position.y * landing_position.y);
    if (dist > OUTER)
    {
        return 0;
    }
    if (dist > MIDDLE)
    {
        return 1;
    }
    if (dist > INNER)
    {
        return 5;
    }
    return 10;
}

#include "space_age.h"

const float EarthYear = 31557600;
const float AgeTable[8] = {
    0.2408467,
    0.61519726,
    1,
    1.8808158,
    11.862615,
    29.447498,
    84.016846,
    164.79132,
};

float age(planet_t planet, int64_t seconds)
{
    if (planet > 7 || planet < 0)
    {
        return -1;
    }

    return ((float)seconds / EarthYear) / AgeTable[planet];
}

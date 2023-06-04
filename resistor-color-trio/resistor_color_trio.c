#include "resistor_color_trio.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>

resistor_value_t color_code(const resistor_band_t resistors[3]) {
    resistor_value_t result;
    result.unit = OHMS;
    long unit = (long)pow((double)10, (double)resistors[2]);
    result.value = (resistors[0] * 10 + resistors[1]) * unit;
    
    if (result.value / KILOOHMS > 0)
    {
        result.unit = KILOOHMS;
        result.value = result.value / KILOOHMS;
    }

    return result;
}

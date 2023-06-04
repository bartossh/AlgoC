#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

typedef enum {
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
}resistor_band_t;

typedef enum {
    OHMS = 0,
    KILOOHMS = 1000,
} unit;


typedef struct {
    uint32_t value;
    unit unit;
} resistor_value_t;

resistor_value_t color_code(const resistor_band_t resistors[3]);

#endif

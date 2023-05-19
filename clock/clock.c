#include "clock.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    strncpy(clock.text, "00:00\0", MAX_STR_LEN);
    clock = clock_add(clock, minute + hour * 60);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    char hours[3];
    char minutes[3];
    for (size_t i = 0; i < strlen(clock.text); i++)
    {
        if (i < 2)
        {
            hours[i] = clock.text[i];
            continue;
        }
        if (i == 2)
        {
            continue;
        }

        minutes[i - 3] = clock.text[i];
    }

    int total = atoi(hours) * 60 + atoi(minutes) + minute_add;
    while (total < 0)
    {
        total = 24 * 60 + total;
    }

    int h = (total / 60) % 24;
    int m = total % 60;

    snprintf(clock.text, MAX_STR_LEN, "%02i:%02i", h, m);

    return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    return clock_add(clock, minute_subtract * -1);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return strcmp(a.text, b.text) == 0;
}

#include "two_fer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name)
{
    if (name == NULL)
    {
        snprintf(buffer, 25, "One for you, one for me.");
        return;
    }

    snprintf(buffer, strlen(name) + 22, "One for %s, one for me.", name);
}

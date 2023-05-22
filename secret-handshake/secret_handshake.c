#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

const size_t HandshakeSize = 4;
const size_t MaxWordSize = 16;

const char **
commands(size_t number)
{
    const char **handshake = calloc(sizeof(char *), HandshakeSize);
    int next = 0;

    if (number & 1)
    {
        char *w = malloc(sizeof(char) * MaxWordSize);
        strncpy(w, "wink\0", MaxWordSize);
        handshake[next++] = w;
    }

    if (number & 2)
    {
        char *w = malloc(sizeof(char) * MaxWordSize);
        strncpy(w, "double blink\0", MaxWordSize);
        handshake[next++] = w;
    }

    if (number & 4)
    {
        char *w = malloc(sizeof(char) * MaxWordSize);
        strncpy(w, "close your eyes\0", MaxWordSize);
        handshake[next++] = w;
    }

    if (number & 8)
    {
        char *w = malloc(sizeof(char) * MaxWordSize);
        strncpy(w, "jump\0", MaxWordSize);
        handshake[next++] = w;
    }

    if (!(number & MaxWordSize))
    {
        return handshake;
    }

    const char **reversed = calloc(sizeof(char *), HandshakeSize);

    next--;
    size_t j = 0;
    while (next > -1)
    {
        reversed[j++] = handshake[next--];
    }
    free(handshake);

    return reversed;
}

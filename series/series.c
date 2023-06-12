#include "series.h"
#include <string.h>
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length)
{
    slices_t sl; 

    size_t len = strlen(input_text); 

    if (len == 0 || input_text == NULL || len < substring_length || substring_length == 0)
    {
        sl.substring = NULL;
        sl.substring_count = 0;
        return sl;
    }
 
    size_t diff = len - substring_length + 1;
    sl.substring = malloc(sizeof(char*) * diff);
    for (size_t i = 0; i < diff; i++)
    {
        char *substring = malloc(sizeof(char) * substring_length+1);
        for (size_t j = 0; j < substring_length; j++)
        {
            substring[j] = input_text[i+j];
        }
        substring[substring_length] = '\0';
        sl.substring[i] = substring;
    }

    sl.substring_count = diff;
    return sl;
}

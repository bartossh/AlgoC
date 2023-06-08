#include "raindrops.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const char f_3[5] = "Pling"; 
const char f_5[5] = "Plang"; 
const char f_7[5] = "Plong";

void convert(char result[], int drops)
{
    size_t next = 0;
    if (drops % 3 == 0) 
    {
        for (size_t i = 0; i < 5; i++)
        {
            result[next++] = f_3[i];
        }
    }
     
    if (drops % 5 == 0) 
    {
        for (size_t i = 0; i < 5; i++)
        {
            result[next++] = f_5[i];
        }
    }
    
    if (drops % 7 == 0) 
    {
        for (size_t i = 0; i < 5; i++)
        {
            result[next++] = f_7[i];
        }
    }

    if (next != 0)
    {
        return;
    }

    size_t n = floor (log10 (abs (drops))) + 1;
    snprintf(result, sizeof(int)*n, "%d", drops);
}

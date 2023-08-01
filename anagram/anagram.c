#include "anagram.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

static int sort_compare(const void *a, const void *b)
{
    return strcmp((const char*)a, (const char*)b);
}
 
static void sort(const char* str, int n)
{
    qsort((void *)str, n, sizeof(const char), sort_compare);
}

static void to_lower_case(char *str, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

static bool str_compare(const char *a, const char *b, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}


void find_anagrams(const char *subject, struct candidates *candidates)
{
    size_t sub_len = strlen(subject);
    if (sub_len >= MAX_STR_LEN)
    {
        exit(1);
    }
    
    char lower_subject[MAX_STR_LEN];
    char *cp = strncpy(lower_subject, subject, sub_len);
    if (cp == NULL)
    {
        exit(1);
    }
    lower_subject[sub_len] = '\0';
    to_lower_case(lower_subject, sub_len); 
    
    char sort_subject[MAX_STR_LEN];
    cp = strncpy(sort_subject, lower_subject, sub_len);
    if (cp == NULL)
    {
        exit(1);
    }
    sort_subject[sub_len] = '\0';
    sort(sort_subject, sub_len);

    for (size_t i = 0; i < candidates->count; i++)
    {
        struct candidate c =  candidates->candidate[i];
        size_t c_len = strlen(c.word);
        if (c_len != sub_len)
        {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }
 
        char sort_c[MAX_STR_LEN];
        cp = strncpy(sort_c, c.word, c_len);
        if (cp == NULL)
        {
            exit(1);
        }
        sort_c[c_len] = '\0';
        to_lower_case(sort_c, c_len);
        if (str_compare(sort_c, lower_subject, sub_len))
        {            
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }
        sort(sort_c, c_len);
        if (!str_compare(sort_subject, sort_c, sub_len))
        {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue; 
        }
        candidates->candidate[i].is_anagram = IS_ANAGRAM;
    }
}

#include "word_count.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void apply_word(char *word, word_count_word_t *words, size_t len)
{
    size_t w_len = strlen(word);
    if (!w_len)
    {
        return;
    }

    if (word[w_len - 1] == '\'')
    {
        w_len = w_len - 1;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (strlen(words[i].text) != w_len)
        {
            continue;
        }
        if (strncmp(words[i].text, word, w_len) == 0)
        {
            words[i].count++;
            return;
        }
    }

    for (size_t i = 0; i < len; i++)
    {
        if (strlen(words[i].text) == 0)
        {
            strncpy(words[i].text, word, w_len);
            words[i].count = 1;
            return;
        }
    }
}

int count_all_words(word_count_word_t *words, size_t len)
{
    size_t word_count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (words[i].count)
        {
            word_count++;
        }
    }
    return word_count;
}

int count_words(const char *sentence, word_count_word_t *words)
{
    if (sentence == NULL)
    {
        return 0;
    }
    if (words == NULL)
    {
        return 0;
    }

    size_t len = strlen(sentence);
    if (len == 0)
    {
        return 0;
    }

    char *local_str = calloc(sizeof(char), MAX_WORD_LENGTH);
    size_t next = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (!isalnum(sentence[i]) && sentence[i] != '\'')
        {
            if (next != 0)
            {
                apply_word(local_str, words, MAX_WORDS);
                local_str = calloc(sizeof(char), MAX_WORD_LENGTH);
                next = 0;
            }
            continue;
        }

        if (next > MAX_WORD_LENGTH)
        {
            free(local_str);
            return count_all_words(words, MAX_WORDS);
        }
        if (sentence[i] == '\'' && next == 0)
        {
            continue;
        }
        local_str[next++] = tolower(sentence[i]);
    }

    if (next != 0)
    {
        apply_word(local_str, words, MAX_WORDS);
    }
    free(local_str);

    return count_all_words(words, MAX_WORDS);
}

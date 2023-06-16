#include "palindrome_products.h"
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool is_palindrom(size_t a)
{
    size_t n = a, rev = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    if (a == rev)
    {
        return true;
    }
    return false;
}

void process_palindrom(product_t *pr, int palindrom, int prod_a, int prod_b)
{

    if (pr->largest == palindrom)
    {
        pr->factors_lg = realloc(pr->factors_lg, (pr->lg_len + 1)*sizeof(factor_t));
        pr->factors_lg[pr->lg_len].factor_a = prod_a;
        pr->factors_lg[pr->lg_len].factor_b = prod_b;
        pr->factors_lg[pr->lg_len-1].next = &pr->factors_lg[pr->lg_len];
        pr->lg_len++;
    }

    if (pr->smallest == palindrom)
    {
        pr->factors_sm = realloc(pr->factors_sm, (pr->sm_len + 1)*sizeof(factor_t));
        pr->factors_sm[pr->sm_len].factor_a = prod_a;
        pr->factors_sm[pr->sm_len].factor_b = prod_b;
        pr->factors_sm[pr->sm_len-1].next = &pr->factors_sm[pr->sm_len];
        pr->sm_len++;
    }
    
    if (pr->largest < palindrom)
    {
        pr->largest = palindrom;
        pr->factors_lg = malloc(sizeof(factor_t));
        pr->lg_len = 1;
        pr->factors_lg[0].next = NULL;
        pr->factors_lg[0].factor_a = prod_a;
        pr->factors_lg[0].factor_b = prod_b;
    }

    if (pr->smallest > palindrom)
    {
        pr->smallest = palindrom;
        pr->factors_sm = malloc(sizeof(factor_t));
        pr->sm_len = 1;
        pr->factors_sm[0].next = NULL;
        pr->factors_sm[0].factor_a = prod_a;
        pr->factors_sm[0].factor_b = prod_b;
    }
}

product_t *get_palindrome_product(int from, int to)
{

    product_t *pr = malloc(sizeof(product_t));
    pr->smallest = INT_MAX;
    pr->factors_lg = NULL;
    pr->factors_sm = NULL;
    pr->largest = 0;
    pr->sm_len = 0;
    pr->lg_len = 0;

    if (to < from)
    {
        snprintf(pr->error, MAXERR, "invalid input: min is %i and max is %i", from, to);
        return pr;

    }

    bool found = false;
    int n = from;
    while (n <= to)
    {
        for(int n_next = n; n_next <= to; n_next++)
        {
            size_t prod = n * n_next;
            if (is_palindrom(prod))
            {
                found = true;
                process_palindrom(pr, prod, n, n_next);    
            }
        }
        n++;
    }

    if (!found)
    {
        snprintf(pr->error, MAXERR, "no palindrome with factors in the range %i to %i", from, to);
    }


    return pr;
}


void free_product(product_t *p)
{ 
    if (p->factors_lg != NULL)
    {
        free(p->factors_lg);
    }
    
    if (p->factors_sm != NULL)
    {
        free(p->factors_sm);
    }
    
    free(p);
}

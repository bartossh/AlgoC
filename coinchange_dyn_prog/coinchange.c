#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX INT_MAX

int min(int a, int b) { return a < b ? a : b; }

/*
 * Function: solve_coin_change
 * --------------------
 * Calculates the fewest number of coins that need to make up that amount
 * coins: arr of coins values
 * length: coins arr length
 * amount: amount to make up from coins
 *
 * returns: number of coins that need to make up that amount or -1 if not
 * possible to make up amount
 */
int solve_coin_change(int *coins, int length, int amount)
{
    if (amount == 0 || length == 0)
    {
        return 0;
    }

    int *mem = malloc((amount + 1) * sizeof(int));

    for (int i = 1; i <= amount; i++)
    {
        mem[i] = MAX;
        for (int j = 0; j < length; j++)
        {
            if (coins[j] <= i && mem[i - coins[j]] != MAX)
            {
                mem[i] = min(mem[i], mem[i - coins[j]] + 1);
            }
        }
    }

    int result;

    if (mem[amount] == MAX)
    {
        result = -1;
    }
    else
    {
        result = mem[amount];
    }

    free(mem);

    return result;
}
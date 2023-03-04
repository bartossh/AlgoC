#include <stdbool.h>
#include <stdio.h>

unsigned int max_set_bit_position(unsigned num)
{
    unsigned r = 0;

    while (num >>= 1)
    {
        r++;
    }

    return r + 1;
}

/*
 * Function:  joshephus_solver
 * --------------------
 * Solves Joshephus problem for any number of soldiers in a circle.
 *  num: unsigned int, number of solders in a circle
 * Flavius Josephus, a Jewish-Roman historian from the first century,
 * tells the story like this: A company of 40 soldiers, along with Josephus himself,
 * were trapped in a cave by Roman soldiers during the Siege of Yodfat in 67 A.D.
 * The Jewish soldiers chose to die rather than surrender,
 * so they devised a system to kill off each other until only one person remained.
 * (That last person would be the only one required to die by their own hand.)

 * All 41 people stood in a circle.
 * The first soldier killed the man to his left, the next surviving soldier killed the man to his left, and so on.
 * Josephus was among the last two men standing, "whether we must say it happened so by chance,
 * or whether by the providence of God," and he convinced the other survivor to surrender rather than die.
 *  returns: unsigned int
 */
unsigned joshephus_solver(unsigned num)
{
    unsigned mask = 1 << (max_set_bit_position(num) - 1);
    unsigned res = mask ^ num;
    res = (res << 1) + 1;
    return res;
}

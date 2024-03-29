#include "queen_attack.h"
#include <stdlib.h>
#include <stdbool.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (queen_1.column >= 8 ||
        queen_2.column >= 8 ||
        queen_1.row >= 8 ||
        queen_2.row >= 8 ||
        (queen_1.column == queen_2.column &&
         queen_1.row == queen_2.row))
    {
        return INVALID_POSITION;
    }

    if (queen_1.column == queen_2.column ||
        queen_1.row == queen_2.row ||
        abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
    {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}

#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
        return INVALID_POSITION;
    if (!(isValid(queen_1) && isValid(queen_2)))
        return INVALID_POSITION;
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
        return CAN_ATTACK;
    if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
        return CAN_ATTACK;
    return CAN_NOT_ATTACK;
}

int isValid(position_t pos)
{
    return pos.row < 8 && pos.column < 8;
}

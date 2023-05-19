#include "robot_simulator.h"
#include <string.h>
#include <stdio.h>

const int WORLD_SIGHTS = 4;

void apply_increment(robot_status_t *robot)
{
    robot_position_t position = {0, 0};
    switch (robot->direction)
    {
    case DIRECTION_NORTH:
        position.y = 1;
        break;
    case DIRECTION_EAST:
        position.x = 1;
        break;
    case DIRECTION_SOUTH:
        position.y = -1;
        break;
    case DIRECTION_WEST:
        position.x = -1;
        break;
    case DIRECTION_MAX:
        break;
    }

    robot->position.x += position.x;
    robot->position.y += position.y;
}

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot = {direction, {x, y}};
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    for (size_t i = 0; i < strlen(commands); i++)
    {
        switch (commands[i])
        {
        case 'R':
            robot->direction = (robot->direction + 1) % WORLD_SIGHTS;
            continue;
        case 'A':
            apply_increment(robot);
            continue;
        case 'L':
            robot->direction = (robot->direction - 1) % WORLD_SIGHTS;
            continue;
        }
    }
}

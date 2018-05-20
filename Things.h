#pragma once

#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

enum Direction
{
    left,
    right,
    up,
    down
};

enum TileState
{
    empty,
    snake,
    fruit,
    wall
};

struct Pos
{
    int x;
    int y;
};

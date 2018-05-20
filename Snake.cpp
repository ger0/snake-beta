#include "Snake.h"

Snake::Snake(Map &map) :
    mMap(map), 
    pos(mMap.getMiddle()),
    dir(left),
    food(2),
    isAlive(1)
{
    mMap.setVal(pos, 1);
    mMap.genFruit();
}

void Snake::changeDir()
{
    switch (getch())
    {
        case 'w':
            if (dir != down)
                dir = up;
            break;

        case 'a':
            if (dir != right)
                dir = left;
            break;

        case 's':
            if (dir != up)
                dir = down;
            break;

        case 'd':
            if (dir != left)
                dir = right;
            break;

        default:
            break;
    }
}

unsigned Snake::getScore()
{
    return food - 2;
}

void Snake::move()
{
    switch (dir)
    {
        case left:
            --pos.x;
            break;

        case right:
            ++pos.x;
            break;

        case up:
            --pos.y;
            break;

        case down:
            ++pos.y;
            break;
    }
}

void Snake::play()
{
    move();
    mMap.update(checkTile());
    changeDir();
}

bool Snake::checkTile()
{
    if (mMap.getVal(pos.x, pos.y) == fruit)
    {
        mMap.setVal(pos, ++ food);
        mMap.genFruit();
        return 1;
    }
    else if (mMap.getVal(pos.x, pos.y) == empty)
    {
        mMap.setVal(pos, food);
        return 0;
    }
    else isAlive = 0;
    return 0;
}

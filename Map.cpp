#include "Map.h"

Map::Map(unsigned const& x, unsigned const& y) :
    mapW(x),
    mapH(y),
    mapVect(x * y)
{

    // initialise grid
    for (unsigned i = 0; i < x * y; i++)
    {
        mapVect[i] = 0;
    }

    // make some walls
    for (unsigned i = 0; i < x; i++)
    {
        mapVect[i] = 2;                     // upper wall

        mapVect[x * y - (1 + i)] = 2;       // lower wall 
    }

    for (unsigned i = 0; i < y; i++)
    {

        mapVect[i * x] = 2;                 // left wall
        mapVect[(i + 1) * x - 1] = 2;       // right wall
    }
}

Pos Map::getMiddle()
{
    return {int(mapW / 2 - 1), int(mapH / 2 - 1)};
}

TileState Map::getVal(int x, int y)
{
    if (mapVect[mapW * y + x] < 0)
        return snake;

    else if (mapVect[mapW * y + x] == 0)
        return empty;

    else if (mapVect[mapW * y + x] == 1)
        return fruit;
    
    else if (mapVect[mapW * y + x] == 2)
        return wall;
}

void Map::setVal(Pos& pos, unsigned value)
{
    mapVect[mapW * pos.y + pos.x] -= value;
}

void Map::update(bool type)
{
    if (!type)
    {
        for (unsigned i = 0; i < mapVect.size(); i++)
        {
            if (mapVect[i] < 0)
                mapVect[i]++;
        }
    }
}

void Map::genFruit()
{
    unsigned coord = mapW * (rand() % (mapH - 1) + 1)
                    + rand() % (mapW - 1) + 1;

    while (mapVect[coord])
    {
        coord = mapW * (rand() % (mapH - 1) + 1)
                    + rand() % (mapW - 1) + 1;
    }
    mapVect[coord] = 1;
}

void Map::draw()
{
    for (unsigned y = 0; y < mapH; y++)
    {
        for (unsigned x = 0; x < mapW; x++)
        {
            switch (getVal(x, y))
            {
                case empty:
                    mvprintw(y, x, " ");
                    break;

                case wall:
                    mvprintw(y, x, "@");
                    break;

                case snake:
                    mvprintw(y, x, "#");
                    break;
                
                case fruit:
                    mvprintw(y, x, "*");
                    break;
                default: break;
            }
        }
        refresh();
    }
}

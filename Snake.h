#pragma once

#include "Map.h"
#include "Things.h"

class Snake
{
    Map &mMap;
    Pos pos;
    Direction dir;
    unsigned food;
    bool checkTile();    /* checks a tile and returns
                            true if it contains a fruit */
    public:

    Snake(Map&);
    void play();

    bool isAlive;
    unsigned getScore(); 

    void changeDir();
    void move();
};

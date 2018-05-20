#pragma once

#include "Things.h"

class Map
{
    unsigned const mapW, mapH;
    std::vector<int> mapVect;               // map grid
    
    public:

    Map(unsigned const&, unsigned const&);

    Pos getMiddle();                        // returns middle coordinate
    TileState getVal(int, int);             // returns the state of the tile
    void genFruit();                        // generates a fruit on a random tile
    void setVal(Pos&, unsigned);            // subtracts an unsigned value from the tile 
    void update(bool);                      // updates map for every tick
    void draw();                            // prints map on screen 
};

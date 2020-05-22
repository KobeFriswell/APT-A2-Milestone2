#ifndef TILES_H
#define TILES_H
#include <iostream>
#include <string>

typedef char Colour;

class Tiles {
    public:

    Tiles();
    Tiles(Colour c);
    Colour getColour();
    void setColour(Colour c);
    bool SameColour(Tiles* tile);

private:
    Colour colour;
    #define YELLOW 'Y'  
    #define RED    'R'
    #define LIGHT_BLUE  'L'
    #define DARK_BLUE  'B'
    #define BLACK 'U'
    #define EMPTY  '-'
    #define INVALID '.'
    #define TOTAL_TILE 100
    #define CURRENTPLAYERTURN 'F'
    #define TAKEN 'o'



};

#endif
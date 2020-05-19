#ifndef Tiles_h
#define Tiles_h
#include <iostream>
#include <string>

class Tiles{
    public:
    typedef char Colour;

    Tiles();
    Tiles(Colour c);
    Colour getColour();
    void setColour(Colour c);
    bool SameColour(Tiles* tiles);

private:
    Colour colour;
    #define YELLOW 'Y'
    #define RED    'R'
    #define LIGHT_BLUE  'L'
    #define DARK_BLUE  'B'
    #define BLACK 'U'
    #define EMPTY  '.'
    #define TOTAL_TILE 100

};

#endif
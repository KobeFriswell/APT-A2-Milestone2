//tiles class
#include "Tiles.h"

Tiles::Tiles(){
    this-> colour = ' ';
}

Tiles::Tiles(Colour c){
    this-> colour = c;
}

void Tiles::setColour(Colour c){
    this->colour = c;
}

Colour Tiles::getColour() {
    return this->colour;
}
    

bool Tiles::SameColour(Tiles* tiles) {
    if(tiles->getColour() == this->colour)
    {return true;}
    return false;
}
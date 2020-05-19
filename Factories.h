#ifndef FACTORIES_H
#define FACTORIES_H

#include <iostream>
#include <string>

#define FACTORY_SIZE 4

class Factories{
    
    public:

    Factories();
    int takeTile(char tile);
    bool storeTile(char tile);
    void removeTiles(char tile);
    std::string toString();

    private:
    
    int numTiles;
    char tiles[FACTORY_SIZE];
};
#endif
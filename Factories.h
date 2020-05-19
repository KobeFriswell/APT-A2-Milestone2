#ifndef Factories_h
#define Factories_h
#include <iostream>
#include <string>
#include "Tiles.h"
#include "LinkedList.h"

class Factories{
    
    public:

    Factories(int noOfPlayers, int seed);
    ~Factories();
    int takeTile(Colour c, int factories);
    int NoOfFactories(int NoOfFactories);
    int getNoOfFactories();
    bool StoreColour(Colour c, int factories);
    bool isClear();
    bool whoFirst();
    void removeFirst();
    void setSeed(int seed);

    void addLeftoverTiles(Tiles* tiles);
    void displayFactories();
    void TileBag(LinkedList* Tilebag);


    void BoxLid(LinkedList* BoxLid);
    void removeTiles();

    private:

};
#endif
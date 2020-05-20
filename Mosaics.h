//Mosacis class
#ifndef Mosaic_h
#define Mosaic_h
#include <iostream>
#include <string>
#include "Player.h"
#include "Tiles.h"
#include "LinkedList.h"

class Mosaics {
    public:

    Mosaics(Player* player);
    ~Mosaics();
    bool PositionTiles(int row, int number, Colour c);
    void DisplayMosaics();
    void CheckTurn();
    bool winCheck();
    bool WhosFirst();
    bool whosTurn();
    LinkedList* returnTiles();
   
    Player* getPlayer();
};

#endif
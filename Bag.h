#ifndef BAG_H
#define BAG_H

#include "LinkedList.h"

#define NUM_COLOUR_TILES 5

class Bag{
    public:
        Bag();
        //~Bag();

        void addTile(char tile);
        char grabTile();
        void shuffleBag();

        void toString();
        std::string saveString();

    private:
    
        const char gameTiles[NUM_COLOUR_TILES] = {'R','Y','B','L','U'};
        LinkedList contents;

        
};
#endif
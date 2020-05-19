#ifndef BAG_H
#define BAG_H

#include "LinkedList.h"

#define NUM_COLOUR_TILES 5

class Bag{
    public:
        Bag();
        ~Bag();

        void addTile(char tile);
        void grabTile(int i);
        void shuffleBag();

    private:
        const char gameTiles[5] = {'R','Y','B','L','U'};
        LinkedList contents;
};
#endif
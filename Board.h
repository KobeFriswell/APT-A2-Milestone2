#ifndef BOARD_H
#define BOARD_H

#include "Tiles.h"

#define FLOOR_LINE_SIZE 7

class Board {
public:
    Board();

    Board getBoard();

    void setWallTile(int x, int y, char tile);
    char* getWall();

    void setPatternTile(int x,int y, char tile);
    char* getPatternLine();

    char* getFloorLine();

    void dropTile(char tile);
    void addFloorLine(char tile);

private: 

    char wall[5][5];
    char patternLine[5][5];

    //2D arrays cant store 2 different data types as far as I can see
    const int weightings[7] = {-1,-1,-2,-2,-2,-3,-3};
    char floorLine[FLOOR_LINE_SIZE];
    
    //int scoreTrack;
};

#endif

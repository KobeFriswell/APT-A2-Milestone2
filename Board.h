#ifndef BOARD_H
#define BOARD_H

#define GRID_SIZE 5
#define PENALTY_LENGTH 7

#include "Tiles.h"

#define FLOOR_LINE_SIZE 7

class Board {
public:
    Board();
    Board(char rightGrid[GRID_SIZE][GRID_SIZE], char leftGrid[GRID_SIZE][GRID_SIZE], char penaltyPanel[PENALTY_LENGTH]);

    Board getBoard();
    
    void setWallTile(int x, int y, char tile);
    std::string getWall();

    bool setPatternTile(int line, char tile, int numTiles);
    std::string getPatternLines();
    int getFreePatterLine(int line);
    char patternLineContains(int line);

    std::string getFloorLine();

    char dropTile(char tile);
    void addFloorLine(char tile);

private: 

    char wall[5][5] = {
        {'-','-','-','-','-'},
        {'-','-','-','-','-'},
        {'-','-','-','-','-'},
        {'-','-','-','-','-'},
        {'-','-','-','-','-'}
    };
    //'.' are unwrittable positions, '-' are empty spaces
    char patternLine[5][5] = {
        {'.','.','.','.','-'},
        {'.','.','.','-','-'},
        {'.','.','-','-','-'},
        {'.','-','-','-','-'},
        {'-','-','-','-','-'}
    };

    //2D arrays cant store 2 different data types as far as I can see
    const int weightings[7] = {-1,-1,-2,-2,-2,-3,-3};
    char floorLine[FLOOR_LINE_SIZE];
    
    //int scoreTrack;
};

#endif

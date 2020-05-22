#ifndef BOARD_H
#define BOARD_H

#include "Tiles.h"

#include <vector>

#define FLOOR_LINE_SIZE 7

class Board {
public:
    Board();

    Board getBoard();

    void setWallTile(int x, int y, char tile);
    std::string getWall();
    void addToWall(int line, char tile);

    bool setPatternTile(int line, char tile, int numTiles);
    std::string getPatternLines();
    int getFreePatterLine(int line);
    char patternLineContains(int line);
    void checkPatternLines();
    void clearPatternLine(int line);

    std::string getFloorLine();

    char dropTile(char tile);
    void addFloorLine(char tile);

    std::vector<int> getNumToLid();
    std::vector<char> getTileToLid();
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

    const char wallTemplate[5][5] = {
        {'B','Y','R','U','L'},
        {'L','B','Y','R','U'},
        {'U','L','B','Y','R'},
        {'R','U','L','B','Y'},
        {'Y','R','U','L','L'}
    };

    //2D arrays cant store 2 different data types as far as I can see
    const int weightings[7] = {-1,-1,-2,-2,-2,-3,-3};
    char floorLine[FLOOR_LINE_SIZE] = {'-'};
    
    //int scoreTrack;
    std::vector<int> numToLid;
    std::vector<char> tileToLid;
};

#endif

#include "Board.h"

//Board class

Board::Board(){
    //TODO
}

void Board::setWallTile(int x, int y, char tile){
    wall[x][y] = tile;
 }
    
std::string Board::getWall(){
    std::string toString;
    for (int i = 0; i<5; i++){
        for (int x = 0; x<5; x++){
            toString = toString + wall[i][x];
        }
    }
    return toString;
}

bool Board::setPatternTile(int line, char tile, int numTiles){
    //Checks if enough free spots
    if (getFreePatterLine(line) < numTiles || (patternLineContains(line) != '0' || patternLineContains(line) != tile)){
        return false;
    } else{
        for (int i = 5; i>(5-numTiles); i--){
            if (patternLine[line][i] == '-'){
                patternLine[line][i] = tile;
            }
        }
        return true;
    }
}

//Get free spaces in pattern line
int Board::getFreePatterLine(int line){
    int count = 0;
    for (int i = 0; i<5; i++){
        if (patternLine[line][i] == '-'){
            count++;
        }
    }
    return count;
}

//Returns the character stored in the line already
char Board::patternLineContains(int line){
    char tile = '0';
    for (int i = 0; i<5; i++){
        if (patternLine[line][i] != '-' || patternLine[line][i] != '.'){
            tile = patternLine[line][i];
        }
    }
    return tile;
}
    
std::string Board::getPatternLine(){
    std::string toString;
    for (int i = 0; i<5; i++){
        for (int x = 0; x<5; x++){
            toString = toString + patternLine[i][x];
        }
    }
    return toString;
}

//Returns the tile being dropped
char Board::dropTile(char tile){
    //TODO
}

std::string Board::getFloorLine(){
    return floorLine;
}

void Board::addFloorLine(char tile){
    //Check array for spare spot to add tile
    //Maybe have an integer to keep track of index
    for (int i = 0; i<FLOOR_LINE_SIZE; i++){
        if (floorLine[i]!='-'){
            floorLine[i] = tile;
        }
    }
}

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
    int lineChoice = line - 1;
    if (numTiles == 0){
        std::cout << "\nError: Tile Doesnt Exist In Factory\n" << std::endl;
        return false;
    }else if (getFreePatterLine(lineChoice) < numTiles){
        std::cout << "\nError: More Tiles Than Line\n" << std::endl;
        return false;
    } else if(patternLineContains(lineChoice) != '0' && patternLineContains(lineChoice) != tile){
        std::cout << "\nError: Pattern Line already contains different tile\n" << std::endl;
        return false;
    } else{
        int addedTiles = 0;
        int index = 5;
        while (addedTiles != numTiles){
            index--; 
            if (patternLine[lineChoice][index] == '-'){
                patternLine[lineChoice][index] = tile;
                addedTiles ++;
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
        char patternTile = patternLine[line][i];
        if (patternTile != '-' && patternTile != '.'){
            tile = patternTile;
        }
    }
    return tile;
}
    
std::string Board::getPatternLines(){
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
    return '0';
}

std::string Board::getFloorLine(){
    std::string toString;
    for (int i = 0; i<FLOOR_LINE_SIZE; i++){
        toString = toString + floorLine[i];
    }
    return toString;
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

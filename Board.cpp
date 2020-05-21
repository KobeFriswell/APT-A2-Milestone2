#include "Board.h"

//Board class

Board::Board(){
    //TODO
}

void Board::setWallTile(int x, int y, char tile){
    wall[x][y] = tile;
 }
    
char* Board::getWall(){
    return *wall;
}

void Board::setPatternTile(int x,int y, char tile){
    patternLine[x][y] = tile;
}
    
char* Board::getPatternLine(){
    return *patternLine;
}

//
void Board::dropTile(char tile){
    //TODO
}

char* Board::getFloorLine(){
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
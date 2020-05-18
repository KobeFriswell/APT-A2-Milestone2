#include "Board.h"

//Board class

Board::Board(){
    //TODO
}

void Board::setWallTile(int x, int y, char tile){
     //TODO
 }
    
int Board::getWall(){
    //TODO
    return 0;
}

void Board::setPatternTile(int x,int y, char tile){
    //TODO
}
    
int Board::getPatternLine(){
    //TODO
    return 0;
}

void Board::dropTile(char tile){
    //TODO
}

void Board::addFloorLine(Tiles* tile){
    //Check array for spare spot to add tile
    //Maybe have an integer to keep track of index
    for (int i = 0; i<FLOOR_LINE_SIZE; i++){
        if (floorLine[i]!=nullptr){
            floorLine[i] = tile;
        }
    }
}
#include "Board.h"

//Board class

Board::Board(){
    //TODO
}

//overload
Board::Board(char rightGrid[GRID_SIZE][GRID_SIZE], char leftGrid[GRID_SIZE][GRID_SIZE], char penaltyPanel[PENALTY_LENGTH]){
    
    for(int i=0; i < GRID_SIZE; i++){
        for(int j=0; j < GRID_SIZE; j++){
            this -> wall[i][j] = leftGrid[i][j];
        }

        for(int x=0; i < GRID_SIZE; x++){
            this -> patternLine[i][x] = rightGrid[i][x];
        }
    }
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
    } else if(patternLineContains(lineChoice) != '0' && patternLineContains(lineChoice) != tile){
        std::cout << "\nError: Pattern Line already contains different tile\n" << std::endl;
        return false;
    } else{
        //Drops tiles to floorline
        if (getFreePatterLine(lineChoice) < numTiles){
            int extraTiles = numTiles-getFreePatterLine(lineChoice);
            numTiles = numTiles-extraTiles;
            int index = 0;
            while (extraTiles != 0){
                if (floorLine[index] == '-'){
                    floorLine[index] = tile;
                    extraTiles--;
                }
                index++;
            }
        }
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

//Checks PatternLines for full then move to wall
void Board::checkPatternLines(){
    char wallTile;
    for (int line = 0; line < 5; line++){
        bool full = true;
        for (int tile = 0; tile<5; tile++){
            if (patternLine[line][tile] == '-'){
                full = false;
            }
        }
        if (full){
            wallTile = patternLineContains(line);
            clearPatternLine(line);
            addToWall(line, wallTile);
        }
    }
}

//Writes '-' for whole line
void Board::clearPatternLine(int line){
    for (int index = 5; index>(5-line); index--){
        patternLine[line][index] = '-';
    }
}

int Board::roundTally(){
    if(noAdjacentTile()){
        //Score +1 if the tile placed had no adjacent tiles
        return
    }

    else{
        
    }


}

//calculates how many point the player gets for their board
int Board::endGameScoreTally(){

    //for each full horizontal line score + 5
    if(verticalLineFull(i)){
        //add 

    }

    //for each full vertical line score + 7

    


    //for each tile colour, if there exist 5 of them, score + 10

}

int Board::endRoundScoreTally(){

    //if tile placed has no adjacent tile then score +1 and return
    if(noAdjacentTile()){
        //Score +1
        return
    } else {
        //add +1 for the tile placed


        //for each tile to the left and right until == "-" +1


        //for each tile above and below until =="-" +1


        //for each tile that droped to the floorline
        

        //last call because this function ends the game
        
        if(horizontalLineFull(i)){
            //Call the game and tally end game scores

        }

    }
    
}


//Adds character to wall in its correct position
void Board::addToWall(int line, char tile){
    for (int column = 0; column<5; column++){
        if (wallTemplate[line][column] == tile){
            wall[line][column] = tile;
        }
    }
}

bool Board::verticalLineFull(int x){


}
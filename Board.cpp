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

//Sets tile on wall given x and y
void Board::setWallTile(int x, int y, char tile){
    wall[x][y] = tile;
 }

//Returns a string format of the wall
std::string Board::getWall(){
    std::string toString;
    for (int i = 0; i<5; i++){
        for (int x = 0; x<5; x++){
            toString = toString + wall[i][x];
        }
    }
    return toString;
}

//Adds tile(s) to specific pattern line
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
        //If too many tiles, drops tiles to floorline
        if (getFreePatterLine(lineChoice) < numTiles){
            //Number of extra tiles to go to floor line
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

//Returns the character stored in the line already, if nothing return '0' char
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

//Returns a string format of all pattern lines
std::string Board::getPatternLines(){
    std::string toString;
    for (int i = 0; i<5; i++){
        for (int x = 0; x<5; x++){
            toString = toString + patternLine[i][x];
        }
    }
    return toString;
}

//Returns a string format of the floor line
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

// void Board::clearFloorLine(){
//     //reset the floorline back to empty
//     for (int i = 0; i<FLOOR_LINE_SIZE; i++){
//         //put tile into boxLid
//         floorLine[i] = "-";
//     }
// }

//Checks PatternLines for full then move to wall
void Board::checkPatternLines(){
    numToLid.clear();
    tileToLid.clear();
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
            numToLid.push_back(line+1);
            tileToLid.push_back(wallTile);
        }
    }
}

//Writes '-' for whole line
void Board::clearPatternLine(int line){
    for (int index = 0; index < GRID_SIZE; index++){
        if (patternLine[line][index] != '.'){
            patternLine[line][index] = '-';
        }
    }
}


//calculates how many point the player gets for their board
int Board::endGameScoreTally(){

    //for each full horizontal line score + 5
    for(int i =0; i < GRID_SIZE; i++)
        if(verticalLineFull(i)){
            //add + 5

    }

    //for each full vertical line score + 7

    


    //for each tile colour, if there exist 5 of them, score + 10

}

int Board::roundTally(){
    int roundScore = 0;

    //if tile placed has no adjacent tile then score +1 and return
    // if(noAdjacentTile(x, y)){
    //     //Score +1
    //     return
    // } else {
        //add +1 for the tile placed


        //for each tile to the left and right until == "-" +1


        //for each tile above and below until =="-" +1


        //for each tile that droped to the floorline
        

        //last call because this function ends the game
        
        // if(horizontalLineFull(i)){
        //     return roundScore;
        //     //Call the game and tally end game scores

        // }
    return roundScore;

    }
    



//Adds character to wall in its correct position
void Board::addToWall(int line, char tile){
    for (int column = 0; column<5; column++){
        if (wallTemplate[line][column] == tile){
            wall[line][column] = tile;
        }
    }
}

bool Board::verticalLineFull(int y){
    return true;
}

bool Board::horizontalLineFull(int x){
    return false;
}

bool Board::noAdjacentTile(int x, int y){
    return true;
}


//Get number of tiles needed to add to lid
std::vector<int> Board::getNumToLid(){
    return numToLid;
}

//Get tiles needed to add to lid
std::vector<char> Board::getTileToLid(){
    return tileToLid;
}

//Returns printable format of board
std::string Board::toStringBoard(){
    std::string toString;
    for (int row = 0; row<5; row++){
        toString = toString + std::to_string(row+1) + ": " + stringPatternLine(row) + " || " + getWallLine(row) + "\n";
    }
    toString = toString + "Broken: " + getFloorLine();
    return toString;
}

//Returns given line in string format
std::string Board::stringPatternLine(int line){
    std::string toString;
    for (int i = 0; i<5; i++){
        if (patternLine[line][i] == '.'){
            toString = toString + "  ";
        }
        else{
           toString = toString + patternLine[line][i] + " "; 
        }
    }
    return toString;
}

//Returns given wall line in string format
std::string Board::getWallLine(int line){
    std::string toString;
    for (int i = 0; i<5; i++){
        toString = toString + wall[line][i] + " "; 
    }
    return toString;
}
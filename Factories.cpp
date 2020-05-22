#include "Factories.h"

Factories::Factories(){
    numTiles = 0;
    clearFactory();
}

//Returns the number of tiles on the factory
//And removes them from the array
int Factories::takeTile(char tile){
    int tileCount = 0;
    for (int i = 0; i<FACTORY_SIZE; i++){
        if (tiles[i] == tile){
            tileCount += 1;
            tiles[i] = '-';
        }   
    }

    return tileCount;
}

//Checks for blank spot then adds the tile
bool Factories::storeTile(char tile){
    for (int i = 0; i<FACTORY_SIZE; i++){
        if (tiles[i] == '-'){
            tiles[i] = tile;
            numTiles++;
            return true; 
        }
    }
    return false;
}

//Removes tile matching that char
void Factories::removeTiles(char tile){
    for (int i = 0; i<FACTORY_SIZE; i++){
        if (tiles[i] == tile){
            tiles[i] = '-';
            numTiles--;
        }
    }
}

//Returns array in string format
std::string Factories::toString(){
    std::string toString;
    for (int i = 0; i<FACTORY_SIZE; i++){
        toString = toString + tiles[i] + " ";
    }

    return toString;
}

std::string Factories::saveString(){
    std::string s;
     for (int i = 0; i<FACTORY_SIZE; i++){
        s = s + tiles[i];
    }
    return s;
}   

//Clear Array
void Factories::clearFactory(){
    for (int i = 0; i<FACTORY_SIZE; i++){
        tiles[i] = '-';
        numTiles = 0;
    }
}
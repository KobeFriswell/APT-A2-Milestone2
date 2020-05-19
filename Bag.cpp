#include "Bag.h"

#include <random>
#include <ctime>

Bag::Bag(){
    //Add 100 tiles to bag (20 of each)
    for (int i = 0; i<NUM_COLOUR_TILES; i++){
        for (int x = 0; x<20 ; x++){
            contents.addBack(gameTiles[i]);
        }
    }
    
    //Shuffles Bag
    shuffleBag();
}

//Adds tile to back of linkedlist
void Bag::addTile(char tile){
    contents.addBack(tile);
}

void Bag::grabTile(int i){
    contents.grabTile(i);
}

//Shuffles the contents of the bag
void Bag::shuffleBag(){
    //Grab contents of bag and store in array
    int bagSize = contents.size();
    char* bagContents = new char[bagSize];
    for (int i = 0; i < bagSize; i++){
        bagContents[i] = contents.getData(i);
    }

    //Using random number move to a shuffled array
    srand((unsigned) time(0));
    int randomIndex;
    char* shuffled = new char[bagSize];
    for (int index = 0; index < bagSize; index++){   
        bool found = false;
        while(!found){
            randomIndex = (rand() % ((bagSize) + 0));
            if (bagContents[randomIndex] != '-'){
                shuffled[index] = bagContents[randomIndex];
                bagContents[randomIndex] = '-';
                found = true;
            } 
        }     
    }

    delete(bagContents);
    delete(shuffled);
}

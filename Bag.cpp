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

char Bag::grabTile(){
    return contents.grabTile();
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

    //Make contents the shuffled array
    contents.clear();
    for (int x = 0; x<bagSize-1; x++){
        contents.addBack(shuffled[x]);
    }

    delete(bagContents);
    delete(shuffled);
}

void Bag::toString(){
    for (int i = 0; i<contents.size(); i++){
        std::cout << contents.getData(i);
    }
    std::cout << std::endl;
}

std::string Bag::saveString(){
    std::string s;
    for (int i = 0; i<contents.size(); i++){
        s = s + contents.getData(i);
    }
}



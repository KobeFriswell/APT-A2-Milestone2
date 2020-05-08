#include "Game.h"

Game::Game(){
    //TODO
}

//Add player to back of vector
//Maybe create new board here also?
void Game::addPlayer(Player* player){
    players.push_back(player);
}

//Adds pointer to tile to back of lid vector
void Game::addToLid(Tiles* tile){
    lid.push_back(tile);
}

//Adds pointer to tile to back of center vector 
void Game::addToCenter(Tiles* tile){
    center.push_back(tile);
}

//Adds pointer to tile to the back of tilebag linked list
void Game::addToTileBag(Tiles* tile){
    tileBag.addBack(tile);
}


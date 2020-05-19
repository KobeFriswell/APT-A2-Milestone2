#include "Game.h"

Game::Game(std::string player1, std::string player2){
    //Create Player and Board Objects
    Player* p1 = new Player(player1);
    Board* player1Board = new Board();

    Player* p2 = new Player(player2);
    Board* player2Board = new Board();

    //Add players and boards to vectors
    players.push_back(p1);
    boards.push_back(player1Board);

    players.push_back(p2);
    boards.push_back(player2Board);

    //Create 5 Factories
    for (int i = 0; i<NUM_FACTORIES; i++){
        Factories* factory = new Factories();
        factories.push_back(factory);
    }

    // Bag
    tileBag = new Bag();
    
}

//Add player to back of vector
//Maybe create new board here also?
void Game::addToPlayers(Player* player){
    players.push_back(player);
}

//Adds pointer to tile to back of lid vector
void Game::addToLid(char tile){
    lid.push_back(tile);
}

//Adds pointer to tile to back of center vector 
void Game::addToCenter(char tile){
    center.push_back(tile);
}

//Adds pointer to tile to the back of tilebag linked list
void Game::addToTileBag(char tile){
    //tileBag->addBack(tile);
}

//Returns number of players
int Game::getNumPlayers(){
    return numPlayers;
}

Player* Game::getPlayer(int index){
    return players.at(index);
}

Factories* Game::getFactory(int index){
    return factories.at(index);
}

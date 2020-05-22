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
    tileBag.shuffleBag();

    //Add tiles to factories
    for(int x = 0; x < NUM_FACTORIES; x++){
        for (int y = 0; y<4; y++){
            char tile = tileBag.grabTile();
            factories.at(x)->storeTile(tile);
        }
    }
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
    return players.size();
}

Player* Game::getPlayer(int index){
    return players.at(index);
}

Factories* Game::getFactory(int index){
    return factories.at(index);
}

std::string Game::lidToString(){
    int lidSize = lid.size();
    std::string toString;
    for (int i = 0; i<lidSize; i++){
        toString = toString + lid.at(i) + "  ";
    }
    return toString;
}

std::string Game::centerToString(){
    int centerSize = center.size();
    std::string toString;
    for (int i = 0; i<centerSize; i++){
        toString = toString + center.at(i) + "  ";
    }
    return toString;
}

//Takes player turn from menu input
bool Game::playerTurn(int factoryChoice, char tile, int patternLine){
    Factories* factory = factories.at(factoryChoice-1);
    int numTiles = factory->takeTile(tile);

    //Add number of Tiles to the chosen patternLine of a players board
    return boards.at(currentPlayer-1)->setPatternTile(patternLine, tile, numTiles);
}

//Uses ReadWrite to write save file
void Game::saveGame(std::string fileName){
    ReadWrite save;

    Player player1 = *players.at(0);
    std::string p1RightGrid = boards.at(0)->getWall(); 
    std::string p1LeftGrid = boards.at(0)->getPatternLines();
    std::string p1PenaltyPanel = boards.at(0)->getFloorLine();

    Player player2 = *players.at(1);
    std::string p2RightGrid = boards.at(1)->getWall(); 
    std::string p2LeftGrid = boards.at(1)->getPatternLines();
    std::string p2PenaltyPanel = boards.at(1)->getFloorLine();

    // save.saveToFile(fileName, gameStatus, tileBag, lid, center, factories, currentPlayer, numberPlayers, player1,
    //             p1RightGrid, p1LeftGrid, p1PenaltyPanel, player2, p2LeftGrid, p2PenaltyPanel);
}

void Game::setGameStatus(bool status){
    gameStatus = status;
}

void Game::setCurrentPlayer(int current){
    currentPlayer = current;
}

void Game::setNumberPlayers(){
    numberPlayers = getNumPlayers();
}
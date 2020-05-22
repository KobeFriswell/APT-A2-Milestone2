#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"
#include "Player.h"
#include "Board.h"
#include "Factories.h"
#include "Bag.h"
#include "readWrite.h"

#include <string>
#include <vector>

#define NUM_FACTORIES 5

class Game{
public:
    Game(std::string player1, std::string player2);

    void addToPlayers(Player* player);

    void addToLid(char tile);
    std::string lidToString();

    void addToCenter(char tile);
    std::string centerToString();

    bool playerTurn(int factoryChoice, char tile, int patternLine);

    void addToTileBag(char tile);

    int getNumPlayers();
    Player* getPlayer(int index);

    Factories* getFactory(int index);

    void saveGame(std::string fileName);

    void setGameStatus(bool status);
    void setCurrentPlayer(int current);
    void setNumberPlayers();

private:
    std::vector<char> lid;
    std::vector<char> center;
    std::vector<Factories*> factories;
    Bag tileBag;
    
    //Cant do 2D array with 2 different types
    std::vector<Player*> players;
    std::vector<Board*> boards;

    int numPlayers;

    bool gameStatus;
    int currentPlayer;
    int numberPlayers;
};

#endif
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

#define NUM_FACTORIES 6

class Game{
public:
    Game(std::string player1, std::string player2);

    Game(bool gameStatus, int currentPlayer,
            std::string player1, int player1Id, int player1Score,
            char p1RightGrid[GRID_SIZE][GRID_SIZE], char p1LeftGrid[GRID_SIZE][GRID_SIZE], char p1PenaltyPanel[PENALTY_LENGTH],
            std::string player2, int player2Id, int player2Score,
            char p2RightGrid[GRID_SIZE][GRID_SIZE], char p2LeftGrid[GRID_SIZE][GRID_SIZE], char p2PenaltyPanel[PENALTY_LENGTH]);
    
    void addToPlayers(Player* player);

    void addToLid(char tile);
    std::string lidToString();

    void addToCenter(char tile);
    std::string centerToString();
    int takeCenterTile(char tile);

    bool playerTurn(int factoryChoice, char tile, int patternLine);
    //void finishRound();

    void addToTileBag(char tile);

    int getNumPlayers();
    Player* getPlayer(int index);

    Factories* getFactory(int index);

    void saveGame(std::string fileName);

    void setGameStatus(bool status);
    void setCurrentPlayer(int current);
    void setNumberPlayers();

    void finishRound();
    void checkScore();

    std::string getBoardString(int playerIndex);

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
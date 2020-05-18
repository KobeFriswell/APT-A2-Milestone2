#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"
#include "Player.h"
#include "Board.h"
#include "Factories.h"

#include <string>
#include <vector>

class Game{
public:
    Game(std::string player1, std::string player2);

    void addToPlayers(Player* player);
    void addToLid(char tile);
    void addToCenter(char tile);
    void addToTileBag(char tile);

private:
    std::vector<char> lid;
    std::vector<char> center;
    std::vector<Factories*> factories;
    LinkedList tileBag;
    
    //Cant do 2D array with 2 different types
    std::vector<Player*> players;
    std::vector<Board*> boards;

    const char tiles[5] = {'R','Y','B','L','U'};
};

#endif
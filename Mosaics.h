//Mosacis class
#ifndef Mosaic_h
#define Mosaic_h
#include <iostream>
#include <string>
#include "Player.h"
#include "LinkedList.h"
#include "Game.h"
#include "Board.h"

#define BOARD_SIZE 5

class Mosaics {
    public:
    
    Mosaics(Player* player);
    ~Mosaics();
    bool PositionTiles(int row, int number, char tiles);
    void setPlayer(Player* player);
    void DisplayMosaics();
    void CheckTurn();
    void setTurn(bool burn);
    void setPointBoard(char** pointBoard);
    void setTurnBoard(char** turnBoard);
    void setBroken(char* tile, int area);
    void setFirst(bool first);
    bool winCheck();
    bool WhosFirst();
    bool whosTurn();
    LinkedList* returnTiles();
    void setSumTotal(int** sumtotal);
   
    Player* getPlayer();
    char** getPointBoard();
    char** getTurnBoard();
    char* getBroken(int content);
    char** getPointCalculator();


    private:
    
    void sumtotal();

    bool currentTurn = false;
    bool holdfirst = false;
    Player* player;
    int brokenScore = 0;
    char** turnBoard;
    char** pointBoard;
    char** pointCalculator;
    bool* colourCounting;
    char* broken[FLOOR_LINE_SIZE];
};

#endif
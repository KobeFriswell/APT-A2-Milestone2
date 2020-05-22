//Mosacis class
#ifndef Mosaic_h
#define Mosaic_h
#include <iostream>
#include <string>
#include "Player.h"
#include "LinkedList.h"
#include "Game.h"

#define BROKEN_AREA 7
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

    void setPlayer(Player* player);
    void setPointBoard(char** pointBoard);
    void setTurnBoard(char** turnBoard);
    void setRemainder(LinkedList* remainder);
    void setBroken(char* tile, int location);
    void setPointCalculator(char** pointCalculator);
    void setTurn(bool turn);
    void setFirst(bool first);
   
    Player* getPlayer();
    char** getPointBoard();
    char** getTurnBoard();
    LinkedList* getRemainder();
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
    LinkedList* remainder;
    char** pointCalculator;
    bool* colourCounting;
    char* broken[BROKEN_AREA];
};

#endif
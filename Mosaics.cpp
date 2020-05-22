//Mosacis class

#include "Mosaics.h"
    

Mosaics::Mosaics(Player* player){
    this->player = player;
    this->pointBoard = new char*[BOARD_SIZE];
    this->turnBoard = new char*[BOARD_SIZE];

    for(int x =0; x < 5; x++)
    {
        this->turnBoard[x] = new char[x+1];
        this->pointBoard[x] = new char[BOARD_SIZE];
        this->pointCalculator[x] = new char[BOARD_SIZE];
    }

    
}
Mosaics::~Mosaics(){
player->~Player();
    for(int x =0; x < BOARD_SIZE; x++)
    {
        delete this->pointBoard[x];
        delete this->turnBoard[x];
    }
    for(int x =0; x < FLOOR_LINE_SIZE;x++)
    {
        delete broken[x];
    }
}


bool Mosaics::PositionTiles(int row, int number, char tiles){
        row -= 1;
    
    if(tiles == CURRENTPLAYERTURN)
    {
        this->holdfirst = true;
        this->broken[this->brokenScore] = new char(tiles);
        this->brokenScore++;
        return true;
    }

}
void Mosaics::setPlayer(Player* player){
        this->player = player;

}

Player* Mosaics::getPlayer()
{
    return this->player;
}

void Mosaics::DisplayMosaics(){}
void Mosaics::CheckTurn(){}
void Mosaics::setTurn(bool turn){
         this->currentTurn = turn;

}


void Mosaics::setBroken(char* tile, int area){}
void Mosaics::setFirst(bool first){
        this->holdfirst = first;

}
bool Mosaics::winCheck(){
        
}
bool Mosaics::WhosFirst(){
        return this->currentTurn;
}
bool Mosaics::whosTurn(){
        return this->currentTurn;

}
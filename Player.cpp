#include "Player.h"

//Player class
//Player info starts with blanked / 0
Player::Player(std::string username){
    this ->username = username;
    this -> id = id;
    this ->score = 0;
}

//Player username and point is blanked
Player::~Player(){
    this->username = "";
    this -> id = 0;
    this->point = 0;
}

//returns player username
std::string Player::getUsername(){
    return this -> username;
}
    
//returns players point
int Player::getPlayerScore(){
    return this->point;
} 
//returns player ID
int Player::getPlayerId(){
    return this -> id;
}
    //set playerID
void Player::setPlayerId(int setId){
    this -> id = setId;
}    

//set point as score 
void Player::setPlayerScore(int point){
    if(point >=0) this-> point = score;
    else this-> point = 0;
}


//Display Username and Score 
void Player::DisplayStatus() {
    std::cout << "Name: " << this-> username << std::endl;
    std::cout << "Point: " << this-> point << std::endl;

}   

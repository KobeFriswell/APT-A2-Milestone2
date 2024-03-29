#ifndef Player_h
#define Player_h
#include <string>
#include <iostream>

using std::string;

class Player {
public:

    Player(std::string username);
    std::string getUsername();
    ~Player();

    Player* getPlayer();
    
    int getPlayerScore();  
    int getPlayerId();
    void setPlayerId(int setId);
    void setPlayerScore(int point);
    
    void DisplayStatus();

private: 

    std::string username;
    int score;
    int point;
    int id;
    };
    
#endif 

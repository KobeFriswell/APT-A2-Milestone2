#include <string>

using std::string;

class Player {
public:

    Player();

    Player getPlayer();
    
    int getPlayerScore();  
    void setPlayerScore();

    

private: 

    string username;
    int playerid;
    int score;

    };
    

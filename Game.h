#include "LinkedList.h"
#include "Tiles.h"
#include "Player.h"
#include "Board.h"

#include <vector>

class Game{
public:
    void addPlayer(Player* player);
    void addToLid(char tile);
    void addToCenter(char tile);
    void addToTileBag(char tile);

private:
    std::vector<char> lid;
    std::vector<char> center;
    std::vector<char> factory;
    LinkedList tileBag;
    
    //Cant do 2D array with 2 different types
    std::vector<Player*> players;
    std::vector<Board*> boards;
};
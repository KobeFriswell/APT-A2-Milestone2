#include "LinkedList.h"
#include "Tiles.h"
#include "Player.h"
#include "Board.h"

#include <vector>

class Game{
public:
    void addPlayer(Player* player);
    void addToLid(Tiles* tile);
    void addToCenter(Tiles* tile);
    void addToTileBag(Tiles* tile);

private:
    std::vector<Tiles*> lid;
    std::vector<Tiles*> center;
    LinkedList tileBag;
    
    //Cant do 2D array with 2 different types
    std::vector<Player*> players;
    std::vector<Board*> boards;
};
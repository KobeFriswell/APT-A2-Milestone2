#include "Game.h"

Game::Game(std::vector<std::string> playersInput, int centers){
    numPlayers = playersInput.size();
    numCenters = centers;
    numFactories = (numPlayers*2)+1;

    //Create Player and Board Objects
    for (int i = 0; i < numPlayers; i++){
        Player* player = new Player(playersInput.at(i));
        Board* playerBoard = new Board();
        players.push_back(player);
        boards.push_back(playerBoard);
    }

    //Create Factories
    for (int i = 0; i<numFactories; i++){
        Factories* factory = new Factories();
        factories.push_back(factory);
    }

    // Shuffles Tile Bag
    tileBag.shuffleBag();

    //Add tiles to factories
    for(int x = 0; x < numFactories; x++){
        for (int y = 0; y<4; y++){
            char tile = tileBag.grabTile();
            factories.at(x)->storeTile(tile);
        }
    }
}

//overload
// Game::Game(bool gameStatus, Bag bag, vector<char> boxLid, Factories*[NUM_FACTORIES], int currentPlayer,
//             std::string player1, int player1Id, int player1Score,
//             char p1RightGrid[GRID_SIZE][GRID_SIZE], char p1LeftGrid[GRID_SIZE][GRID_SIZE], char p1PenaltyPanel[PENALTY_LENGTH],
//             std::string player2, int player2Id, int player2Score,
//             char p2RightGrid[GRID_SIZE][GRID_SIZE], char p2LeftGrid[GRID_SIZE][GRID_SIZE], char p2PenaltyPanel[PENALTY_LENGTH])
Game::Game(bool gameStatus, int currentPlayer,
            std::string player1, int player1Id, int player1Score,
            char p1RightGrid[GRID_SIZE][GRID_SIZE], char p1LeftGrid[GRID_SIZE][GRID_SIZE], char p1PenaltyPanel[PENALTY_LENGTH],
            std::string player2, int player2Id, int player2Score,
            char p2RightGrid[GRID_SIZE][GRID_SIZE], char p2LeftGrid[GRID_SIZE][GRID_SIZE], char p2PenaltyPanel[PENALTY_LENGTH])
    {
        players.clear();
        boards.clear();

        Player* p1 = new Player(player1);
        p1 ->setPlayerId(player1Id);
        p1 ->setPlayerScore(player1Score);              
        Player* p2 = new Player(player2);
        p2 ->setPlayerId(player2Id);
        p2 ->setPlayerScore(player2Score);


        players.push_back(p1);
        players.push_back(p2);

        //Board* player1Board = new Board(p1RightGrid, p1LeftGrid, p1PenaltyPanel);
        //Board* player2Board = new Board(p2RightGrid, p2LeftGrid, p2PenaltyPanel);

        // for (int i = 0; i<NUM_FACTORIES; i++){
        //     Factories* factory = new Factories();
        //     factories.push_back(factory);
        // }

}

//Option to add player to vector
void Game::addToPlayers(Player* player){
    players.push_back(player);
}

//Adds pointer to tile to back of lid vector
void Game::addToLid(char tile){
    lid.push_back(tile);
}

//Adds pointer to tile to back of center vector 
void Game::addToCenter(char tile, bool choiceExtra){
    if (choiceExtra){
        extraCenter.push_back(tile);
    } else{
        center.push_back(tile);
    }
}

//Adds pointer to tile to the back of tilebag linked list
void Game::addToTileBag(char tile){
    //tileBag->addBack(tile);
}

//Returns number of players
int Game::getNumPlayers(){
    return players.size();
}

//Returns a player at certain index
Player* Game::getPlayer(int index){
    return players.at(index);
}

//Returns a factory at certain index
Factories* Game::getFactory(int index){
    return factories.at(index);
}

//Returns a string format of the lid
std::string Game::lidToString(){
    int lidSize = lid.size();
    std::string toString;
    for (int i = 0; i<lidSize; i++){
        toString = toString + lid.at(i) + "  ";
    }
    return toString;
}

//Returns a string format of the center
std::string Game::centerToString(bool extra){
    std::vector<char>* chosenCenter;
    if (extra){
        chosenCenter = &extraCenter;
    } else{
        chosenCenter = &center;
    }
    int centerSize = chosenCenter->size();
    std::string toString;
    for (int i = 0; i<centerSize; i++){
        toString = toString + chosenCenter->at(i) + " ";
    }
    return toString;
}

//Return a the number of centers for this game
int Game::getNumCenters(){
    return numCenters;
}

//Takes player turn from menu input and returns if valid
bool Game::playerTurn(int factoryChoice, char tile, int patternLine, int centerChoice){
    int numTiles = 0;
    if (factoryChoice == 0){
        return boards.at(currentPlayer-1)->setPatternTile(patternLine, tile, takeCenterTile(tile, false));
    } if (factoryChoice == 1 && numCenters == 2){
        return boards.at(currentPlayer-1)->setPatternTile(patternLine, tile, takeCenterTile(tile, true));
    } else{
        Factories* factory = factories.at(factoryChoice-1);
        numTiles = factory->takeTile(tile);
        std::string remainingTiles = factory->toString();
        for (int i = 0; i<8; i++){
            if (remainingTiles[i] != '\0' && remainingTiles[i] != '-' && remainingTiles[i] != ' ' && remainingTiles[i] != '0'){
                if (centerChoice==1){
                    addToCenter(remainingTiles[i], false);
                } else{
                    addToCenter(remainingTiles[i], true);
                }
            }
        }
    }   
    
    //Add number of Tiles to the chosen patternLine of a players board
    return boards.at(currentPlayer-1)->setPatternTile(patternLine, tile, numTiles);
}

//Take tile from the center
int Game::takeCenterTile(char tile, bool extra){
    std::vector<char>* chosenCenter;
    int numTiles = 0;
    bool deleting = true;
    int index = 0;

    if (!extra){
        chosenCenter = &center;
    } else {
        chosenCenter = &extraCenter;
    }

    while (deleting){
        if(chosenCenter->at(index) == tile){
            numTiles++;
            chosenCenter->erase(chosenCenter->begin() + index);
        } else{
            index++;
        }
        int centerSize = chosenCenter->size();
        if (index == centerSize){
            deleting = false;
        }
    }
    return numTiles;
}

//Uses ReadWrite to write save file
void Game::saveGame(std::string fileName){
    ReadWrite save;

    Player player1 = *players.at(0);
    std::string p1RightGrid = boards.at(0)->getWall(); 
    std::string p1LeftGrid = boards.at(0)->getPatternLines();
    std::string p1PenaltyPanel = boards.at(0)->getFloorLine();

    Player player2 = *players.at(1);
    std::string p2RightGrid = boards.at(1)->getWall(); 
    std::string p2LeftGrid = boards.at(1)->getPatternLines();
    std::string p2PenaltyPanel = boards.at(1)->getFloorLine();

    save.saveToFile(fileName, gameStatus, tileBag, lid, factories, currentPlayer, numberPlayers, player1,
                  p1RightGrid, p1LeftGrid, p1PenaltyPanel, player2, p1RightGrid, p2LeftGrid, p2PenaltyPanel);
}

//Sets the gamestatus to be true or false
void Game::setGameStatus(bool status){
    gameStatus = status;
}

//Set the current player number
void Game::setCurrentPlayer(int current){
    currentPlayer = current;
}

//Set the variable numberPlayers to be size of player vector
void Game::setNumberPlayers(){
    numberPlayers = players.size();
}

//For every board, check to see if patternLines are full 
//If full move tiles to wall
void Game::finishRound(){
    for (int i = 0; i<numPlayers; i++){
        Board* playerBoard = boards.at(i);
        playerBoard->checkPatternLines();
        std::vector<int> numToLid = playerBoard->getNumToLid();
        std::vector<char> tileToLid = playerBoard->getTileToLid();
        int vectorSize = numToLid.size();
        for (int i = 0; i<vectorSize; i++){
            for (int x = 0; x<=numToLid.at(i); x++){
                lid.push_back(tileToLid.at(i));
            }
        }
    }
}

void Game::checkScore(){
    for (int i = 0; i<numPlayers; i++){
        int score = boards.at(i) -> roundTally();
        players[i] -> setPlayerScore(score);
    }
}

std::string Game::getBoardString(int playerIndex){
    return boards.at(playerIndex)->toStringBoard();
}

int Game::getNumFactories(){
    return numFactories;
}
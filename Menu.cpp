//Menu Class
#include "Menu.h"
#include "Game.h"
#include "readWrite.h"

Menu::Menu(){
    welcome();
}

//return an input from console
int Menu::input(){
    int input = 0;
    std::cout << "> ";
    std::cin >> input;
    std::cout << std::endl;
    return input;
}

void Menu::roundInput(){
    //Check if valid input
    valid = false;
    while(!valid){
        //Make variables blank when false
        action = "";
        fileName = "";

        std::cout << "\nturn, save or help: \n> ";
        std::cin >> action;
        
        if (action != "turn" && action != "save" && action != "help"){
            std::cout << "\nInvalid Action (turn or save)" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (action == "turn"){
            bool turn = false;
            while (!turn){
                //Set variables to be outside range
                factoryChoice = 100;
                tile = '0';
                patternLine = 0;

                std::cout << "\nEnter Turn (Factory Tile PatternLine): \n>";
                std::cin >> factoryChoice >> tile >> patternLine;
                tile = toupper(tile);
                if (factoryChoice < 0 || factoryChoice >game->getNumFactories()){
                    std::cout << BOLDRED << "\nInvalid Factory" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else if (tiles.find(tile) == std::string::npos){
                    std::cout << BOLDRED << "\nInvalid Tile" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else if (patternLine < 1 || patternLine > 5){
                    std::cout << BOLDRED << "\nInvalid Pattern Line" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else {
                    //Passed Validation - use factorieChoice, tile and patternLine
                    turn = true;
                    valid = true;
                    //Option for excess tiles when extra center is in play
                    extraCenter = 0;
                    if (game->getNumCenters()==2){
                        bool centerValid = false;
                        while(!centerValid){
                            extraCenter = 0;
                            std::cout << "Enter which center you would like the excess tiles to go (1 or 2): " << std::endl;
                            std::cin >> extraCenter;
                            if (extraCenter < 1 || extraCenter > 2){
                                std::cout << BOLDRED << "\nInvalid Center Choice" << RESET << std::endl;
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                            } else{ 
                                centerValid = true;
                            }
                        }
                    }
                } 
            } 
        } else if (action == "save"){
            std::cout << "\nEnter File Name: \n>";
            std::cin >> fileName;
            game->saveGame(fileName);
            valid = true;
        } else if (action == "help"){
            help();
        }
    }
}
        
//Print welcome when menu object is created
void Menu::welcome(){
    std::cout << GREEN << "Welcome to Azul!" << std::endl;
    std::cout << "-------------------" << RESET << std::endl;
    std::cout << std::endl;
}

//display main menu options and ask for input
void Menu::mainMenu(){
    bool menu = true;
    while (menu){
        std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits (Show student information)" << std::endl;
        std::cout << RED << "4. Quit" << RESET << std::endl;
        std::cout << std::endl;
        
        int getInput = input();

        if (getInput == 1){
            newGame();
            menu = false;
        } else if (getInput == 2){
            loadGame();
            // menu = false; unquote this after game is made
        } else if (getInput == 3){
            credits();
        } else if (getInput == 4){
            quit();
            menu = false;
        } else if (getInput != 1 && getInput != 2 && getInput !=3 && getInput !=4) {
            std::cout << "invalid Command, Please Enter A Correct Value." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } 
        //end game if EOF command is entered
        if (std::cin.eof()){
            std::cout << "Goodbye." <<std::endl;
            std::exit(EXIT_SUCCESS);
            }
    }
}

//Print student details
void Menu::credits(){
    std::cout << "-------------------" << std::endl;
    for (int i=0; i<3; i++){
        std::cout << "Name: " << creditsArray[0][i] << std::endl;
        std::cout << "Student ID: " << creditsArray[1][i] << std::endl; 
        std::cout << "Email: " << creditsArray[2][i] << std::endl;   
        std::cout << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
}

//Function to start new game
void Menu::newGame(){
    std::cout << "Starting New Game" << std::endl;

    std::cout << "How many players?(2-4): " << std::endl;
    int numPlayers = 0;
    bool inValidPlayers = true;
    while (inValidPlayers){
        numPlayers = input();
        if (numPlayers < 2 || numPlayers > 4){
            std::cout << "Please Input Number Between 2 and 4" << std::endl;
            std::cin.ignore(1000, '\n');
        } else {
            inValidPlayers = false;
        }
    }

    std::cout << "1 or 2 Centre Factories?: " << std::endl;
    int centres = 0;
    bool inValidFactories = true;
    while (inValidFactories){
        centres = input();
        if (centres < 1 || centres > 2){
            std::cout << "Please Input Number Between 1 and 2" << std::endl;
            std::cin.ignore(1000, '\n');
        } else {
            inValidFactories = false;
        }
    }

    std::vector<std::string> players;
    for (int i = 0; i < numPlayers; i++){
        std::cout << "Enter Player " << i+1 << " Name: \n>";
        std::string playerName;
        std::cin >> playerName;
        std::cout << std::endl;
        players.push_back(playerName);
    }

    game = new Game(players, centres);

    std::cout << GREEN << "Welcome ";
    int playerSize = players.size();
    for (int i = 0; i<playerSize; i++){
        std::cout << players.at(i);
        if (i!=playerSize-1){
            std::cout << " and ";
        }
    }
    std::cout << std::endl;
    std::cout << "Let's Play!\n" << RESET << std::endl;
    game->setGameStatus(true);
    
    startRound();
}

//Function to load game
void Menu::loadGame(){
    std::cout << "Load Game!" << std::endl;

    // Game(bool gameStatus, Bag bag, vector<char> boxLid, Factories*[NUM_FACTORIES], int currentPlayer,
    //         std::string player1, int player1Id, int player1Score,
    //         char p1RightGrid[GRID_SIZE][GRID_SIZE], char p1LeftGrid[GRID_SIZE][GRID_SIZE], char p1PenaltyPanel[PENALTY_LENGTH],
    //         std::string player2, int player2Id, int player2Score,
    //         char p2RightGrid[GRID_SIZE][GRID_SIZE], char p2LeftGrid[GRID_SIZE][GRID_SIZE], char p2PenaltyPanel[PENALTY_LENGTH])
    ReadWrite* load = new ReadWrite();
    

    char p1LGrid[GRID_SIZE][GRID_SIZE];
    char p1RGrid[GRID_SIZE][GRID_SIZE];
    char p2LGrid[GRID_SIZE][GRID_SIZE];
    char p2RGrid[GRID_SIZE][GRID_SIZE];
    char p1Pen[PENALTY_LENGTH];
    char p2Pen[PENALTY_LENGTH];


    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            p1LGrid[i][j] = load -> loadPlayerLeftGrid(1,i,j);
            p2LGrid[i][j] = load -> loadPlayerLeftGrid(2,i,j);

            p1RGrid[i][j] = load -> loadPlayerRightGrid(1,i,j);
            p2RGrid[i][j] = load -> loadPlayerRightGrid(2,i,j);
        }
        p1Pen[i] = load ->loadPlayerPenaltyPanel(1, i);
        p2Pen[i] = load ->loadPlayerPenaltyPanel(2, i);

    }

    game = new Game(true, 1, 
    load->loadPlayerName(1), 1, load->loadPlayerScore(1),
    p1RGrid, p1LGrid, p1Pen,
    load->loadPlayerName(2), 2, load->loadPlayerScore(2),
    p2RGrid, p2LGrid, p2Pen);

    startRound();
}

//Function to quit game
void Menu::quit(){
    std::cout << RED << "Quit!" << RESET <<std::endl;
    exit(0);
}

//Call everytime a round starts
void Menu::startRound(){
    while(true){
        std::cout << BOLDWHITE << "=== Start Round ===" << RESET << std::endl;
        for (int i = 0; i<game->getNumPlayers(); i++){
            game->setCurrentPlayer(i+1);
            std::cout << BLUE << "\nTURN FOR PLAYER: " + game->getPlayer(i)->getUsername() << RESET << std::endl;
            std::cout << "Factories: " << std::endl;
            std::cout << BOLDYELLOW << "0: " << RESET << game->centerToString(false) << std::endl;
            int index = 0;
            if (game->getNumCenters()==2){
                index=1;
                std::cout << BOLDYELLOW << "1: " << RESET << game->centerToString(true) << std::endl;
            }
            //Prints factories with randomized tiles
            for (int i = 0; i<game->getNumFactories(); i++){
                Factories* factory = game->getFactory(i);
                std::cout << BOLDMAGENTA << i+1+index << ": " << RESET;
                std::cout << factory->toString() << std::endl;
            }
            
            std::cout << std::endl;

            std::cout << "Mosaic For " << game->getPlayer(i)->getUsername() << ":" << std::endl;
            std::cout << game->getBoardString(i) << std::endl;
            
            //display options for user to input (factoryNo (0-5), tile (colour) & patternline (1-5) )
            bool validTurn = false;
            while (!validTurn){
                roundInput(); 
                validTurn = game->playerTurn(factoryChoice, tile, patternLine, extraCenter);

                //UNCOMMENT THIS
                //game -> checkScore(); 
            }
        }
        game->finishRound();
        std::cout << "=== End Round ===" << std::endl;
    }
}

//Prints help menu
void Menu::help(){
    std::cout << "\n=== Help ===" << std::endl;
    std::cout << "Turn: " << std::endl;
    std::cout << "  After selecting turn, enter the factory in which you want to choose the tile from,\n    followed by the tile character and the pattern line the tile will be placed to on the players board" << std::endl;
    std::cout << "Save: " << std::endl;
    std::cout << "  After selecting save, choose a filename for the save file" << std::endl;
}




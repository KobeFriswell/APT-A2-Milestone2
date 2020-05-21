//Menu Class
#include "Menu.h"
#include "Game.h"

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

        std::cout << "\nturn or save: \n> ";
        std::cin >> action;
        
        if (action != "turn" && action != "save"){
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
                if (factoryChoice < 0 || factoryChoice >5){
                    std::cout << "\nInvalid Factory" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else if (tiles.find(tile) == std::string::npos){
                    std::cout << "\nInvalid Tile" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else if (patternLine < 1 || patternLine > 5){
                    std::cout << "\nInvalid Pattern Line" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                } else {

                    //Passed Validation - use factorieChoice, tile and patternLine
                    turn = true;
                    valid = true;
                } 
            } 
        } else if (action == "save"){
            std::cout << "\nEnter File Name: \n>";
            std::cin >> fileName;
            game->saveGame(fileName, gameStatus, currentPlayer, numberPlayers);
            valid = true;
        }
    }
}
        
//Print welcome when menu object is created
void Menu::welcome(){
    std::cout << "Welcome to Azul!" << std::endl;
    std::cout << "-------------------" << std::endl;
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
        std::cout << "4. Quit" << std::endl;
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

    std::cout << "Enter Player 1 Name: \n>";
    std::string player1;
    std::cin >> player1;
    std::cout << std::endl;

    std::cout << "Enter Player 2 Name: \n>";
    std::string player2;
    std::cin >> player2;
    std::cout << std::endl;

    game = new Game(player1, player2);

    std::cout << "Welcome " + player1 + " and " + player2 << std::endl;
    std::cout << "Let's Play!" << std::endl;
    gameStatus = true;
    
    startRound();
}

//Function to load game
void Menu::loadGame(){
    std::cout << "Load Game!" << std::endl;
}

//Function to quit game
void Menu::quit(){
    std::cout << "Quit!" << std::endl;
    exit(0);
}

void Menu::startRound(){
    std::cout << "=== Start Round ===" << std::endl;
    for (int i = 0; i<game->getNumPlayers(); i++){
        currentPlayer = i+1;
        std::cout << "\nTURN FOR PLAYER: " + game->getPlayer(i)->getUsername() << std::endl;
        std::cout << "Factories: " << std::endl;
        std::cout << "0: " << game->centerToString() << std::endl;
        for (int x = 0; x<NUM_FACTORIES; x++){
            Factories* factory = game->getFactory(x);
            std::cout << x+1 << ": ";
            std::cout << factory->toString() << std::endl;
        }
        
        std::cout << std::endl;

        std::cout << "Mosaic For " << game->getPlayer(i)->getUsername() << ":" << std::endl;
        //Call Mosaic Print Here

        roundInput();           
    }
    std::cout << "=== End Round ===" << std::endl;
}




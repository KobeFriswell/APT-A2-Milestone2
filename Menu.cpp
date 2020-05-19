//Menu Class
#include "Menu.h"
#include "Player.h"

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

            std::cout <<"---------------- " <<std::endl;

            std::cout << "enter name for player 1" << std::endl;
            std::string user1;
            std::cin>>user1;
            Player* player1 = new Player(user1);
            

            std::cout << "enter name for player 2" << std::endl;
            std::string user2;
            std::cin>>user2;
            Player* player2 = new Player(user2);

            std::cout <<"Lets play!" <<std::endl;
            std::cout <<"---------------- " <<std::endl;

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
    std::cout << "Starting a New Game" << std::endl;
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



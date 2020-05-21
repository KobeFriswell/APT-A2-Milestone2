#include <iostream>
#include <string>

#include "Game.h"

class Menu {
public:
    Menu();

    int input();
    void roundInput();
    void welcome();
    void mainMenu();

    void newGame();
    void loadGame();
    void credits();
    void quit();
    void startRound();

private: 
    //2D array to store student details
    std::string creditsArray[3][3] = {
        {"Kobe Friswell", "Mitchell Slavik", "Jacky Chuong"}, 
        {"s3783258", "s3723026", "s3780272"}, 
        {"s3783258@student.rmit.edu.au", "s3723026@student.rmit.edu.au", "s3780272@student.rmit.edu.au"}
    };

    Game* game;
    std::string tiles = "RYBLU";

    bool valid;
    std::string action;
    std::string fileName;
    int factoryChoice;
    char tile;
    int patternLine;
};

#include <iostream>
#include <string>

#include "Game.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
    int extraCenter;

    bool gameStatus;
    int currentPlayer;
    int numberPlayers;
};

#ifndef readWrite
#define readWrite

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "LinkedList.h"
#include "Node.h"
#include "Player.h"
#include "Factories.h"
#include "Bag.h"

#define GRID_SIZE 5
#define NUM_FACTORIES 5
#define PENALTY_LENGTH 7
#define NUM_PLAYERS 2

//libraries frequently used
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stoi;
using std::vector;


class ReadWrite{
    public:
        ReadWrite();
        void saveToFile(string fileName, int gameStatus, 
                Bag bag, vector<char> boxLid, vector<Factories*> factories, int currentPlayer, int numPlayers, 
                Player player1, string p1RightGrid, string p1LeftGrid, string p1PenaltyPanel,
                Player player2, string p2RightGrid, string p2LeftGrid, string p2PenaltyPanel
                );
    private:


    //METHODS
        
        void skip(ifstream inFile, string line);
        bool ignore(string s);
        int readFromFile();
        

//VARIABLES
        string line;
        char c;

//DATATYPES
        int hour,minute,second,day,month,year;
        string dateTime;
        bool gameStatus;
        LinkedList bag;
        vector<char> boxlid;
        vector<char> factory[NUM_FACTORIES];
        int currentPlayer;
        int numberPlayers;
        Player* player[NUM_PLAYERS];

//PLAYER VARIABLES
        string playerName[NUM_PLAYERS];
        int playerId[NUM_PLAYERS];
        int playerScore[NUM_PLAYERS];

        char p1RightGrid[GRID_SIZE][GRID_SIZE];
        char p1LeftGrid[GRID_SIZE][GRID_SIZE];
        char p2RightGrid[GRID_SIZE][GRID_SIZE];
        char p2LeftGrid[GRID_SIZE][GRID_SIZE];

        char p1PenaltyPanel[PENALTY_LENGTH];
        char p2PenaltyPanel[PENALTY_LENGTH];

};

#endif
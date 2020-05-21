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
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Player.h"
#include "Factories.h"
#include "Bag.h"
//#include "Player.cpp"

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
        void saveToFile(string fileName, int gameStatus, Bag bag, vector<char> boxLid, vector<char> center, vector<Factories*> 
                factories, int currentPlayer, int numPlayers, 
                Player player1, char p1RightGrid[gridSize][gridSize], char p1LeftGrid[gridSize][gridSize], char p1PenaltyPanel[penaltylength],
                Player player2, char p2RightGrid[gridSize][gridSize], char p2LeftGrid[gridSize][gridSize], char p2PenaltyPanel[penaltylength]
                );
    private:

    //CONST
        const static int gridSize = 5;
        const static int numFactories = 5;
        const static int penaltylength = 7;

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
        vector<int> center;
        vector<char> factory[numFactories];
        int currentPlayer;
        int numberPlayers;
        Player players[2];

//PLAYER VARIABLES
        string playerName;
        int playerId;
        int playerScore;
        char rightGrid[gridSize][gridSize];
        char leftGrid[gridSize][gridSize];
        char penaltyPanel[penaltylength];

};

#endif 

//CONST
const static int gridSize = 5;
const static int numFactories = 5;
const static int penaltylength = 7;

int hour,minute,second,day,month,year;

string dateTime;
bool gameStatus;
char c;

vector<int> center;
LinkedList bag;
LinkedList boxlid;
vector<char> factory[numFactories];

int currentPlayer;
int numberPlayers;
string playerName;
int playerId;
int playerScore;
char rightGrid[gridSize][gridSize];
char leftGrid[gridSize][gridSize];
char penaltyPanel[penaltylength];

Player players[2];
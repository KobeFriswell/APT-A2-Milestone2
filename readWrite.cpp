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
//#include "Player.cpp"




using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stoi;
using std::vector;

int hour,minute,second,day,month,year;

string dateTime;
bool gameStatus;

LinkedList bag;
char c;

//vector<int> center;
vector<int> center;

//vector<char> boxlid;
LinkedList boxlid;

LinkedList factory[5];

int currentPlayer;
int numberPlayers;

string playerName;
int playerId;
int playerScore;

char rightGrid[5][6];

char leftGrid1[2];
char leftGrid2[3];
char leftGrid3[4];
char leftGrid4[5];
char leftGrid5[6];

char penaltyPanel[5];

//Player players[2];

std::ifstream inFile("example.txt");
string line;

bool ignore(string s){
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}

void skip(ifstream inFile, string line){
    getline(inFile,line);
    while(ignore(line)){
        getline(inFile,line);
        }
        
}



int main(){
    
    std::ifstream inFile("example.txt");
    string line;

    if(!inFile.is_open()){
        cout<<"File failed to open"<<endl;
        return 0;

        cout<<"-File Opened"<<endl;
        
    } else {
// SAVE DATE
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        dateTime=line;
        cout<<line<<endl;


// GAME STATUS
        getline(inFile,line);
        while(ignore(line)){  
            getline(inFile,line);
        }
        
        if(line=="1"){
            gameStatus=true;
        } else {
            gameStatus=false;
        }
        cout<<"game status " + line<<endl;

// BAG
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        for (unsigned i=0; i<line.length()-1; ++i){
            c = line.at(i);
            bag.addFront(c);
        }
        cout<<"Bag " + line<<endl;


// BOX LID
        getline(inFile,line);
        
        while(ignore(line)){
            getline(inFile,line);
        }
        //TODO vector
        for (unsigned i=0; i<line.length()-1; ++i){
            c = line.at(i);
            boxlid.addFront(c);
        }

        cout<<"Box lid " + line<<endl;


// FACTORIES
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //for the 5 factories
        for(int i=0;i<5;i++){
            //print the content of the factory as a string
            cout<< i <<"factory " + line<<endl;

            for (unsigned i=0; i<line.length()-1; ++i){
            c = line.at(i);
            factory[i].addFront(c);
            } 

            getline(inFile,line);
        }

// CURRENT PLAYER
       //getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        currentPlayer=std::stoi(line);
        cout<<"current player " << currentPlayer<<endl;
        

// NUMBER OF PLAYER
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        numberPlayers=std::stoi(line);
        cout<<"number palyers " << numberPlayers <<endl;

        cout<<"----------------------------------------------"<<endl;
// ADDING PLAYERS

        for(int i=0; i<=1 ;i++){
            cout<<"PLAYER: "<<i+1<<endl;
            //player name
            //player id
            //players score
            //right grid
            //left grid
            //penalty panel


             getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerName = line;
        cout<<"Player name " << playerName <<endl;

             getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }


        playerId=std::stoi(line);
        cout<<"playerid " << playerId<<endl;

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerScore = stoi(line);
        cout<<"player Score " << playerScore <<endl;

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO right grid
        cout<<"rightgrid:"<<endl;
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
            //add chatacters to array
            c = line.at(j);
            rightGrid[i][j] = c;
            cout<<rightGrid[i][j];
            }
            cout<<endl;
            getline(inFile,line);
            
        }

        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO left grid arrays
        cout<<"leftgrid:"<<endl;
        for(int i=0; i<1;i++){
            c = line.at(i);
            leftGrid1[i] = c;
            cout<<leftGrid1[i];
        }
        cout<<endl;
        getline(inFile,line);
        

        for(int i=0; i<2;i++){
            c = line.at(i);
            leftGrid2[i] = c;
            cout<<leftGrid2[i];
        }
        cout<<endl;

        getline(inFile,line);
        
        
        for(int i=0; i<3;i++){
            c = line.at(i);
            leftGrid3[i] = c;
            cout<<leftGrid2[i];
        }
        cout<<endl;

        getline(inFile,line);
        

        for(int i=0; i<4;i++){
            c = line.at(i);
            leftGrid4[i] = c;
            cout<<leftGrid4[i];
        }
        cout<<endl;

        getline(inFile,line);
        

        for(int i=0; i<5;i++){
            c = line.at(i);
            leftGrid5[i] = c;
            cout<<leftGrid5[i];
        }
        cout<<endl;
        getline(inFile,line);
        

        while(ignore(line)){
            getline(inFile,line);
        }



        cout<<"penaltyPanel:";
        for(int i=0; i<5;i++){
            c = line.at(i);
            penaltyPanel[i] = c;
            cout<< penaltyPanel[i];
        }
        cout<<endl;

        //CREATE A PLAYER

        std::cout << "----------------------------------------------" << std::endl;

        }        
    }

    exit (EXIT_SUCCESS);
    
}
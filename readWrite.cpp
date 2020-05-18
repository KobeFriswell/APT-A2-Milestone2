#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stoi;

int hour,minute,second,day,month,year;

string dateTime;
bool gameStatus;

//LinkedList bag = LinkedList();
LinkedList bag;


//vector center

//vector char boxlid;
string boxLid;

//LinkedList factories = LinkedList();
LinkedList factories;

int currentPlayer;
int numberPlayers;

string playerName;
int playerId;
int playerScore;

char rightGrid[5][5];

char leftGrid1[1];
char leftGrid2[2];
char leftGrid3[3];
char leftGrid4[4];
char leftGrid5[5];
string penaltyPanel;
//char penaltyPanel[5];

bool ignore(string s){
    //cout<<"call ignore"<<endl;
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}

void skip(ifstream inFile, string line){
    getline(inFile,line);
    while(ignore(line)){
        cout<<"-empty line" + line <<endl;
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
//  getline(file to look at, where to store that line)
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
        cout<<"Bag " + line<<endl;
        //TODO linkedlist
        //bag=line;

// BOX LID
        getline(inFile,line);
        
        while(ignore(line)){
            getline(inFile,line);
        }
        cout<<"Box lid " + line<<endl;
        //TODO vector
        //boxlid=line;

// FACTORIES
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //for the 5 factories
        for(int i=0;i<5;i++){

            cout<< i <<"factory " + line<<endl;
            getline(inFile,line);

            // TODO
            // while(char!='$'){
            //     //TODO
            //     //if character != $ add the vector
            // }  
        }

// CURRENT PLAYER
       //getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        cout<<"current player " + line<<endl;
        //currentPlayer=std::stoi(line);

// NUMBER OF PLAYER
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        //numberPlayers=std::stoi(line);
        cout<<"number palyers " + line<<endl;

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
        cout<<"Player name " + line<<endl;

             getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //playerId=std::stoi(line);
        cout<<"playerid " + line<<endl;

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //playerScore=std::stoi(line);
        cout<<"player Score " + line<<endl;

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO right grid
        for (int i=0;i<5;i++){
//             for (int j=0;i<5;j++){
//                 //add chatacters to array
//                 string s = line;
//                 strcpy(rightGrid[i], s.c_str());
//             }
            cout<<"rightgird " + line <<endl;
            getline(inFile,line);
            
        }

        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO left grid arrays
        string s = line;
        //strcpy(leftGrid1, s.c_str());
        cout<<"leftgird " + line <<endl;
        getline(inFile,line);
        

        s = line;
        //strcpy(leftGrid2, s.c_str());
        cout<<"leftgird " + line <<endl;
        getline(inFile,line);
        
        
        
        s = line;
        //strcpy(leftGrid3, s.c_str());
        cout<<"leftgird " + line <<endl;
        getline(inFile,line);
        

        s = line;
        //strcpy(leftGrid4, s.c_str());
        cout<<"leftgird " + line <<endl;
        getline(inFile,line);
        

        s = line;
        //strcpy(leftGrid5, s.c_str());
        cout<<"leftgird " + line <<endl;
        getline(inFile,line);
        

        while(ignore(line)){
            getline(inFile,line);
        }

        penaltyPanel = line;
        cout<<"penalty panel" + line <<endl;

        //CREATE A PLAYER

        std::cout << "----------------------------------------------" << std::endl;

        }        
    }

    exit (EXIT_SUCCESS);
    
}
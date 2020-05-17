#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;

int hour,minute,second,day,month,year;

string dateTime;
bool gameStatus;

LinkedList bag = new LinkedList();

//vector center

//linkedlist char bag;

//vector char boxlid;
string boxLid;

// linkedlist char factories;

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



int main(){
    ifstream inFile("example.txt");
    //inFile.open ("test.txt");
    string line;

    if(!inFile.is_open()){
        cout<<"File failed to open"<<endl;
        return 0;
    } else {
//  getline(file to look at, where to store that line)
// SAVE DATE
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        dateTime=line;


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

// BAG
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //TODO linkedlist
        bag=line;

// BOX LID
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //TODO vector
        boxlid=line;

// FACTORIES
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //for the 5 factories
        for(int i=0;i<5;i++){

            // TODO
            // while(char!='$'){
            //     //TODO
            //     //if character != $ add the vector
            // }  
        }

// CURRENT PLAYER
       getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        currentPlayer=std::stoi(line);

// NUMBER OF PLAYER
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        } 
        numberPlayers=std::stoi(line);

// ADDING PLAYERS

        for(int i=0; i<2;i++){
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

             getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerId=std::stoi(line);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerScore=std::stoi(line);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO right grid
        for (int i=0;i<5;i++){
            for (int j=0;i<5;j++){
                //add chatacters to array
                string s = line;
                strcpy(rightGrid[i], s.c_str());
            }
            getline(inFile,line);
        }


         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //TODO left grid arrays
        string s = line;
        strcpy(leftGrid1, s.c_str());
        getline(inFile,line);

        s = line;
        strcpy(leftGrid2, s.c_str());
        getline(inFile,line);
        
        s = line;
        strcpy(leftGrid3, s.c_str());
        getline(inFile,line);

        s = line;
        strcpy(leftGrid4, s.c_str());
        getline(inFile,line);

        s = line;
        strcpy(leftGrid5, s.c_str());
        getline(inFile,line);


         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        penaltyPanel = line;

        //create player
    }
    //EXIT FILE
    inFile("example.txt").close();

}

bool ignore(string s){
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}

void skip(ifstream inFile, string line){
    getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
}










// int main() {
//     string line;
//     std::ifstream file ("example.txt");
//     if(!file.is_open()){
//         cout<<"File failed to open"<<endl;
//         return 0;
//     }
//     string s;
//     string myString;
// //  getline(file to look at, where to store that line)
//     while(std::getline(file, line)){
//         // ss(stored line)
//         std::stringstream ss(line);
//         if(line[0]!='#' && line[0]!='/' && line.length()!=0){
//         }
//         //std::getline(call it on ss, where to store, where to stop looking)
//     }
// }
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
string bag;
string boxLid;

// linkedlist char factories;

int currentPlayer;
int numberPlayers;

bool ignore(string s){
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}


int main(){
    ifstream inFile("example.txt");
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
        //TODO
        //bag=line;

// BOX LID
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //TODO
        //boxlid=line;

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
            //     //if character != $ add the linkedlist
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

        for(int i=0; i<=numberPlayers;i++){
            //player name
            //player id
            //players score
            //right grid
            //left grid
            //penalty panel

        }

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
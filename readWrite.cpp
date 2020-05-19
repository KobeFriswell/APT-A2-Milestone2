#include "readWrite.h"

std::ifstream inFile("example.txt");
string line;

// readWrite::readWrite(){
//     //Empty
// }

bool ignore(string s){
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}

int dataFromFile(){
    
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
        //TODO vector?
        for (unsigned i=0; i<line.length()-1; ++i){
            c = line.at(i);
            boxlid.addFront(c);
        }

        cout<<"Box lid " + line<<endl;

        // CENTER
         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        cout<<"center: ";
        for (unsigned i=0; i<line.length()-1; i++){
            c = line.at(i);
            cout<<c;
            center.push_back(c);
        }
        cout<<endl;


// FACTORIES
        getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }
        //for the 5 factories
        for(int i=0;i<gridSize;i++){
            //print the content of the factory as a string
            cout<< i <<"factory " + line<<endl;

            for (unsigned i=0; i<line.length()-1; ++i){
            c = line.at(i);

            factory[i].push_back(c);
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

        for(int i=0; i<numberPlayers ;i++){
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

        //Player patternlines on the right
        cout<<"rightgrid:"<<endl;
        for (int i=0;i<gridSize;i++){
            for (int j=0;j<gridSize;j++){
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

        //Players tiles in a tiangle on the left side
        cout<<"leftgrid:"<<endl;
        for (int i =0; i<gridSize; i++){
            for (int j=0; j<=i; j++){
                c = line.at(j);
                leftGrid[i][j] = c;
                cout<<leftGrid[i][j];
            }
            getline(inFile,line);
            cout<<endl;
        }

        while(ignore(line)){
            getline(inFile,line);
        }

        cout<<"penaltyPanel:";
        for(int i=0; i<penaltylength;i++){
            c = line.at(i);
            penaltyPanel[i] = c;
            cout<< penaltyPanel[i];
        }
        cout<<endl;

        //CREATE A PLAYER HERE

        std::cout << "----------------------------------------------" << std::endl;

        }        
    }

    exit (EXIT_SUCCESS);
    
}

int main(){
    dataFromFile();
}
#include "readWrite.h"

std::ifstream inFile("example.txt");
string line;

// readWrite::readWrite(){
//     //Empty
// }

ReadWrite::ReadWrite(){
    
}

bool ReadWrite::ignore(string s){
    return (s.length()==0 || s[0]=='#' || s[0]=='/');
}

int ReadWrite::readFromFile(){
    
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
        inFile.close();        
    }

    exit (EXIT_SUCCESS);
    
}


/* Method creates a savefile of the game status
    requires:
    - save name
    - date of save (can be done inside the method)
    - game status (1 or 0)
    - a bag object
    - a boxlid
    - a center
    - 5 factories
    - the current player
    - number of players
    THEN PLAYESRS 1 and 2 FORMAT
    - name
    - playerId
    - score/points
    - 5x5 wall tile grid
    - 5x5 left grid in triangle ^
    - penaltyPanel/floorline
      
    */
void ReadWrite::saveToFile(string fileName, int gameStatus, Bag bag, vector<char> boxLid, vector<char> center, vector<Factories*> 
                factories, int currentPlayer, int numPlayers, 
                Player player1, char p1RightGrid[gridSize][gridSize], char p1LeftGrid[gridSize][gridSize], char p1PenaltyPanel[penaltylength],
                Player player2, char p2RightGrid[gridSize][gridSize], char p2LeftGrid[gridSize][gridSize], char p2PenaltyPanel[penaltylength]
                ){

    //open file stream to the selected txtfile
    ofstream newSaveFile;
    //if the file already exists in the file directory
    newSaveFile.open (fileName);

    //Save Date
    newSaveFile << "#save date\n";
    newSaveFile << "HH:MM:SS DD-MM-YYYY" << "\n\n";
    
    //Game status
    newSaveFile << "#Game Status\n";
    newSaveFile << gameStatus << "\n\n";

    //Bag
    newSaveFile << "#Bag \n";
    for(int i = 0; i<bag.size(); i++){
        newSaveFile << bag.getData(i);
        
    }
    newSaveFile << "$\n\n";

    //BoxLid
    newSaveFile << "BoxLid\n";
    for(int i = 0; i<boxLid.size(); i++){
        newSaveFile << boxLid.getData(i);
    }
    newSaveFile << "$\n\n";

    //Center
    newSaveFile << "Center\n";
    for(unsigned i = 0; i<center.size(); i++){
        newSaveFile << center.at(i);
    }
    newSaveFile << "$\n\n";

    //5 Factories
    for(int i = 0; i<numFactories; i++){
        for(unsigned j; j < factories[i].size(); j++){
            newSaveFile << factories[i].at(j);
        }
        newSaveFile << "$\n";
    }
    newSaveFile << "\n\n";

    //current player
    newSaveFile << "#Current Player\n";
    newSaveFile << currentPlayer << "\n\n";

    //Number of Players
    newSaveFile << "#Number of Player\n";
    newSaveFile << numberPlayers << "\n\n";


    // -----------PLAYER 1----------------
    newSaveFile << "#Player1" << "\n";
    newSaveFile << player1.getUsername() << "\n";
    //newSaveFile << player1.getPlayerId() << "\n";
    newSaveFile << player1.getPlayerScore() << "\n";

    //5x5 wall tiles
    newSaveFile << "Right Wall Tile\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j<gridSize; j++){
            newSaveFile << p1RightGrid[i][j];
        }
        newSaveFile << "\n";
    }
    newSaveFile << "\n\n";

    newSaveFile << "Left Wall Triangle\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j<=i; j++){
            newSaveFile << p1LeftGrid[i][j];
        }
        newSaveFile << "\n";
    }
    newSaveFile << "\n\n";


    newSaveFile << "Penalty Panel\n";
    for (int i = 0; i < penaltylength; i++){
        newSaveFile << p1PenaltyPanel[i];
    }
    newSaveFile << "\n\n";

// ---------PLAYER 2----------------
    newSaveFile << "#Player2" << "\n";
    newSaveFile << player2.getUsername() << "\n";
    //newSaveFile << player2.getPlayerId() << "\n";
    newSaveFile << player2.getPlayerScore() << "\n";

    //5x5 wall tiles
    newSaveFile << "Right Wall Tile\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j<gridSize; j++){
            newSaveFile << p2RightGrid[i][j];
        }
        newSaveFile << "\n";
    }
    newSaveFile << "\n\n";

    newSaveFile << "Left Wall Triangle\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j<=i; j++){
            newSaveFile << p2LeftGrid[i][j];
        }
        newSaveFile << "\n";
    }
    newSaveFile << "\n\n";


    newSaveFile << "Penalty Panel\n";
    for (int i = 0; i < penaltylength; i++){
        newSaveFile << p2PenaltyPanel[i];
    }
    newSaveFile << "\n\n";

    newSaveFile.close();

}

int main(){
    dataFromFile();
}
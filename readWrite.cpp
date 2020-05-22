#include "readWrite.h"

std::ifstream inFile("example.txt");
string line;


ReadWrite::ReadWrite(){
    //readFromFile();
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
            boxlid.push_back(c);
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
        for(int i=0;i<GRID_SIZE;i++){
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

// ADDING PLAYER 1

        cout<<"PLAYER: "<< "1" <<endl;
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

        playerName[0] = line;
        cout<<"Player name " << playerName[0] <<endl;
        player[0] = new Player(playerName[0]);
        getline(inFile,line);
        while(ignore(line)){
        getline(inFile,line);
        }


        playerId[0] = std::stoi(line);
        cout<<"playerid " << playerId[0] <<endl;
        player[0] -> setPlayerId(playerId[0]);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerScore[0] = stoi(line);
        cout<<"player Score " << playerScore[0] <<endl;
        player[0] -> setPlayerScore(playerScore[0]);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //Player patternlines on the right
        cout<<"rightgrid:"<<endl;
        for (int i=0;i<GRID_SIZE;i++){
            for (int j=0;j<GRID_SIZE;j++){

                //add chatacters to array
                c = line.at(j);
                p1RightGrid[i][j] = c;
                cout<<p1RightGrid[i][j];
            }
            cout<<endl;
            getline(inFile,line);
            
        }

        while(ignore(line)){
            getline(inFile,line);
        }

        //Players tiles in a tiangle on the left side
        cout<<"leftgrid:"<<endl;
        for (int i =0; i<GRID_SIZE; i++){
            for (int j=0; j<=i; j++){
                c = line.at(j);
                p1LeftGrid[i][j] = c;
                cout<<p1LeftGrid[i][j];
            }
            getline(inFile,line);
            cout<<endl;
        }

        while(ignore(line)){
            getline(inFile,line);
        }

    cout<<"penaltyPanel:";
    for(int i=0; i<PENALTY_LENGTH;i++){
        c = line.at(i);
        p1PenaltyPanel[i] = c;
        cout<< p1PenaltyPanel[i];
    }
    cout<<endl;

    std::cout << "----------------------------------------------" << std::endl;
    
// ADDING PLAYER 2

        cout<<"PLAYER: "<< "2" <<endl;
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

        
        playerName[1] = line;
        cout<<"Player name " << playerName[1] <<endl;
        player[1] = new Player(playerName[1]);

             getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }


        playerId[1] = std::stoi(line);
        cout<<"playerid " << playerId[1] <<endl;
        player[1] -> setPlayerId(playerId[1]);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        playerScore[1] = stoi(line);
        cout<<"player Score " << playerScore[1] <<endl;
        player[1] -> setPlayerScore(playerScore[1]);

         getline(inFile,line);
        while(ignore(line)){
            getline(inFile,line);
        }

        //Player patternlines on the right
        cout<<"rightgrid:"<<endl;
        for (int i=0;i<GRID_SIZE;i++){
            for (int j=0;j<GRID_SIZE;j++){

                //add chatacters to array
                c = line.at(j);
                p2RightGrid[i][j] = c;
                cout<<p2RightGrid[i][j];
            }
            cout<<endl;
            getline(inFile,line);
            
        }

        while(ignore(line)){
            getline(inFile,line);
        }

        //Players tiles in a tiangle on the left side
        cout<<"leftgrid:"<<endl;
        for (int i =0; i<GRID_SIZE; i++){
            for (int j=0; j<=i; j++){
                c = line.at(j);
                p2LeftGrid[i][j] = c;
                cout<<p2LeftGrid[i][j];
            }
            getline(inFile,line);
            cout<<endl;
        }

        while(ignore(line)){
            getline(inFile,line);
        }

    cout<<"penaltyPanel:";
    for(int i=0; i<PENALTY_LENGTH;i++){
        c = line.at(i);
        p2PenaltyPanel[i] = c;
        cout<< p2PenaltyPanel[i];
    }
    cout<<endl;

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
void ReadWrite::saveToFile(string fileName, int gameStatus, 
                Bag bag, vector<char> boxLid, vector<char> center, vector<Factories*> factories, int currentPlayer, int numPlayers, 
                Player player1, string p1RightGrid, string p1LeftGrid, string p1PenaltyPanel,
                Player player2, string p2RightGrid, string p2LeftGrid, string p2PenaltyPanel
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
    string s = bag.saveString();

    //newSaveFile << bag.getData(i);
    newSaveFile << bag.saveString();

    newSaveFile << "$\n\n";

    //BoxLid
    newSaveFile << "BoxLid\n";
    for(unsigned i = 0; i<boxLid.size(); i++){
        newSaveFile << boxLid.at(i);
    }
    newSaveFile << "$\n\n";

    //Center
    newSaveFile << "Center\n";
    for(unsigned i = 0; i<center.size(); i++){
        newSaveFile << center.at(i);
    }
    newSaveFile << "$\n\n";

    //5 Factories
    for(unsigned i = 0; i< NUM_FACTORIES; i++){

        newSaveFile << factories.at(i) -> saveString();

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
    newSaveFile << player1.getPlayerId() << "\n";
    newSaveFile << player1.getPlayerScore() << "\n";

    //5x5 wall tiles
    newSaveFile << "Right Wall Tile\n";
    newSaveFile << p1RightGrid;
    // for (int i = 0; i < GRID_SIZE; i++){
    //     for (int j = 0; j<GRID_SIZE; j++){
    //         newSaveFile << p1RightGrid[i][j];
    //     }
    //     newSaveFile << "\n";
    // }
    newSaveFile << "\n\n";

    newSaveFile << "Left Wall Triangle\n";
    newSaveFile << p1RightGrid;
    // for (int i = 0; i < GRID_SIZE; i++){
    //     for (int j = 0; j<=i; j++){
    //         newSaveFile << p1LeftGrid[i][j];
    //     }
    //     newSaveFile << "\n";
    // }
    newSaveFile << "\n\n";


    newSaveFile << "Penalty Panel\n";
    newSaveFile << p1PenaltyPanel;
    // for (int i = 0; i < PENALTY_LENGTH; i++){
    //     newSaveFile << p1PenaltyPanel[i];
    // }
    newSaveFile << "\n\n";

// ---------PLAYER 2----------------
    newSaveFile << "#Player2" << "\n";
    newSaveFile << player2.getUsername() << "\n";
    newSaveFile << player2.getPlayerId() << "\n";
    newSaveFile << player2.getPlayerScore() << "\n";

    //5x5 wall tiles
    newSaveFile << "Right Wall Tile\n";
    newSaveFile << p2RightGrid;
    // for (int i = 0; i < GRID_SIZE; i++){
    //     for (int j = 0; j<GRID_SIZE; j++){
    //         newSaveFile << p2RightGrid[i][j];
    //     }
    //     newSaveFile << "\n";
    // }
    newSaveFile << "\n\n";

    newSaveFile << "Left Wall Triangle\n";
    newSaveFile << p2LeftGrid;
    // for (int i = 0; i < GRID_SIZE; i++){
    //     for (int j = 0; j<=i; j++){
    //         newSaveFile << p2LeftGrid[i][j];
    //     }
    //     newSaveFile << "\n";
    // }
    newSaveFile << "\n\n";


    newSaveFile << "Penalty Panel\n";
    newSaveFile << p2PenaltyPanel;
    // for (int i = 0; i < PENALTY_LENGTH; i++){
    //     newSaveFile << p2PenaltyPanel[i];
    // }
    newSaveFile << "\n\n";

    newSaveFile.close();

}

// int main(){
//     readFromFile();
// }

// int loadPlayerScore(int playerId){
//     return playerScore[playerId-1];
// }

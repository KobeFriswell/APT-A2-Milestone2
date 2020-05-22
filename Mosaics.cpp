//Mosacis class

#include "Mosaics.h"
    

Mosaics::Mosaics(Player* player){
 this->player = player;
    this->pointBoard = new char*[BOARD_SIZE];
    this->turnBoard = new char*[BOARD_SIZE];
    this->pointCalculator = new char*[BOARD_SIZE];
    for(int x =0; x < 5; x++)
    {
        this->turnBoard[x] = new char[x+1];
        this->pointBoard[x] = new char[BOARD_SIZE];
        this->pointCalculator[x] = new char[BOARD_SIZE];
    }
    
    for(int x=0; x< BOARD_SIZE; x++)
    {
        for(int y = 0; y <BOARD_SIZE; y++)
        {
            this->pointCalculator[x][y] = EMPTY;
        }
    }
    
    for(int x = 0; x <= BOARD_SIZE-1; x++)
    {
        for(int y = BOARD_SIZE-1; y >= 0; y--)
        {
            if(x+y < BOARD_SIZE-1)
            {
                        this->turnBoard[x][y].setColour(' ');
            }
            else
            {
                this->turnBoard[x][y].setColour(EMPTY);
            }
            
        }
    }
     
    for(int x = 0; x <= BOARD_SIZE-1; x++)
    {
       
        
        this->pointBoard[x][x] =    EMPTY;
        this->pointBoard[x][x+1] =  EMPTY;
        this->pointBoard[x][x+2] =  EMPTY;
        this->pointBoard[x][x+3] =  EMPTY;
        this->pointBoard[x][x+4] =  EMPTY;
        
        this->pointBoard[x][x-1] =  EMPTY;
        this->pointBoard[x][x-2] =  EMPTY;
        this->pointBoard[x][x-3] =  EMPTY;
        this->pointBoard[x][x-4] =  EMPTY;
    }
    
    remainder = new LinkedList();
    for(int x =0; x < BROKEN_AREA; x++)
    {
        this->broken[x] = nullptr;
    }
}


Mosaics::~Mosaics() {
player->~Player();
    for(int x =0; x < BOARD_SIZE; x++)
    {
        delete this->pointBoard[x];
        delete this->turnBoard[x];
        delete this->pointCalculator[x];
    }
    for(int x =0; x < BROKEN_AREA;x++)
    {
        delete broken[x];
    }
    delete this->remainder;
}
void Mosaics::setPlayer(Player* player){
        this->player = player;
}

 void Mosaics::DisplayMosaics(){
         std::cout << "Mosaic for " << this-> player ->getUsername() <<std::endl;
         for(int x =0; x < BOARD_SIZE; x++){

                 std::cout <<x+1<<": ";

        for (int y =0; y < BOARD_SIZE ;y++ ){

            std::cout <<this-> turnBoard[x][y].getColour();
            std::cout <<"  ";
        }
        std::cout <<"||";
        for (int y =0; y < BOARD_SIZE ;y++ )
        {
            std::cout <<"  ";
            std::cout << this-> pointBoard[x][y].getColour();

        }

        std::cout <<std::endl;
    }

         std::cout <<"broken: ";
         for(int x = 0; x < BROKEN_AREA; x++){
           if(broken[x] != nullptr)
        {
            std::cout<<broken[x]->getColour()<<" ";
            std::cout <<" ";
        }
    }
    std::cout <<std::endl;
}


bool Mosaics::PositionTiles(int row, int number, char tiles){
 row -= 1;
    
    if(tiles == CURRENTPLAYERTURN)
    {
        this->WhosFirst = true;
        this->broken[this->brokenScore] = new char(tiles);
        this->broken++;
        return true;
    }
    
    bool valid = false;
    
    for(int x = 0; x <BOARD_SIZE; x++)
    {
       if(this->pointBoard[row][x].getColour() == tolower(tiles))
       {
           valid = true;
       }
        
    }
    for(int x = 0; x <BOARD_SIZE; x++)
    {
        if(this->turnBoard[row][x].getColour() != EMPTY
        && this->turnBoard[row][x].getColour() != tiles
        && this->turnBoard[row][x].getColour() != ' ')
        {
            valid = false;
        }
    }
    
    if(valid == true)
    {
        for (int x =0; x <= BOARD_SIZE; x++)
        {
           
            if(this->turnBoard[row][5-x].getColour() == EMPTY && number != 0)
            {
                this->turnBoard[row][5-x] = tiles;
                number--;
            }
        }
        if(number != 0)
        {
            
            for(int x =0; x < number; x++)
            {
                if(brokenScore < BROKEN_AREA)
                {
                    
                    this->broken[this->brokenScore] = new char(c);
                    this->brokenScore++;

                }
            }
        }
        return valid;
        
    }
    
    else
    {   if(number != 0)
        { 
        for(int x =0; x < number; x++)
        {
            if(brokenScore < BROKEN_AREA)
            {
                this->broken[this->brokenScore] = new char(tiles);
                this->brokenScore++;
                
            }
        }
    }
        return valid;
    }}


void Mosaics::CheckTurn() {
        for (int x = 0; x < BOARD_SIZE; x++)
    {
        bool fullrow = true;
        char tiles = EMPTY;
        for (int y = BOARD_SIZE-1; y >= 0; y--)
        {
            if(this->turnBoard[x][y].getColour() == EMPTY)
            {
                fullrow = false;
            }
            else if(this->turnBoard[x][y].getColour() != ' ')
            {
                tiles = this->turnBoard[x][y].getColour();
            }
        }
        
        if(fullrow == true)
        {
            for (int y = BOARD_SIZE-1; y >= 0; y--)
            {
                if(this->turnBoard[x][y].getColour() != ' ' && y < 4)
                {
                    this->turnBoard[x][y].setColour(EMPTY);
                    remainder->addBack(new char(tiles));
                }
                
                if(this->pointBoard[x][y].getColour() == tolower(tiles))
                {
                    this->pointBoard[x][y].setColour(tiles);
                    this->pointCalculator[x][y] = 'o';
                }
            }
            this->turnBoard[x][4].setColour(EMPTY);
        }
    }
    this->sumtotal();
}

bool Mosaics::WhosFirst() {
        return this->currentTurn;
}

bool Mosaics::winCheck() {

        for(int x =0; x < BOARD_SIZE; x++)
    {
        bool fullrow = true;
        
        for(int y =0; y < BOARD_SIZE; y++)
        {
            if(this->pointBoard[x][y].getColour() == tolower(this->pointBoard[x][y].getColour()))
            {
                fullrow = false;
            }
           
        }
        
        if(fullrow)
        {
            return true;
        }
    }
    
    return false;
}

LinkedList* Mosaics::returnTiles()
{
    for(int x = 0; x < brokenScore; x++)
    {
            this->remainder->addBack(broken[x]);
            this->broken[x] = new char(' ');
    }
    this->brokenScore = 0;
    return this->remainder;
}

//calcuate 
void Mosaics::sumtotal(){

}

Player* Mosaics::getPlayer()
{
    return this->player;
}

void Mosaics::setPointBoard(char **pointBoard)
{
    this->pointBoard = pointBoard;
    int UCount = 0;
    int LCount = 0;
    int BCount = 0;
    int YCount = 0;
    int RCount = 0;
    
    for(int x = 0; x <  BOARD_SIZE; x++)
    {
        for(int y = 0; y <  BOARD_SIZE; y++)
        {
            switch (pointBoard[x][y].getColour())
            {
                case RED: RCount++;
                case BLACK: UCount++;
                case LIGHT_BLUE: LCount++;
                case DARK_BLUE: BCount++;
                case YELLOW: YCount++;
            }
        }
    }
    if(UCount == 5 && this->colourCounting[0] == false) this->colourCounting[0] = true;
    if(LCount == 5 && this->colourCounting[1] == false) this->colourCounting[1] = true;
    if(BCount == 5 && this->colourCounting[2] == false) this->colourCounting[2] = true;
    if(YCount == 5 && this->colourCounting[3] == false) this->colourCounting[3] = true;
    if(RCount == 5 && this->colourCounting[4] == false) this->colourCounting[4] = true;
    
}

bool Mosaics::whosTurn()
{
    return this->currentTurn;
}

void Mosaics::setTurn(bool turn)
{
    this->currentTurn = turn;
}

void Mosaics::setFirst(bool first)
{
    this->holdfirst = first;
}


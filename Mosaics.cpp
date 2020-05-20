//Mosacis class

#include "Mosaics.h"
    

Mosaics::Mosaics(Player* player){
        this->player = player;
}

void Mosaics::setPlayer(Player* player){
        this->player = player;
}

 void Mosaics::DisplayMosaics(){
         std::cout << "Mosaic for " << this-> player ->getUsername() <<std::endl;
         for(int x =0; x < BOARD_SIZE; x++){

                 std::cout <<x+1<<": ";

        for (int y =0; y < BOARD_SIZE ;y++ ){

            std::cout <<this->turnBoard[x][y].getColour();
            std::cout <<"  ";
        }
        std::cout <<"||";
        for (int y =0; y < BOARD_SIZE ;y++ )
        {
            std::cout <<"  ";
            std::cout <<this->pointBoard[x][y].getColour();

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


bool Mosaics::PositionTiles(int row, int number, Colour c){
        //TODO
}
void Mosaics::DisplayMosaics(){
        //TODO

}

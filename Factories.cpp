#include "Factories.h"

Factories::Factories(int noOfPlayers, int seed){

}

// int Factories::takeTile(Colour c, int factories){
//     //TODO
// }

int Factories::setNoOfFactories(int NoOfFactories){
        //TODO
}

void Factories::displayFactories() {
   std::cout << "Factories: " <<std::endl;
       for( int y =0; y < this-> NoOfFactories; y++)
    { 
        if (this->factories[0][y].getColour() != ' ')
        { 
             std::cout <<this-> factories[0][y].getColour()<<" ";
        }    
    }
        for (int x = 1; x < this->NoOfFactories; x++)
    {
        std::cout << x << ": ";
        for (int y = 0; y < NOOFTILES; y++)
        {
            std::cout << this -> factories[x][y].getColour()<<" ";
        }
    }   
}

// bool Factories::StoreColour(Colour c, int factories){
//     //TODO
// }

void Factories::setTileBag(LinkedList* Tilebag){
    //TODO
}

void Factories::addLeftoverTiles(Tiles* tile){
    if(tiles != nullptr && tile->getColour() != CURRENTLYONPLAYERS)
    { this -> BoxLid -> addBack(numTiles);
    }
}

void Factories::removeTiles(){
    factories[0][0] = ' ';
    this-> top = false;
    this-> size -=1;
}

void Factories::setBoxLid(LinkedList* BoxLid){
    //TODO
}
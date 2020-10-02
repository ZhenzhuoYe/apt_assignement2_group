#include "Factory.h"
Factory::Factory(){
    
}

Factory::Factory(int factoryNumber){
    /* 
        if the factory number == 0; the factory is centre factory with first player token
        and shouldn't have any tile before any operation being done

    **/
    
    //TODO
    
    if(factoryNumber == 0){
        this->factoryNumber = factoryNumber;

    }else{
        this->factoryNumber = factoryNumber;
    }
}

Factory::~Factory(){
    // for(Tile s : tiles){
    //     delete s;
    // }
    // delete the tiles array
}


vector<Tile> Factory::clear(){
    std::vector<Tile> returnVector;

    for(int i = 0; i < length; i++){
        returnVector.push_back(tiles[length]);
    }

    length = 0;
    return returnVector;
}

vector<Tile> Factory::takeTile(Color color){
    std::vector<Tile> returnVector;

    for(int i = 0; i < length; i++){
        if(tiles[i].getTileColor() == color){
            returnVector.push_back(tiles[length]);
        }
    }

    return returnVector;
}


void Factory::addingTile(vector<Tile> addTile){
    for(int i = 0; i < 4; i++){
        this->tiles[i] = addTile.at(i);
        length++;
    }
}

std::ostream& operator<<(std::ostream& os, const Factory& fact){
    os<< fact.factoryNumber<<":";
    for(Tile t: fact.tiles){
        os<<char(t.getTileColor())<<" ";
    }

    return os;
}

int Factory::getFactoryNumber(){
    return factoryNumber;
}

bool Factory::ifEmpty(){
    if(length == 0){
        return true;
    }else{
        return false;
    }
}

Tile* Factory::getTiles(){
    return this->tiles;
}

int Factory::getLength(){
    return length;
}

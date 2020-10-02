#include "Factory.h"
Factory::Factory(){
    
}

Factory::Factory(int factoryNumber){
    /* 
        TODO:
        if the factory number == 0; the factory is centre factory with first player token
        and shouldn't have any tile before any operation being done

    **/
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

    for(int i = 0; i < tiles.size(); i++){
        returnVector.push_back(tiles.at(i));
    }

    tiles.clear();
    return returnVector;
}



vector<Tile> Factory::takeTile(Color color){
    std::vector<Tile> returnVector;

    for(int i = 0; i < tiles.size(); i++){
        if(tiles[i].getTileColor() == color){
            //Tile t = tiles[length];
            Tile t(color);
            returnVector.push_back(t);
        }
    }

    return returnVector;
}


void Factory::addingTile(vector<Tile> addTile){
    for(int i = 0; i < addTile.size(); i++){
        tiles.push_back(addTile.at(i));
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
    if(tiles.size() == 0){
        return true;
    }else{
        return false;
    }
}

vector<Tile> Factory::getTiles(){
    return this->tiles;
}

int Factory::getLength(){
    return tiles.size();
}

void Factory::addFirstPlayerToken(){
    Tile t(FIRST_PLAYER);
    tiles.push_back(t);
}
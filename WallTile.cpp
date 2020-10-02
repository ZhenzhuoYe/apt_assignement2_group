#include "WallTile.h"
WallTile::WallTile(){
    
}

WallTile::WallTile(Color color){
    setColor(color);
    wallTaileColor = color;
}

void WallTile::placeTile(){
    placeWithTile = true;
}

bool WallTile::compareWithTile(Tile& tile){
    if(tile.getTileColor() == this->getTileColor()){
        return true;
    }else{
        return false;
    }
}

bool WallTile::getPlaceWithTile(){
    return this->placeWithTile;
}


std::ostream& operator<<(std::ostream& os, const WallTile& wt){
    if(wt.placeWithTile == false){
        os<<".";
        return os;
    }else{
        os<< char(wt.wallTaileColor);
        return os;
    }
}


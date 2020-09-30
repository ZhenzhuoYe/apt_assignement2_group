#include "WallTile.h"
WallTile::WallTile(){
    
}

WallTile::WallTile(Color color){
    setColor(color);
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

#include "Tile.h"

Tile::Tile(){
    
}

Tile::Tile(Color color){
    this->color = color;
}

Color Tile::getTileColor(){
	return this->color;
}

void Tile::setColor(Color color){
    this->color = color;
}
		
std::ostream& operator<<(std::ostream& os, const Tile& tile){
    if(tile.color == RED){
        os<<'R';
    }else if(tile.color == LIGHT_BLUE){
        os<<'L';
    }else if(tile.color == YELLOW){
        os<<'Y';
    }else if(tile.color == DARK_BLUE){
        os<<'B';
    }else if(tile.color == BLACK){
        os<<'U';
    }else if(tile.color == FIRST_PLAYER){
        os<<'F';
    }else if(tile.color == NO_TILE){
        os<<'.';
    }

    return os;
}

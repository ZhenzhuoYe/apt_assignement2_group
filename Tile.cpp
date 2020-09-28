#include "Tile.h"

Tile::Tile(){
    
}

Tile::Tile(Color color){
    this->color = color;
}

Color Tile::getTileColor(){
	return this->color;
}
char* Tile::toString(){
    return enum_to_string(this->getTileColor);
}
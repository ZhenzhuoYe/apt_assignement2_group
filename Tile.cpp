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
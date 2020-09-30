#ifndef AZUL_TILES
#define AZUL_TILES

#include "Type.h"
#include "iostream"

class Tile {
	public:
		Tile();
		Tile(Color color);// constrator to create a tile with color
		//~Tile();

		Color getTileColor();// get color of this tile
		char toString();// convert enum to char for output
		void setColor(Color color);//set the color of tile;

		

	
	private:
		Color color;// color enum cast into char for print
	
	
};

#endif


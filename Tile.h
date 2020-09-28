#ifndef AZUL_TILES
#define AZUL_TILES

#include "Type.h"
#include "iostream"

class Tile {
	public:
		Tile();
		Tile(Color color);
		~Tile();

		Color getTileColor();// get color of this tile
		char* toString();// convert enum to char for output

	
	private:
		Color color;// color enum cast into char for print
	
};

#endif


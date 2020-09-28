#ifndef AZUL_FACTORY
#define AZUL_FACTORY

#include "Tile.h"
#include "Type.h"
#include <vector>
#include <iostream>

using std::vector;

class Factory {
    public:
        Factory();//Constructor

        void addingTile(vector<Tile> addTile);// add tiles from bag

        vector<Tile> clear();//put all tile left into a vector, and clear the factory to empty

        vector<Tile> takeTile(Color color);//take the tile with same color into a vector, and remove that color of tile
        
        //changed here
        friend std::ostream& operator<<(std::ostream& os, const Factory& fact);// operator overloading
        
        Tile* getTiles();//get factory tiles
        //

    
    private:
        int tilesNumber;//current number of tiles in this factory

        Tile* tiles[MAX_FACTORYNUMBER];// array store all tiles
};

#endif
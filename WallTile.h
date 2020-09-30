#include "Tile.h"

class WallTile : public Tile{

    public:
        WallTile();//defult
        WallTile(Color color);
        bool compareWithTile(Tile& tile);// compare the color of the given tile return true if the color is same
        void placeTile();// place a tile on this wall tile, change the value of place with tile to true
    
    private:
        bool placeWithTile = false;// if this wall tile has a tile place on it

};
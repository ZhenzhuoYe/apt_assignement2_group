#ifndef AZUL_GAMEBOARD
#define AZUL_GAMEBOARD

#include "Type.h"
#include "Tile.h"
#include "vector"

typedef Tile Wall[MAX_WALL_COL][MAX_WALL_ROW];
typedef std::vector<Tile> BrokenTile;
typedef Tile PatternLine[MAX_BROKENTILE];

class GameBoard{
    public:
        GameBoard();
        
        void addtoBrokenTile(Tile& tile);//push back to the brokenTile
        void addtoPatternLine(Tile& tile);//1. add to head of the pattern line 2. add to back of the head
        void addtoWall(Tile& tile);//check if the color is the same

        friend std::ostream& operator<<(std::ostream& os, const GameBoard& gameBorard);// operator overloading
        
        //changed here
        Tile* getWall();//get wall array
        Tile getBrokenTile();//get broken tile
        Tile* getPatternLine();//get pattern line
        //

    private:
        Wall wall;
        BrokenTile BrokenTile;
        PatternLine PatternLine;

};
#endif
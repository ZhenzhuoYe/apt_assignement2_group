#ifndef AZUL_GAMEBOARD
#define AZUL_GAMEBOARD

#include "Type.h"
#include "Tile.h"
#include "string"
#include "vector"
#include "WallTile.h"

#define MAX_PATTERNLINE 15


typedef WallTile Wall[MAX_WALL_COL][MAX_WALL_ROW];
typedef std::vector<Tile> BrokenTile;
typedef Tile PatternLine[MAX_PATTERNLINE];




class GameBoard{
    public:
        GameBoard();
        ~GameBoard();
        

        void addtoBrokenTile(Tile tile);//push back to the brokenTile
        
        void addtoPatternLine(std::vector<Tile> tiles, int row);//1. add to head of the pattern line 2. add to back of the head
        
        int addtoWall(std::vector<Tile> tiles, int row);//check if the color is the same return the score

        friend std::ostream& operator<<(std::ostream& os, GameBoard& gameBorard);// operator overloading

        Tile* getPatternLine();

        std::string createSpace(int num);

        std::string getPatternLineByRow(int row);//give a row of patterline, patterline index

        Color getPatternLineRowColor(int row);//get the first color of that row

        std::vector<Tile> getBrokenTile();//get the broken tile

        bool ifPatternLineComplete(int row);//check complete row

        std::vector<Tile> getPatternLineInVector(int row);//return a patterline into vector by row

        void clearRowOfPatterline(int row);//clear the patterline of that ro

        void addFirstPlayerToBrokenTile();//add a first player token to broken


    private:
        Wall wall;
        BrokenTile BrokenTile;
        PatternLine PatternLine;

        int patternLineIndex[6] = {0,1,3,6,10,15};

        



};
#endif
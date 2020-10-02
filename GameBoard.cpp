#include "GameBoard.h"

GameBoard::GameBoard(){
    
    Tile tile =  Tile(NO_TILE);
    //No tile object


    WallTile red = WallTile(RED);
    WallTile yellow =  WallTile(YELLOW);
    WallTile darkBule =  WallTile(DARK_BLUE);
    WallTile lightBule =  WallTile(LIGHT_BLUE);
    WallTile black =  WallTile(BLACK);

    //WallTile test(RED);

    WallTile wallTileInOrder[25] = 
    {
        darkBule, yellow, red, black, lightBule,
        lightBule, darkBule, yellow, red, black,
        black,lightBule, darkBule, yellow, red,
        red,black, lightBule,darkBule, yellow,
        yellow, red, black,lightBule, darkBule
    };
    int wallTileInOrderCount = 0;

    //fill wall with wall tile in order
    for(int x = 0;  x < MAX_WALL_COL; x++){
        for(int y = 0; y < MAX_WALL_ROW; y++){
            wall[x][y] = wallTileInOrder[wallTileInOrderCount];
            wallTileInOrderCount++;
        }
    }

    //fill patternline with tile

    for(int i = 0; i < MAX_PATTERNLINE; i++){
        PatternLine[i] = tile;
    }

    
}

GameBoard::~GameBoard(){
}


void GameBoard::addtoBrokenTile(Tile tile){
    BrokenTile.push_back(tile);
}

void GameBoard::addtoPatternLine(std::vector<Tile> tiles, int row){
    int tilesIndex = 0;
    bool flag = true;

    //loop from the row to next row terminate if vector a have left
    for(int i = patternLineIndex[row]; (i < patternLineIndex[row+1]) && flag; i++){

        //only increment when no tiles exist on that patternline
        if(PatternLine[i].getTileColor() == NO_TILE){
            PatternLine[i] = tiles.at(tilesIndex);
        }
        tilesIndex++;

        if(tilesIndex >= tiles.size()){
            // row is bigger than tiles being pass
            flag = false;
        }
    }

    if(flag){
        //something left in the tiles

        //put everything left in the brokenTile
        for(int i = tilesIndex; i < tiles.size(); i++){
            BrokenTile.push_back(tiles.at(i));
        }
    }
}

Tile* GameBoard::getPatternLine(){
    return this->PatternLine;
}


std::string GameBoard::createSpace(int num){
    std::string s;
    for(int i = 0; i < num; i++){
        s = s + " ";
    }
    return s;
}


std::ostream& operator<<(std::ostream& os, GameBoard& gameBorard){

    for(int printRow = 0; printRow<5; printRow++){
        std::string space = gameBorard.createSpace(5-printRow);
        std::string patterlineTile = gameBorard.getPatternLineByRow(printRow);

        os<<printRow+1<<":"<<space<<patterlineTile<<"||";

        //add wall to the os
        for(int i = 0; i < MAX_WALL_ROW; i++){
            os<<gameBorard.wall[printRow][i];
        }

        os<<std::endl;
    }

    return os;
}

void GameBoard::addtoWall(std::vector<Tile> tiles, int row){
    for(int i = 0; i < MAX_WALL_COL; i++){
        for(Tile s : tiles){
            if(wall[row][i].compareWithTile(s)){
                wall[row][i].placeTile();
            }
        }
    }
}

std::string GameBoard::getPatternLineByRow(int row){
    std::string s;
    
    int rowIndex = patternLineIndex[row];
    int nextRowIndex = patternLineIndex[row+1];

    /*
        everything between the rowindex and nexrowindex is the element that need to be taken
    */
    // for(int i = 0; i < 15; i++){
    //     if(i == rowIndex){
    //         s = s +char(PatternLine[i].getTileColor());
    //         if(i == nextRowIndex){
    //             break;
    //             //TODO fix break

    //         }
    //     }
    // }

    for(int i = rowIndex; i < nextRowIndex; i++){
        s = s +char(PatternLine[i].getTileColor());

    }

    return s;
    //should s be backward?
}

Color GameBoard::getPatternLineRowColor(int row){
    int index = patternLineIndex[row];
    return PatternLine[index].getTileColor();
}


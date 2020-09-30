#include "Bag.h"
Bag::Bag(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<5; j++){
             if(j == 0){
                 tiles.enqueue(Tile(RED));
             }else if(j == 1){
                 tiles.enqueue(Tile(YELLOW));
             }else if(j == 2){
                 tiles.enqueue(Tile(BLACK));
             }else if(j == 3){
                 tiles.enqueue(Tile(DARK_BLUE));
             }else if(j == 4){
                 tiles.enqueue(Tile(LIGHT_BLUE));
             }
        }
    }
}


void Bag::pushLastTile(Tile& tile){
    tiles.enqueue(tile);
}

std::vector<Tile> Bag::popFourTile(){
    std::vector<Tile> returnTiles;

    for(int i = 0 ; i < 4; i++){
        returnTiles.push_back(tiles.getHead());
    }

    return returnTiles;
}

#include "Bag.h"
Bag::Bag(){
    //fill bag with fix size of tile
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

    Node* currentNode = tiles.getHead();

    for(int i = 0; i < tiles.getSize(); i ++){
        order = order + char(currentNode->tile.getTileColor());
        currentNode = currentNode->next;
    }

    delete currentNode;
}


void Bag::pushLastTile(Tile& tile){
    tiles.enqueue(tile);
}

Bag:: ~Bag(){
    //delete tiles;
}
std::vector<Tile> Bag::popFourTile(){
    std::vector<Tile> returnTiles;

    for(int i = 0 ; i < 4; i++){
        returnTiles.push_back(tiles.getHead()->tile);
        tiles.dequeue();
    }

    return returnTiles;
}

std::string Bag::getOrder(){
    return order;
}

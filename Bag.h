#ifndef AZUL_BAG
#define AZUL_BAG


#include "Tile.h"
#include "LinkedList.h"

class Bag{
    public:
        Bag();// constractor Initialise a fix order of linked list, could take seed as parameter
        ~Bag();
        
        Tile* popFirstTile();// take the tile from the head of linked list, and set next tile to be the head
        void pushLastTile();// add the tile to the end of the 
        
        //changed here
        LinkedList& getBag();//get bag linked list
        //

    private:
        LinkedList tiles;//the tile bag
};

#endif
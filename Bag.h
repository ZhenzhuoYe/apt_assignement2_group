#ifndef AZUL_BAG
#define AZUL_BAG

#include "Tile.h"
#include "LinkedList.h"
#include <vector>

class Bag{
    public:
        Bag();// constractor Initialise a fix order of linked list, could take seed as parameter
        ~Bag();//deconstractor for bag
        
        void pushLastTile(Tile& tile);// add the tile to the end of the bag

        std::vector<Tile> popFourTile();// pop first 4 tile to a vector inorder to pass into the factory

    private:
        LinkedList tiles;//the tile bag
};

#endif
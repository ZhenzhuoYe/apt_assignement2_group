#ifndef AZUL_FACTORY
#define AZUL_FACTORY

#include "Tile.h"
#include "Type.h"
#include <vector>
#include <iostream>

using std::vector;

class Factory {
    public:
        Factory();//defult constrctor

        Factory(int factoryNumber);//Constructor factoryNumber ->the number of factory in all factorys

        ~Factory();//deconstructor

        void addingTile(vector<Tile> addTile);// add tiles from bag

        vector<Tile> clear();//put all tile left into a vector, and clear the factory to empty

        vector<Tile> takeTile(Color color);//take the tile with same color into a vector, and remove that color of tile

        int getFactoryNumber();//get the factory number

        friend std::ostream& operator<<(std::ostream& os, const Factory& fact);// operator overloading

        bool ifEmpty();//return true if tiles is empty

        vector<Tile> getTiles();//return array of tiles;

        int getLength();//return the length of tiles;

        void addFirstPlayerToken();// add a first player tokent into the factory;

    
    private:
        int factoryNumber;//the number of factory in all factorys
        //int length;//current number of tiles in this factory

        //Tile tiles[MAX_FACTORY_NUMBER];// array store all tiles
        vector<Tile> tiles;
};

#endif
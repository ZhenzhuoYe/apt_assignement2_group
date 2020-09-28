#ifndef AZUL_ENGINE
#define AZUL_ENGINE

#include "Type.h"
#include "Factory.h"
#include "GameBoard.h"
#include "Bag.h"
#include "Tile.h"
#include"LinkedList.h"
#include"Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include  <io.h>

using std::string;

class Engine{
    public:
       
        Engine();

        void start();
        

        int getInput();

        void getFromFactory(int factory, int row, Color color);
        // get all color from that factory, insert to that row

        void newGame();
        //set up
        //loop till 5 turn

        void saveGame();

        void loadGame();

        void printMainMenu();// print the menu
        void printCredit();// print credit
        
        //changed here
        void saveLinkedListToFile(std::ofstream &file, LinkedList &list);//save linked list to file
        void saveFactoryArrayToFile(std::ofstream &file,Factory *arr);//save array of factories
        void savePlayerToFile(std::ofstream &file,Player &p1,Player &p2);//save player to file
        //

    private:
        int option; 

        //chnaged here
        int roundIndex;//caculate the round
        Bag bag;
        int saveDataIndex = 1;
        Factory* factories;//factory to be stored
        Player p1;
        Player p2;
        //


};

#endif
#ifndef AZUL_ENGINE
#define AZUL_ENGINE

#include "Type.h"
#include "Factory.h"
#include "GameBoard.h"
#include "Tile.h"
#include <iostream>
#include<fstream>
#include <io.h>
#include <string>
#include "Player.h"
#include "Bag.h"

using std::string;

class Engine{
    public:
        Engine();

        void start();
        

        int getInput();
        //get input from user

        void getFromFactory(int factory, int row, Color color);
        // get all color from that factory, insert to that row

        void newGame();
        //set up
        //loop till 5 turn
        void setupNewGame();
        //set up with player name

        void printAllFactory();
        

        void saveGame();

        void loadGame();

        void printMainMenu();// print the menu
        void printCredit();// print credit
        
        void getPlayerInput();//get the input for ingame player


    private:
        int option;

        Player* player1; 
        Player* player2;

        Factory allFactory[MAX_ALL_FACTORY] = {Factory(1), Factory(2), Factory(3), Factory(4),Factory(5), Factory(0)};

        Color chosenColor;// the color player chose to pick
        int chosenFactory;// the factory player chose to pick
        int chosenRow;// the row player picked

        Bag* bag;
        int saveDataIndex = 1;
        std::vector<string> inputRecord;
        bool checkFactoryElement();// return true if all factory is empty
        Color stringToColor(string s);//convert the string to color
        bool checkIfFactoryContainColor();//check if this factory contain this kind of color;
        bool checkInput(Player player);//check the input of a player
    
};

#endif
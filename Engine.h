#ifndef AZUL_ENGINE
#define AZUL_ENGINE

#include "Type.h"
#include "Factory.h"
#include "GameBoard.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Bag.h"

#define MAX_PLAYER 2

using std::string;

class Engine{
    public:
        Engine();

        ~Engine();

        void start();// start the game
        

        int getInput();
        //get input from user

        void newGame();
        //set up
        //loop till 5 turn

        void setupNewGame();
        //set up with player name

        void printAllFactory();
        //print all factory in format
        

        void saveGame();//save game into a file

        void loadGame();//load game from a file

        void printMainMenu();// print the menu

        void printCredit();// print credit
        
        void getPlayerInput();//get the input for ingame player
        /**
         * be able to seperate "save", and "turn"
        */

        void reconstrator(string fileName);
        //use for test mode and load game

        /*
            1. using filename to get file input

            2. tranfer file into input (player name, tile bag, turn order)

            3.player a new game with the order provided in the file
        **/


    private:
        int option;

        Player* player1; //player 1
        Player* player2; //plaeyr 2

        Player* players[MAX_PLAYER];// array of player

        Factory allFactory[MAX_ALL_FACTORY] = {Factory(1), Factory(2), Factory(3), Factory(4),Factory(5), Factory(0)};
        //all factory, 6 index is the center facotory
        
        Factory& centerFactory = allFactory[5];

        Color chosenColor;// the color player chose to pick
        int chosenFactory;// the factory player chose to pick
        int chosenRow;// the row player picked

        Bag* bag;// bag object

        std::vector<string> inputRecord;//store all "turn" input in the vector for saving and loading

        bool checkFactoryElement();// return true if all factory is empty

        bool checkPatterlineFirstCol();//return the state of patterline first col
        Color stringToColor(string s);//convert the string to color
        bool checkInput(Player* player);//check the input of a player

        void putRestIntoCenter();
    
};

#endif
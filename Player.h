#ifndef AZUL_PLAYER
#define AZUL_PLAYER

#include "GameBoard.h"
#include <string>

using std::string;

class Player{
    public: 
        //diff here:add a default constructor
        Player(); //default constructor
        //
        Player(string name);

        
        string getPlayerName();// get this player name
        int getScore();//get player score
        GameBoard getGameBoard();// get the gameboard of this player

    private:
        int score;
        string playerName;
        GameBoard gameBoard;

};

#endif
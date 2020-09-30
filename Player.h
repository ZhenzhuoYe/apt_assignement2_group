#ifndef AZUL_PLAYER
#define AZUL_PLAYER

#include "GameBoard.h"
#include <string>

using std::string;

class Player{
    public: 
        Player(string name);
        
        string getPlayerName();// get this player name
        GameBoard getGameBoard();// get the gameboard of this player
        void setScore(int score);//set the score of the player

    private:
        int score;
        string playerName;
        GameBoard gameBoard;

};

#endif
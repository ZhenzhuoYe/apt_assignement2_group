#include "Player.h"

Player::Player(string playerName){
    this->playerName = playerName;
    //this->gameBoard = gameBoard;
}

string Player::getPlayerName(){
    return this->playerName;
}

GameBoard Player::getGameBoard(){
    return this->gameBoard;
}

void Player::setScore(int score){
    this->score = score;
}

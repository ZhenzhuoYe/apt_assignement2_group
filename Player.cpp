#include "Player.h"

Player::Player(string playerName, GameBoard* gameboard){
    this->playerName = playerName;
    this->gameBoard = gameboard;
}

string Player::getPlayerName(){
    return this->playerName;
}

GameBoard* Player::getGameBoard(){
    return this->gameBoard;
}

void Player::increaseScore(int score){
    this->score = this->score + score;
}

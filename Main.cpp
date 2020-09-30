#include "Engine.h"

int main(){

    Engine* game = new Engine();
    game->start();

    delete game;
    return EXIT_SUCCESS;
}
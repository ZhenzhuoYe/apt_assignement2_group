#include "Engine.h"

int main(int argc, char** argv){

    Engine* game = new Engine();
    game->start();

    delete game;
    return EXIT_SUCCESS;
}
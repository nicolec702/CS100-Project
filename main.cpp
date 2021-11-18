#include <iostream>
#include "CharacterSelection/CharacterSelection.hpp"
#include "CharacterSelection/game.hpp"


int main(int argc, char* argv[])
{
    Game* gameClient = new Game();
    gameClient -> newGame();   
    return 0;
}

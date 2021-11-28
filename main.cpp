#include <iostream>
#include "CharacterSelection/CharacterSelection.hpp"
#include "CharacterSelection/game1.hpp"


int main(int argc, char* argv[])
{
    newGame* gameClient = new newGame();
    gameClient -> CharacterScreen();   
    return 0;
}

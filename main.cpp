#if _WIN32
#include "CharacterSelection/WinGame.hpp"

#elif __linux__
#include "CharacterSelection/UnixGame.hpp"

#elif __APPLE__
#include "CharacterSelection/UnixGame.hpp"

#endif

#include <iostream>

int main(int argc, char* argv[])
{
    #if _WIN32
        WinGame* gameClient = new WinGame();
        gameClient -> CharacterScreen();

    #elif __linux__
        UnixGame* gameClient = new UnixGame();
        gameClient -> CharacterScreen();  

    #elif __APPLE__
        UnixGame* gameClient = new UnixGame()
        gameClient -> CharacterScreen();

    #endif
    return 0;
}

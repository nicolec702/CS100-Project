#if _WIN32
#include "WinGame.hpp"
#elif
#include "UnixGame.hpp"
#endif

#include <iomanip>




int main(int argc, char* argv[]){
       std::cout << std::fixed << std::showpoint << std::setprecision(2);
       newGame* GameClient = new newGame();
       GameClient->playerSelection();
       GameClient->tutorial();
       GameClient->scene1();
       return 0;
}
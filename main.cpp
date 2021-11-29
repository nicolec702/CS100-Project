#include "game.hpp"
#include <iomanip>

int main(int argc, char* argv[]){
       std::cout << std::fixed << std::showpoint << std::setprecision(2);
       Game *newGame = new Game();
       newGame->playerSelection();
       newGame->tutorial();
       newGame->scene1();
}

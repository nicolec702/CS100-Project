#include "game.hpp"
#include <iomanip>

int main(int argc, char* argv[]){
       std::cout << std::fixed << std::showpoint << std::setprecision(2);
       Game *newGame = new Game();
       if(newGame->mainMenu())
       {
              newGame->playerSelection();
              //newGame->tutorial();
              //newGame->scene1();
	      //newGame->scene2();

             NPAttackCharacter *girl= new NPAttackCharacter(1, "girl", 2, 1);
             for(int i=0; i<3; i++)
             {
                    newGame->ArtBattleScene(girl);
                    girl->resetValues();
                    girl->fullHealth();
             }
       }
}

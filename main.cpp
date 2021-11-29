#include "game.hpp"
#include <iomanip>

int main(int argc, char* argv[]){
       std::cout << std::fixed << std::showpoint << std::setprecision(2);
       Game *newGame = new Game();
       newGame->playerSelection();
       NPAttackCharacter* npc = new NPAttackCharacter();
       npc->setName("NPC");
       npc->setCharacterType(4);
       npc->setWeaponType(4);
       newGame->BatlleScene(npc);
}

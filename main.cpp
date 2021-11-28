#include "game.hpp"

int main(int argc, char* argv[]){
       Game *newGame = new Game();
       newGame->playerSelection();
       NPAttackCharacter* npc = new NPAttackCharacter();
       npc->setName("NPC");
       npc->setCharacterType(4);
       npc->setWeaponType(4);
       newGame->BatlleScene(npc);
}

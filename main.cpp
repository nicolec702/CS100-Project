#include "WeaponsFiles/weapons.hpp"
#include "WeaponsFiles/weaponBehavior.hpp"
#include "WeaponsFiles/longSword.hpp"
#include "WeaponsFiles/dagger.hpp"
#include "WeaponsFiles/staff.hpp"
#include "WeaponsFiles/broom.hpp"
#include "CharacterFiles/attribute.hpp"
#include "CharacterFiles/attributeBehavior.hpp"
#include "CharacterFiles/wizard.hpp"
#include "CharacterFiles/rogue.hpp"
#include "CharacterFiles/bob.hpp"
#include "CharacterFiles/knight.hpp"
#include "CharacterFiles/attackCharacter.hpp"
#include "CharacterFiles/character.hpp"
#include "CharacterFiles/playableCharacter.hpp"
#include "CharacterFiles/npAttackCharacter.hpp"
#include "game.hpp"


#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]){
       Game *newGame = new Game();
       newGame->playerSelection();
       NPAttackCharacter* npc = new NPAttackCharacter();
       npc->setName("NPC");
       npc->setCharacterType(4);
       npc->setWeaponType(4);
       newGame->BatlleScene(npc);
}

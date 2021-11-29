#ifndef __GAME_HPP__
#define __GAME_HPP__

#ifdef __unix__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#elif _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#elif __APPLE__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#endif

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
#include <fstream>

class Game{
private:
    PlayableCharacter *player;
public:
    Game(){}

    void playerSelection();
    void BatlleScene(NPAttackCharacter* npc);
    void tutorial();
    void scene1();

    //----------
    void cls(){ std::cout << "\033[2J\033[1;1H"; }
};
#endif

#include "../helperFunction.cpp"
#include "../WeaponsFiles/weapons.cpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/broom.hpp"
#include "../CharacterFiles/attribute.cpp"
#include "../CharacterFiles/attributeBehavior.hpp"
#include "../CharacterFiles/wizard.hpp"
#include "../CharacterFiles/rogue.hpp"
#include "../CharacterFiles/bob.hpp"
#include "../CharacterFiles/knight.hpp"
#include "../CharacterFiles/attackCharacter.hpp"
#include "../CharacterFiles/character.hpp"
#include "../CharacterFiles/playableCharacter.hpp"
#include "../CharacterFiles/npAttackCharacter.hpp"
#include "../gtest/gtest.h"

TEST(HelperFunctions, verifyIntInputTRUE){
    EXPECT_EQ(verifyIntInput("1"), 1);
}

TEST(HelperFunctions, verifyIntInputFALSE){
    EXPECT_EQ(verifyIntInput("hello"), -1);
}
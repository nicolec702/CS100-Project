#include "../BaseGameFiles/helperFunction.cpp"
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
#include "gtest/gtest.h"

TEST(Attribute, VerifyRogueAttack)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getAttackStat(), 16.50);
    delete model;
}

TEST(Attribute, VerifyRogueHP)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getHpStat(), 16.00);
    delete model;
}

TEST(Attribute, VerifyRogueDef)
{
    Attribute *model = new Attribute();
    model->setBehavior(new Rogue());
    model->setStats();

    EXPECT_EQ(model->getDefenseStat(), 12.50);
    delete model;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
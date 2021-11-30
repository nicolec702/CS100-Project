
#include "../BaseGameFiles/helperFunction.cpp"
#include "../CharacterFiles/attackCharacter.hpp"
#include "../CharacterFiles/character.hpp"
#include "../CharacterFiles/playableCharacter.hpp"
#include "../CharacterFiles/npAttackCharacter.hpp"
#include "gtest/gtest.h"

TEST(PlayableCharacter, verifyName){
    
    PlayableCharacter *player = new PlayableCharacter();
    player->setPlayerName("Player 1")
    EXPECT_EQ(player->getPlayerName(), "Player 1");
    delete player;
}
TEST(PlayableCharacter, verifyAttackKnight){
    
    PlayableCharacter *player = new PlayableCharacter();
    player->setPlayerName("Knight")
    player->setCharacterType (2);
    EXPECT_EQ(player->getAttack(), 15);
    delete player;
}

TEST(PlayableCharacter, verifyNameChange){
    
    PlayableCharacter *player = new PlayableCharacter();
    player->setPlayerName("Player 1")
    player->setPlayerName ("Hello");
    EXPECT_EQ(player->getPlayerName(), "Hello");
    delete player;
}

TEST(Character, verifyName){
    Character *character = new Character();
    character->setName("Narrator");
    EXPECT_EQ(character->getName(), "Narrator");
    delete character;
}

TEST(Character, verifyNameChange){
    Character *character = new Character();
    character->setName("Narrator");
    EXPECT_EQ(character->getName(), "Narrator");
    delete character;
}

TEST(NPAttackCharacter, verifyAttackWizard)
{
    NPAttackCharacter *wizard = new NPAttackCharacter(1,"Wizard",1,1);
    EXPECT_EQ(wizard->getAttack(), 15);
    delete wizard;
}

TEST(NPAttackCharacter, verifyDefkWizard)
{
    NPAttackCharacter *wizard = new NPAttackCharacter(1,"Wizard",1,1);
    EXPECT_EQ(wizard->getDefense(), 11);
    delete wizard;
}

TEST(NPAttackCharacter, verifyHPkWizard)
{
    NPAttackCharacter *wizard = new NPAttackCharacter(1,"Wizard",1,1);
    EXPECT_EQ(wizard->getHp(), 15);
    delete wizard;
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
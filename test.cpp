#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include "longSword.hpp"
#include "staff.hpp"
#include "dagger.hpp"
#include "broom.hpp"

#include "gtest/gtest.h"

TEST(LongSword, NormalAttack){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->attack(1);
	EXPECT_TRUE((dmg <= 8) && (dmg >= 5));
	delete sword;
}

TEST(LongSword, SpecialAttack){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->specialAttack(1);
	EXPECT_TRUE((dmg <= 12) && (dmg >= 7.5));
	delete sword;
}

TEST(LongSword, SpecialMove){
	WeaponBehavior* sword = new LongSword();
	double dmg = sword->specialMove(1);
	EXPECT_TRUE((dmg <= 16) && (dmg >= 10));
	delete sword;
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

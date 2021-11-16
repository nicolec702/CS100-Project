#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include <iostream>

Weapons::~Weapons()
{
	delete behavior;
}

void Weapons::setBehavior(WeaponBehavior* newBehavior)
{
	delete behavior;
	behavior = newBehavior;
}

double Weapons::attack(int playerLvl)
{
	double dmg = behavior->attack(playerLvl);
	std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}

double Weapons::specialAttack(int playerLvl)
{
	double dmg = behavior->specialAttack(playerLvl);
	std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}

double Weapons::specialMove(int playerLvl)
{
	double dmg = behavior->specialMove(playerLvl);
	std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}



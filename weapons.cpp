#include "weapons.hpp"

Weapons::~Weapons()
{
	delete weaponBehavior;
}

void Weapons::setBehavior(WeaponBehavior* newBehavior)
{
	delete weaponBehavior;
	weaponBehavior = newBehavior;
}

void Weapons::attack()
{
	//TODO
}

void Weapons::specialAttack()
{
	//TODO
}

void Weapons::defense()
{
	//TODO
}

void Weapons::specialMove()
{
	//TODO
}



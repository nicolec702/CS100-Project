#include "weapons.hpp"

Weapons::~Weapons()
{
	delete behavior;
}

void Weapons::setBehavior(WeaponBehavior* newBehavior)
{
	delete behavior;
	behavior = newBehavior;
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



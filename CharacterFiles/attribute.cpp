#include "attribute.hpp"
#include "attributeBehavior.hpp"
#include <iostream>

Attribute::~Attribute() { delete behavior; }

void Attribute::deleteAttribute(){ delete behavior; }

void Attribute::setBehavior(AttributeBehavior* newBehavior)
{
	delete behavior;
	behavior = newBehavior;
}

void Attribute::setStats()
{
	this->defenseStat = behavior->defense(playerLvl);
	this->staminaStat = behavior->stamina(playerLvl);
	this->hpStat = behavior->health_points(playerLvl);
	this->attackStat = behavior->attack(playerLvl);

}

void Attribute::updatedLevel(int newLevel)
{
    this->playerLvl=newLevel;
    setStats();
}



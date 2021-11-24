#ifndef __WEAPONS_HPP__
#define __WEAPONS_HPP__
#include <string>
#include "weaponBehavior.hpp"

class WeaponBehavior;

class Weapons{
	private:
		std::string name;
		WeaponBehavior* behavior = nullptr;
	public:
		//constructors
		Weapons(){}
		Weapons(std::string name):name(name){}
		//destructor
		~Weapons();

		void setBehavior(WeaponBehavior* newBehavior);
		std::string getName(){ return name; }
		
		double attack(int playerLvl);
		double specialAttack(int playerLvl);
		double specialMove(int playerLvl);
};
#endif

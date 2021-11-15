#ifndef __WEAPONS_HPP__
#define __WEAPONS_HPP__
#include <string>

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
		
		void attack();
		void specialAttack();
		void defense();
		void specialMove();
};
#endif

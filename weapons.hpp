#ifndef __WEAPONS_HPP__
#define __WEAPONS_HPP__

class WeaponBehavior

class Weapons{
	private:
		string name;
		WeaponBehavior* behavior = nullptr;
	public:
		//constructors
		Weapons(){}
		Weapons(string name):name(name){}
		//destructor
		~Weapons();

		void setBehavior(WeaponBehavior* newBehavior);
		
		void attack();
		void specialAttack();
		void defense();
		void specialMove();
};


#ifndef __ATTRIBUTE_HPP__
#define __ATTRIBUTE_HPP__
#include "attributeBehavior.hpp"
#include "../WeaponsFiles/weapons.hpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/broom.hpp"
#include "../WeaponsFiles/basicWeapon.hpp"

class AttributeBehavior;

class Attribute{
	private:
		AttributeBehavior* behavior = nullptr;
		double defenseStat;
		double staminaStat;
		double attackStat;
		double hpStat;
		int playerLvl=1;

	public:
		//constructors
		Attribute(){}
		~Attribute();
        void deleteAttribute();
		void setBehavior(AttributeBehavior* newBehavior);
		void updatedLevel(int newLevel);
		void setStats();

		double getDefenseStat(){ return this->defenseStat;}
		double getStatminaStat() {return this->staminaStat;}
		double getHpStat(){ return this->hpStat;}
		double getAttackStat(){ return this->attackStat;}
		
};
#endif
#ifndef __ATTRIBUTE_HPP__
#define __ATTRIBUTE_HPP__
#include "attributeBehavior.hpp"
#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include "longSword.hpp"
#include "dagger.hpp"
#include "staff.hpp"
#include "broom.hpp"
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
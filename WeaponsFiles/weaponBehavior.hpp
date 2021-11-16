#ifndef __WEAPONBEHAVIOR_HPP__
#define __WEAPONBEHAVIOR_HPP__

class WeaponBehavior
{
	public:
		virtual ~WeaponBehavior() = default;
		virtual double attack(int playerLvl) = 0;
		virtual double specialAttack(int playerLvl) = 0;
		virtual double specialMove(int playerLvl) = 0;

};

#endif

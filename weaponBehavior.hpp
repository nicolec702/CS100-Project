#ifndef __WEAPONBEHAVIOR_HPP__
#define __WEAPONBEHAVIOR_HPP__

class WeaponBehavior
{
	public:
		virtual ~WeaponBehavior() = default;
		virtual double attack(int playerLvl);
		virtual double specialAttack(int playerLvl);
		virtual double specialMove(int playerLvl);

};

#endif

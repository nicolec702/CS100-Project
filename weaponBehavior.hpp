#ifndef __WEAPONBEHAVIOR_HPP__
#define __WEAPONBEHAVIOR_HPP__

class WeaponBehavior
{
	public:
		virtual ~WeaponBehavior() = default;
		virtual void attack();
		virtual void specialAttack();
		virtual void defense();
		virtual void specialMove();

};

#ifndef __ATTRIBUTEBEHAVIOR_HPP__
#define __ATTRIBUTEBEHAVIOR_HPP__

class AttributeBehavior
{
	public:
		virtual ~AttributeBehavior() = default;
		virtual double defense(int playerLvl) = 0;
		virtual double stamina(int playerLvl) = 0;
		virtual double health_points(int playerLvl) = 0;
		virtual double attack(int playerLvl) = 0;

};

#endif
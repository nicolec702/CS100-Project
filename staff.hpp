#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>

class Staff : public WeaponBehavior 
{
    private:
        //min dmg weapon deals
        int minDmg = 3;
        //max dmg weapon deals
        int maxDmg = 6;
        //scale dmg based on player lvl
        double scale = 3;

    public:
        //constructor
        Staff() { srand(time(0)); }

        /*
            Normal Attack:
                deals normal damage
        */
        virtual double attack(int playerLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage
            damage += playerLvl * scale;
            //return damage
            return damage;
        }

        virtual double specialAttack(int playerLvl)
        {
            //TODO
        }

        virtual double defense(int playerLvl)
        {
            //TODO (inside character class maybe?)
        }

        virtual double specialMove(int playerLvl)
        {
            //TODO
        }

};
#endif
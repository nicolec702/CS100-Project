#ifndef __LONGSWORD_HPP__
#define __LONGSWORD_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>


class LongSword : public WeaponBehavior 
{
    private:
        //min dmg weapon deals
        int minDmg = 5;
        //max dmg weapon deals
        int maxDmg = 8;
        //scale dmg based on player lvl
        double scale = 3;
        
    public: 
        //constructor
        LongSword(){ srand(time(0)); }

        /*
            Normal Attack: Stab
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

        /*  
            Special Attack: Slash
                deals 1.5x damage
        */
	    virtual double specialAttack(int playerLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += playerLvl * scale;
            //x1.5 damage bc of special attack
            damage *= 1.5;
            //return damage
            return damage;
        }

        /*
            Special Move: Mighty Steed
                deals 2x damage
        */
	    virtual double specialMove(int playerLvl, double dmgTaken)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += playerLvl * scale;
            //x2 damage bc of special move
            damage *= 2;
            //return damage
            return damage;
        }

};
#endif
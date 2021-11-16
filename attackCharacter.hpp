#ifndef __ATTACK_CHARACTER_HPP__
#define __ATTACK_CHARACTER_HPP__

#include "attribute.hpp"
#include "character.hpp"
#include <iostream>

class AttackChacracter: public Character {
    private:
        Attribute attribute;
        int level, exp, nextLvl;
    public:
        AttackChacracter() {}
        AttackChacracter(Attribute attribute) { 
            this->attribute = attribute;
            this->exp=0;
            this->nextLvl=10;
            this->level=1;
        }
        void takeDamage( double damage) { attribute.setHp(attribute.getHp() - damage); }

        void printVitals()
        {
            std::cout<<"Vitals: "<<std::endl;
            std::cout<<"Level: "<<level<<std::endl;
            std::cout<< "HP: "<<attribute.getHp()<<std::endl;
            std::cout<< "Defense: "<<attribute.getDefense()<<std::endl;
            std::cout<< "Attack: "<<attribute.getAttack()<<std::endl;
            std::cout<< "Stamina: "<<attribute.getStamina()<<std::endl;
        }
        void increaseEXP(int increase)
        {
            exp+=increase;
            if( exp > nextLvl)
            {
                exp -=nextLvl;
                level++;
                attribute.setHp(attribute.getHp()*2);
                attribute.setDefense(attribute.getDefense()*2);
                attribute.setAttack(attribute.getAttack()*2);
                attribute.setStamina(attribute.getStamina() * 2);

                std::cout<<name<<" is now level "<<level<<std::endl;
                printVitals();
            }
        }

};

#endif 
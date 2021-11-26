#ifndef __ATTACK_CHARACTER_HPP__
#define __ATTACK_CHARACTER_HPP__

#include "attribute.hpp"
#include "attributeBehavior.hpp"
#include "character.hpp"
#include "wizard.hpp"
#include "rogue.hpp"
#include "bob.hpp"
#include "knight.hpp"
#include <string>
#include <iostream>

class AttackCharacter: public Character {
    protected:
        Attribute model;
        Weapons weapon;
        double hp, defense, attack, stamina, damageGiven;
        double staminaSpecialAttack = 3, staminaSpecialMove=5;
    public:
        ~AttackCharacter(){}
        AttackCharacter(){}
        virtual void selectMove() {}
	
        double getHp(){return hp;}
        double getDamagaGiven() {return damageGiven;}

        void resetValues()
        {
            defense = model.getDefenseStat();
            hp = model.getHpStat();
            attack = model.getAttackStat();
            stamina = model.getStatminaStat();
            damageGiven = 0;
        }

        bool takeDamage(double damage)
        {
            bool defeated = false;
            if(damage > 0){
	            if(damage-defense<2) damage = 2; 
                else damage=damage-defense;    

                hp-=damage;
                if(hp <= 0){
                    std::cout<<getName()<< " HAS BEEN DEFEATED"<<std::endl;
                    defeated = true; hp = 0;
                }
                std::cout<<getName()<<"'S HP IS NOW "<< hp << std::endl;
            }
            return defeated;
            
	
        } 

    bool increaseDefense()
    {
        damageGiven = 0;
        if(defense != model.getDefenseStat() * 2) {
            defense = defense + (model.getDefenseStat() / 4);
            std::cout<<"DEFENSE HAS INCREASED!\n";
            return true;
        }
        else {
            std::cout<<"DEFENSE ALREADY AT CAP. CHOOSE DIFFERENT MOVE: ";
            return false;
        }
    }

    void normalAttack() { damageGiven = weapon.attack(attack/10); }

    void specialAttack()
    {
        if(stamina >= staminaSpecialAttack){
            stamina -= staminaSpecialAttack;
            damageGiven = weapon.specialAttack(attack/10);
        }
        else{
            std::cout<<getName()<< "'S SPECIAL ATTACK FAILED. "<<std::endl;
            damageGiven = 0;
        }
    }

    void specialMove()
    {
        if(stamina > staminaSpecialMove){
            stamina -= staminaSpecialAttack;
            damageGiven = weapon.specialMove(attack/10); 
        }
        else{
            std::cout<<getName()<<"'S SPECIAL MOVE FAILED"<<std::endl;
            damageGiven = 0;
        }
    }
    /////////////
    void printVitals()
    {
        std::cout<<"\nName: "<<getName()<<std::endl;
        std::cout<<"Attack: "<<model.getAttackStat()<<std::endl;
        std::cout<<"Defense: "<<model.getDefenseStat()<<std::endl;
        std::cout<<"Stamina: "<<model.getStatminaStat()<<std::endl;
        std::cout<<"HP: "<<model.getHpStat()<<std::endl;
    }
        
	void currentStats()
    {
        std::cout<<"\nName: "<<getName()<<std::endl;
        std::cout<<"Attack: "<<attack<<std::endl;
        std::cout<<"Defense: "<<defense<<std::endl;
        std::cout<<"Stamina: "<<stamina<<std::endl;
        std::cout<<"HP: "<<hp<<std::endl;
    }

};

#endif
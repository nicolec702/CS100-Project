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
        double hp, defense, attack, mana, damageGiven;
        double manaSpecialAttack = 3, manaSpecialMove=5;
    public:
        ~AttackCharacter(){}
        AttackCharacter(){}
        virtual void selectMove() {}
	
        double getHp() const {return hp;}
        double getDefense() const {return defense;}
        double getAttack() const {return attack;}
        double getMana() const {return mana; }
        double getDamagaGiven() const {return damageGiven;}


        void setCharacterType(int characterClass)
        {
            switch(characterClass){
            case 1: model.setBehavior(new Wizard()); break; // Wizard model
            case 2: model.setBehavior(new Knight()); break; // Knight model
            case 3: model.setBehavior(new Rogue()); break; // Rogue model
            case 4: model.setBehavior(new Bob()); break; // Bob model
            default: break;
            }
            model.setStats(); 
            damageGiven = 0;
            hp = model.getHpStat(); defense = model.getDefenseStat();
            attack = model.getAttackStat(); mana = model.getManaStat();
        }

        void setWeaponType(int weaponClass)
        {
            switch (weaponClass){
            case 1: weapon.setBehavior(new Staff()); break; // staff model 
            case 2: weapon.setBehavior(new LongSword()); break; // longsword model
            case 3: weapon.setBehavior(new Dagger()); break; // dagger model
            case 4: weapon.setBehavior(new Broom()); break; // broom model
            default: break;
            }
        }

        void resetValues()
        {
            defense = model.getDefenseStat();
            hp = model.getHpStat();
            attack = model.getAttackStat();
            mana = model.getManaStat();
            damageGiven = 0;
        }

        bool takeDamage(double damage)
        {
            bool defeated = false;
            if(damage > 0){
	            if(damage-(defense/2)<2) damage = 2; 
                else damage=damage-(defense/2);    
                hp-=damage;
                if(hp <= 0){
                    std::cout<<getName()<< " HAS BEEN DEFEATED"<<std::endl;
                    defeated = true; hp = 0;
                }
                std::cout<< getName()<<"'s hp is not "<< hp << std::endl;
            }
            return defeated;
            
	
        } 

        bool increaseDefense()
        {
            damageGiven = 0;
            if(defense != model.getDefenseStat() * 2) {
                defense = defense + (model.getDefenseStat() / 4);
                std::cout<< "\n" << getName()<<" decides to defend!\nDefense has increased!"<<std::endl;
                return true;
            }
            else {
                std::cout<<"\n"<<"Defense already at cap. Choose different move."<<std::endl;
                return false;
        }
        }

        void normalAttack() { 
            damageGiven = weapon.attack(attack/10); 
            std::cout<<"\n"<<getName() << " decides to attack!"<<std::endl;
        }

        bool specialAttack()
        {
            if(mana >= manaSpecialAttack){
                mana -= manaSpecialAttack;
                damageGiven = weapon.specialAttack(attack/10);
                std::cout<<"\n"<<getName()<< " uses SPECIAL ATTACK!"<<std::endl;
                return true;
            }
            else{
                std::cout<<"\n"<<getName()<< "'s special attack failed. Try different move."<<std::endl;
                return false;
            }
        }

        bool specialMove()
        {
            if(mana > manaSpecialMove){
                mana -= manaSpecialAttack;
                damageGiven = weapon.specialMove(attack/10); 
                std::cout<<"\n"<<getName()<< " uses SPECIAL MOVE!"<<std::endl;
                return true;
            }
            else{
                std::cout<<"\n"<<getName()<<"'s special move failed. Try different move."<<std::endl;
                return false;
            }
        }
    /////////////
        void printVitals()
        {
            std::cout<<"\nName: "<<getName()<<std::endl;
            std::cout<<"Attack: "<<model.getAttackStat()<<std::endl;
            std::cout<<"Defense: "<<model.getDefenseStat()<<std::endl;
            std::cout<<"Mana: "<<model.getManaStat()<<std::endl;
            std::cout<<"HP: "<<model.getHpStat()<<std::endl;
        }
        
	    void currentStats()
        {
            std::cout<<"\nName: "<<getName()<<std::endl;
            std::cout<<"Attack: "<<attack<<std::endl;
            std::cout<<"Defense: "<<defense<<std::endl;
            std::cout<<"Mana: "<<mana<<std::endl;
            std::cout<<"HP: "<<hp<<std::endl;
        }

};

#endif